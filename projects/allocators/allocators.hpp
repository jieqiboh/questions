#pragma once
#include <memory_resource>
#include <cstddef>
#include <new>

class LinearAllocator : public std::pmr::memory_resource {
public:
    explicit LinearAllocator(std::size_t capacity)
        : capacity_(capacity)
        , buf_(static_cast<std::byte*>(::operator new(capacity)))
        , offset_(0)
    {}
    ~LinearAllocator() override { ::operator delete(buf_); }
    std::size_t used()     const noexcept { return offset_; }
    std::size_t capacity() const noexcept { return capacity_; }
    void release() noexcept { offset_ = 0; }

private:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        void*       ptr   = buf_ + offset_;
        std::size_t space = capacity_ - offset_;
        if (!std::align(alignment, bytes, ptr, space)) throw std::bad_alloc{};
        std::size_t padding = static_cast<std::byte*>(ptr) - (buf_ + offset_);
        offset_ += padding + bytes;
        return ptr;
    }
    void do_deallocate(void*, std::size_t, std::size_t) override {}
    bool do_is_equal(const std::pmr::memory_resource& o) const noexcept override {
        return this == &o;
    }
    std::size_t capacity_;
    std::byte*  buf_;
    std::size_t offset_;
};

class PoolAllocator : public std::pmr::memory_resource {
    struct FreeNode { FreeNode* next; };
public:
    PoolAllocator(std::size_t block_size, std::size_t block_align,
                  std::pmr::memory_resource* upstream = std::pmr::get_default_resource())
        : block_size_ (std::max(block_size,  sizeof(FreeNode*)))
        , block_align_(std::max(block_align, alignof(FreeNode*)))
        , upstream_(upstream), free_list_(nullptr)
    {}
private:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        if (bytes > block_size_ || alignment > block_align_)
            return upstream_->allocate(bytes, alignment);
        if (free_list_) {
            FreeNode* node = free_list_;
            free_list_ = node->next;
            return static_cast<void*>(node);
        }
        return upstream_->allocate(block_size_, block_align_);
    }
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override {
        if (bytes > block_size_ || alignment > block_align_) {
            upstream_->deallocate(p, bytes, alignment); return;
        }
        FreeNode* node = static_cast<FreeNode*>(p);
        node->next = free_list_;
        free_list_ = node;
    }
    bool do_is_equal(const std::pmr::memory_resource& o) const noexcept override {
        return this == &o;
    }
    std::size_t block_size_, block_align_;
    std::pmr::memory_resource* upstream_;
    FreeNode* free_list_;
};
