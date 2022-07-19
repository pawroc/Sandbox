#include "MoreRealisticExample.hpp"
#include "FixedSizedMemoryResource.hpp"
#include <string>
#include <sstream>
#include <vector>

std::pmr::vector<MemoryConsuptingType> memoryConsuptingFunction()
{
    // Will use std::pmr::get_default_resource()
    std::pmr::vector<MemoryConsuptingType> result;

    std::array<std::byte, 16000> buffer;
    FixedMemoryResource resource(buffer.data(), buffer.size());
    MemoryConsuptingType myList{&resource};

    for (std::size_t i = 0; i < 100; ++i)
    {
        std::ostringstream ss;
        ss << i;
        myList.addItem(MemoryConsuptingType::staff_type("Item: ") + MemoryConsuptingType::staff_type(ss.str()));
    }
    result.push_back(myList);
    return result;
}
