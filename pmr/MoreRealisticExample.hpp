#pragma once

#include "FixedSizedMemoryResource.hpp"
#include <memory>
#include <vector>
#include <memory_resource>
#include <algorithm>

class MemoryConsuptingType
{
public:
    // This type makes uses_allocator<ShoppingList, memory_resource*>::value true.
    using allocator_type = std::pmr::memory_resource*;
    using staff_type = std::pmr::string;
    using vector = std::pmr::vector<staff_type>;

public:
    // If no resource is given, the vect_ will use std::pmr::get_default_resource()
    MemoryConsuptingType(allocator_type alloc = nullptr) : vect_(alloc) {}
    MemoryConsuptingType(const MemoryConsuptingType& other) = default;

    // https://en.cppreference.com/w/cpp/memory/uses_allocator
    // Used in uses_allocator construction
    // MemoryConsuptingType(std::allocator_arg_t, allocator_type alloc, const MemoryConsuptingType& other)
    // : vect_{other.vect_, alloc} {}
    // MemoryConsuptingType(allocator_type alloc, const MemoryConsuptingType& other) : vect_{other, alloc} {}

    allocator_type getAllocator()
    {
        return vect_.get_allocator().resource();
    }

    void addItem(const staff_type& newStaff)
    {
        vect_.push_back(newStaff);
    }

    friend std::ostream& operator<<(std::ostream& os, const MemoryConsuptingType& obj)
    {
        for (const auto& v : obj.vect_)
        {
            os << v << '\n';
        }
        // std::for_each(std::cbegin(obj.vect_), std::cend(obj.vect_), std::ostream_iterator<char>(os, "\n"));
        return os;
    }

private:
    vector vect_;
};

std::pmr::vector<MemoryConsuptingType> memoryConsuptingFunction();