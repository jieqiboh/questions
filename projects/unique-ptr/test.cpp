#include "unique_ptr.hpp"
#include <cassert>
#include <iostream>
#include <string>

struct Widget {
    int val;
    Widget(int v) : val(v) {}
};

static int destructor_count = 0;
struct Tracked {
    ~Tracked() { ++destructor_count; }
};

int main() {
    // Basic construction and dereference
    {
        unique_ptr<int> p(new int(42));
        assert(p);
        assert(*p == 42);
        assert(p.get() != nullptr);
    }

    // Destructor fires
    {
        destructor_count = 0;
        { unique_ptr<Tracked> p(new Tracked); }
        assert(destructor_count == 1);
    }

    // Move construction
    {
        unique_ptr<int> a(new int(7));
        unique_ptr<int> b(std::move(a));
        assert(!a);
        assert(*b == 7);
    }

    // Move assignment
    {
        unique_ptr<int> a(new int(1));
        unique_ptr<int> b(new int(2));
        b = std::move(a);
        assert(!a);
        assert(*b == 1);
    }

    // release()
    {
        unique_ptr<int> p(new int(99));
        int* raw = p.release();
        assert(!p);
        assert(*raw == 99);
        delete raw;
    }

    // reset()
    {
        destructor_count = 0;
        unique_ptr<Tracked> p(new Tracked);
        p.reset(new Tracked);        // old one destroyed
        assert(destructor_count == 1);
        p.reset();                   // second one destroyed
        assert(destructor_count == 2);
        assert(!p);
    }

    // Arrow operator
    {
        unique_ptr<Widget> p(new Widget(5));
        assert(p->val == 5);
    }

    // Custom deleter
    {
        bool called = false;
        auto del = [&](int* p) { called = true; delete p; };
        {
            unique_ptr<int, decltype(del)> p(new int(3), del);
        }
        assert(called);
    }

    // Array: basic indexing
    {
        unique_ptr<int[]> p(new int[3]{10, 20, 30});
        assert(p[0] == 10);
        assert(p[1] == 20);
        assert(p[2] == 30);
    }

    // Array: destructor calls delete[]
    {
        destructor_count = 0;
        { unique_ptr<Tracked[]> p(new Tracked[3]); }
        assert(destructor_count == 3);
    }

    // Array: move
    {
        unique_ptr<int[]> a(new int[2]{4, 5});
        unique_ptr<int[]> b(std::move(a));
        assert(!a);
        assert(b[0] == 4 && b[1] == 5);
    }

    // Array: reset
    {
        unique_ptr<int[]> p(new int[2]{1, 2});
        p.reset(new int[2]{3, 4});
        assert(p[0] == 3);
        p.reset();
        assert(!p);
    }

    // make_unique: single object
    {
        auto p = make_unique<Widget>(99);
        assert(p->val == 99);
    }

    // make_unique: array
    {
        auto p = make_unique<int[]>(5);
        for (int i = 0; i < 5; ++i) assert(p[i] == 0);  // value-initialized
    }

    std::cout << "All tests passed.\n";
}
