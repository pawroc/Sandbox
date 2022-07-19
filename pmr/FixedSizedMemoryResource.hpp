#pragma once

#include <memory_resource>
#include <fmt/format.h>

struct FixedMemoryResource : std::pmr::memory_resource
{
    FixedMemoryResource(std::byte* buff, size_t size) : nextFreeMemory{buff}, remainingFreeSize{size} {}

    void* do_allocate(size_t bytes, size_t alignment = alignof(max_align_t)) override
    {
        fmt::print("FixedMemoryResource allocating {} bytes from {}\n", bytes, remainingFreeSize);
        if (remainingFreeSize < bytes)
        {
            throw std::bad_alloc();
        }

        auto* resource = nextFreeMemory;
        nextFreeMemory += bytes;
        remainingFreeSize -= bytes;

        fmt::print("FixedMemoryResource allocated {} bytes at {}; remaining: {}\n", bytes, static_cast<const void*>(resource), remainingFreeSize);
        return resource;
    }

    void do_deallocate(void* p, size_t bytes, size_t alignment = alignof(max_align_t)) override
    {
    }

    bool do_is_equal( const std::pmr::memory_resource& other ) const noexcept override
    {
        return false;
    }

private:
    std::byte* nextFreeMemory;
    std::size_t remainingFreeSize;
};