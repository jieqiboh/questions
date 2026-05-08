// message_dispatcher.cpp
// Benchmarks: std::visit vs virtual dispatch vs manual vtable
// Compile: g++ -O2 -std=c++20 -o dispatcher message_dispatcher.cpp

#include <variant>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <memory>
#include <random>
#include <array>

// ============================================================
// 1. MESSAGE TYPES
// ============================================================

struct NewOrder {
    uint64_t order_id;
    double   price;
    int      qty;
    char     side; // 'B' or 'S'
};

struct Cancel {
    uint64_t order_id;
};

struct Modify {
    uint64_t order_id;
    double   new_price;
    int      new_qty;
};

using Message = std::variant<NewOrder, Cancel, Modify>;

// ============================================================
// 2. OVERLOAD PATTERN  (the idiomatic std::visit helper)
// ============================================================
//
// Derives from every callable you hand it, inheriting all their
// operator()s. The compiler merges them into a single overload set.
//
template<typename... Ts>
struct overload : Ts... {
    using Ts::operator()...;   // C++17 pack expansion of using-decls
};
// CTAD (C++17): lets you write overload{f, g} without spelling out types explicitly
template<typename... Ts> overload(Ts...) -> overload<Ts...>;


// ============================================================
// 3. HANDLER USING std::visit + overload
// ============================================================

// Accumulator so the compiler can't optimise the whole loop away
static volatile int64_t g_sink = 0;

void handle_visit(const Message& msg) {
    std::visit(overload{
        [](const NewOrder& o) {
            g_sink += o.order_id + static_cast<int64_t>(o.price) + o.qty;
        },
        [](const Cancel& c) {
            g_sink -= static_cast<int64_t>(c.order_id);
        },
        [](const Modify& m) {
            g_sink += static_cast<int64_t>(m.order_id) + static_cast<int64_t>(m.new_price);
        },
    }, msg);
}


// ============================================================
// 4. VIRTUAL DISPATCH
// ============================================================

struct IMessage {
    virtual ~IMessage() = default;
    virtual void handle() const = 0;
};

struct VNewOrder : IMessage {
    uint64_t order_id; double price; int qty;
    VNewOrder(uint64_t id, double p, int q) : order_id(id), price(p), qty(q) {}
    void handle() const override {
        g_sink += order_id + static_cast<int64_t>(price) + qty;
    }
};

struct VCancel : IMessage {
    uint64_t order_id;
    explicit VCancel(uint64_t id) : order_id(id) {}
    void handle() const override { g_sink -= static_cast<int64_t>(order_id); }
};

struct VModify : IMessage {
    uint64_t order_id; double new_price;
    VModify(uint64_t id, double p) : order_id(id), new_price(p) {}
    void handle() const override {
        g_sink += static_cast<int64_t>(order_id) + static_cast<int64_t>(new_price);
    }
};


// ============================================================
// 5. HAND-ROLLED VTABLE
// ============================================================
//
// A vtable is just an array of function pointers.
// Virtual dispatch does:
//   1. Load vptr from object   (indirect memory read)
//   2. Index into vtable       (pointer arithmetic)
//   3. Call through fn pointer (indirect branch)
//
// We replicate that explicitly.

enum class MsgKind : uint8_t { NewOrder, Cancel, Modify };

// A tagged-union "fat pointer" approach: store the kind + a void*
struct RawMessage {
    MsgKind kind;
    union {
        NewOrder new_order;
        Cancel   cancel;
        Modify   modify;
    } data;
};

// The vtable: one function pointer per message kind
using HandlerFn = void(*)(const RawMessage&);

void handle_new_order_raw(const RawMessage& m) {
    const auto& o = m.data.new_order;
    g_sink += o.order_id + static_cast<int64_t>(o.price) + o.qty;
}
void handle_cancel_raw(const RawMessage& m) {
    g_sink -= static_cast<int64_t>(m.data.cancel.order_id);
}
void handle_modify_raw(const RawMessage& m) {
    const auto& mo = m.data.modify;
    g_sink += static_cast<int64_t>(mo.order_id) + static_cast<int64_t>(mo.new_price);
}

// The vtable itself: indexed by MsgKind
constexpr std::array<HandlerFn, 3> g_vtable = {
    handle_new_order_raw,
    handle_cancel_raw,
    handle_modify_raw,
};

void handle_vtable(const RawMessage& msg) {
    g_vtable[static_cast<size_t>(msg.kind)](msg);
}


// ============================================================
// 6. BENCHMARK HARNESS
// ============================================================

constexpr size_t N = 5'000'000;

using Clock = std::chrono::steady_clock;

double bench_visit(const std::vector<Message>& msgs) {
    auto t0 = Clock::now();
    for (const auto& m : msgs) handle_visit(m);
    auto t1 = Clock::now();
    return std::chrono::duration<double, std::milli>(t1 - t0).count();
}

double bench_virtual(const std::vector<std::unique_ptr<IMessage>>& msgs) {
    auto t0 = Clock::now();
    for (const auto& m : msgs) m->handle();
    auto t1 = Clock::now();
    return std::chrono::duration<double, std::milli>(t1 - t0).count();
}

double bench_vtable(const std::vector<RawMessage>& msgs) {
    auto t0 = Clock::now();
    for (const auto& m : msgs) handle_vtable(m);
    auto t1 = Clock::now();
    return std::chrono::duration<double, std::milli>(t1 - t0).count();
}


// ============================================================
// 7. DATASET GENERATION
// ============================================================

int main() {
    std::mt19937_64 rng(42);
    std::uniform_int_distribution<int> kind_dist(0, 2);

    // --- variant messages ---
    std::vector<Message> var_msgs;
    var_msgs.reserve(N);

    // --- virtual messages ---
    std::vector<std::unique_ptr<IMessage>> virt_msgs;
    virt_msgs.reserve(N);

    // --- raw vtable messages ---
    std::vector<RawMessage> raw_msgs;
    raw_msgs.reserve(N);

    for (size_t i = 0; i < N; ++i) {
        int k = kind_dist(rng);
        uint64_t id = rng();
        double price = static_cast<double>(rng() % 100000) / 100.0;
        int qty = static_cast<int>(rng() % 1000) + 1;

        switch (k) {
        case 0:
            var_msgs.emplace_back(NewOrder{id, price, qty, 'B'});
            virt_msgs.push_back(std::make_unique<VNewOrder>(id, price, qty));
            raw_msgs.push_back(RawMessage{MsgKind::NewOrder, {.new_order = {id, price, qty, 'B'}}});
            break;
        case 1:
            var_msgs.emplace_back(Cancel{id});
            virt_msgs.push_back(std::make_unique<VCancel>(id));
            raw_msgs.push_back(RawMessage{MsgKind::Cancel, {.cancel = {id}}});
            break;
        case 2:
            var_msgs.emplace_back(Modify{id, price, qty});
            virt_msgs.push_back(std::make_unique<VModify>(id, price));
            raw_msgs.push_back(RawMessage{MsgKind::Modify, {.modify = {id, price, qty}}});
            break;
        }
    }

    // Warmup pass (cold-cache effects skew the first run)
    for (const auto& m : var_msgs)   handle_visit(m);
    for (const auto& m : raw_msgs)   handle_vtable(m);
    for (const auto& m : virt_msgs)  m->handle();

    // Timed runs
    double t_visit   = bench_visit(var_msgs);
    double t_virtual = bench_virtual(virt_msgs);
    double t_vtable  = bench_vtable(raw_msgs);

    printf("\n=== Message Dispatcher Benchmark (N=%zu) ===\n\n", N);
    printf("  %-20s  %8.2f ms   %6.2f ns/msg\n",
           "std::visit",  t_visit,   t_visit   * 1e6 / N);
    printf("  %-20s  %8.2f ms   %6.2f ns/msg\n",
           "virtual dispatch", t_virtual, t_virtual * 1e6 / N);
    printf("  %-20s  %8.2f ms   %6.2f ns/msg\n",
           "hand-rolled vtable", t_vtable, t_vtable  * 1e6 / N);
    printf("\n  (sink=%lld -- prevents dead-code elimination)\n\n",
           (long long)g_sink);

    return 0;
}
