#pragma once

#include <memory_resource>

struct MyMonotonicResource : public std::pmr::monotonic_buffer_resource
{
    MyMonotonicResource() = default;

    MyMonotonicResource(std::string_view name, std::byte* buff, size_t size, std::pmr::memory_resource* upstream = std::pmr::get_default_resource())
        : std::pmr::monotonic_buffer_resource{buff, size, upstream}
    {
        std::cout << "Creating memory resource buff " << name << " at: " << buff << '\n';
    }

    MyMonotonicResource(std::byte* buff, size_t size, std::pmr::memory_resource* upstream = std::pmr::get_default_resource())
        : std::pmr::monotonic_buffer_resource{buff, size, upstream}
    {
        std::cout << "Creating memory resource buff at: " << buff << '\n';
    }

    void* do_allocate(size_t bytes, size_t alignment = alignof(max_align_t)) override
    {
        void* p = std::pmr::monotonic_buffer_resource::do_allocate(bytes, alignment);
        std::cout << "\tAllocated " << p << " with size " << bytes << " with alignment " << alignment << '\n';
        return p;
    }

    void do_deallocate(void* p, size_t bytes, size_t alignment = alignof(max_align_t)) override
    {
        std::cout << "\tDeallocating (no-op)" << p << " with size " << bytes << " with alignment " << alignment << '\n';
        std::pmr::monotonic_buffer_resource::do_deallocate(p, bytes, alignment);
    }
};