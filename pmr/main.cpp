#include <algorithm>
#include <cstddef>
#include <memory_resource>
#include <array>
#include <list>
#include <vector>
#include <iostream>
#include <fmt/format.h>
#include "FixedSizedMemoryResource.hpp"
#include "MonotonicMemoryResource.hpp"
#include "CustomTypes.hpp"
#include "MoreRealisticExample.hpp"

template <typename ItrBegin, typename ItrEnd>
void print_line(int offset, ItrBegin begin, const ItrEnd end) {
//   fmt::print("(dec) {:02x}:  {:3}\n", offset, fmt::join(begin, end, "  "));
//   fmt::print("(hex) {:02x}:   {:02x}\n", offset, fmt::join(begin, end, "   "));

  fmt::print("(asc) {:02x}:", offset);

  std::for_each(begin, end, [](const auto c) {
    if (std::isgraph(std::to_integer<char>(c))) {
      fmt::print("   {} ", static_cast<char>(c));
    } else {
      fmt::print(" \\{:03o}", c);
    }
  });

  fmt::print("\n");
}

template <typename Buffer, typename Container>
void print_buffer(const std::string_view title, const Buffer &buffer,
                  const Container &container) {
  fmt::print("==============={:^10}==============\n", title);

  auto begin = buffer.begin();
  fmt::print("Buffer Address Start: {}\n",
             static_cast<const void *>(buffer.data()));
  for (const auto &elem : container) {
    fmt::print(" Item Address: {}; Value: {}\n", static_cast<const void *>(&elem), elem);
  }

  for (std::size_t offset = 0; offset < buffer.size(); offset += 24) {
    auto end = std::min(offset + 24, buffer.size());
    print_line(offset, std::next(begin, offset), std::next(begin, end));
  }

  fmt::print("\n");
}

template <typename Buffer>
void print_buffer(const std::string_view title, const Buffer &buffer) {
  fmt::print("==============={:^10}==============\n", title);

  auto begin = buffer.begin();
  fmt::print("Buffer Address Start: {}\n",
             static_cast<const void *>(buffer.data()));

  for (std::size_t offset = 0; offset < buffer.size(); offset += 24) {
    auto end = std::min(offset + 24, buffer.size());
    print_line(offset, std::next(begin, offset), std::next(begin, end));
  }

  fmt::print("\n");
}

// When vector resizes, old memory is not reused (deallocated) but instead
// further region of the given memory resource is utilized.
void example_1()
{
    fmt::print("==============={:^10}==============\n", "std::pmr::vector");

    std::array<std::byte, 64> buffer;
    for (auto& v : buffer) { v = std::byte(0); }
    MyMonotonicResource mbr{buffer.data(), buffer.size()};
    std::pmr::vector<Test> vec{&mbr};

    print_buffer("Example 1: empty", buffer, vec);

    vec.emplace_back('A');
    print_buffer("Example 1: 1 element", buffer, vec);

    vec.emplace_back('B');
    print_buffer("Example 1: 2 elements", buffer, vec);

    vec.emplace_back('C');
    print_buffer("Example 1: 3 elements", buffer, vec);

    vec.emplace_back('D');
    print_buffer("Example 1: 4 elements", buffer, vec);
}

// Containers that allocates own internal memory also uses given memory resource
void example_2()
{
    fmt::print("==============={:^10}==============\n", "std::pmr::list");

    std::array<std::byte, 128> buffer;
    for (auto& v : buffer) { v = std::byte(0); }
    MyMonotonicResource mbr{buffer.data(), buffer.size()};
    std::pmr::list<std::byte> list{&mbr};

    print_buffer("Example 2: empty", buffer, list);

    list.push_back(std::byte('A'));
    print_buffer("Example 2: 1 element", buffer, list);

    list.push_back(std::byte('B'));
    print_buffer("Example 2: 2 elements", buffer, list);

    list.push_back(std::byte('C'));
    print_buffer("Example 2: 3 elements", buffer, list);

    list.push_back(std::byte('D'));
    print_buffer("Example 2: 4 elements", buffer, list);
}

// Using upstream memory resource when resource is exhausted
void example_3()
{
    fmt::print("==============={:^10}==============\n", "using upstream memory resource");

    std::array<std::byte, 64> upstream_buffer;
    for (auto& v : upstream_buffer) { v = std::byte(0); }

    std::array<std::byte, 3> buffer;
    for (auto& v : buffer) { v = std::byte(0); }

    // upstream uses null_memory_resource which throws std::bad_alloc when allocate is called
    MyMonotonicResource upstream{"upstream", upstream_buffer.data(), upstream_buffer.size(), std::pmr::null_memory_resource()};
    MyMonotonicResource mbr{"main", buffer.data(), buffer.size(), &upstream};
    std::pmr::vector<std::byte> vec{&mbr};

    print_buffer("Example 1: empty main buffer", buffer, vec);
    print_buffer("Example 1: empty upstream buffer", upstream_buffer);

    vec.push_back(std::byte('A'));
    print_buffer("Example 1: 1 element main buffer", buffer, vec);
    print_buffer("Example 1: 1 element upstream buffer", upstream_buffer);

    vec.push_back(std::byte('B'));
    print_buffer("Example 1: 2 elements main buffer", buffer, vec);
    print_buffer("Example 1: 2 elements upstream buffer", upstream_buffer);

    // The vector will require 4 bytes of memory which gives 7 bytes required from main memory resource.
    // Due to lack of memory in main resource, upstream will be used.
    // Warning:
    // When upstream resource is used by monotonic_buffer_resource, it is implementation-defined what is
    // a growth factor (see specyfication). In x84-64 gcc 12.1 implementation it is 64 bytes.
    vec.push_back(std::byte('C'));
    print_buffer("Example 1: 3 elements main buffer", buffer);
    print_buffer("Example 1: 3 elements upstream buffer", upstream_buffer, vec);

    vec.push_back(std::byte('D'));
    print_buffer("Example 1: 4 elements main buffer", buffer);
    print_buffer("Example 1: 4 elements upstream buffer", upstream_buffer, vec);
}

// std::pmr::unsynchronized_pool_resource
void example_4()
{
    fmt::print("==============={:^10}==============\n", "using pool memory resource");

    static constexpr std::uint8_t elementsCount{2};

    std::array<std::byte, elementsCount*32+768> buffer;
    for (auto& v : buffer) { v = std::byte(0); }


    std::pmr::pool_options pool_options{16, 1024};
    MyMonotonicResource pool_1_mr{"pool-1", buffer.data(), buffer.size()};//, std::pmr::null_memory_resource()};
    std::pmr::unsynchronized_pool_resource pool_1{pool_options, &pool_1_mr};
    std::pmr::list<Test> list{&pool_1};

    print_buffer("Example 1: empty main buffer", buffer, list);

    for (char c = 100; c != elementsCount+100; ++c)
    {
        try
        {
            list.emplace_back(c);
            print_buffer("Example 1: x elements main buffer", buffer, list);
        }
        catch(...)
        {
            std::cout << "exception\n";
        }
    }
}

void example_5()
{
    fmt::print("==============={:^10}==============\n", "pool memory resource");

    std::array<std::byte, 16000> buffer;
    std::fill_n(buffer.begin(), buffer.size(), std::byte(0));

    FixedMemoryResource pool_mr{buffer.data(), buffer.size()};
    std::pmr::unsynchronized_pool_resource pool{&pool_mr};
    fmt::print("Pool options: {}, {}\n", pool.options().max_blocks_per_chunk, pool.options().largest_required_pool_block);

    std::pmr::list<char> charList{&pool};
    std::pmr::list<Test> testList{&pool};

    for (char c = 'A'; c < 'X'; ++c)
    {
        fmt::print("Allocating {}\n", c);
        charList.emplace_back(c);
    }
    fmt::print("Allocating X\n");
    testList.emplace_back('X');
    fmt::print("Allocating Y\n");
    testList.emplace_back('Y');
    fmt::print("Allocating Z\n");
    testList.emplace_back('Z');
    fmt::print("Allocating x\n");
    testList.emplace_back('x');
}

// std::pmr::pool_options
void example_6()
{
    fmt::print("==============={:^10}==============\n", "pool memory resource");

    std::array<std::byte, 16000> buffer;
    std::fill_n(buffer.begin(), buffer.size(), std::byte(0));

    std::pmr::pool_options pool_options{2, 576};
    FixedMemoryResource pool_mr{buffer.data(), buffer.size()};
    std::pmr::unsynchronized_pool_resource pool{pool_options, &pool_mr};
    fmt::print("Pool options: {}, {}\n", pool.options().max_blocks_per_chunk, pool.options().largest_required_pool_block);

    std::pmr::list<char> charList{&pool};
    std::pmr::list<Test> testList{&pool};

    for (char c = 'A'; c < 'X'; ++c)
    {
        fmt::print("Allocating {}\n", c);
        charList.emplace_back(c);
    }
    fmt::print("Allocating X\n");
    testList.emplace_back('X');
    fmt::print("Allocating Y\n");
    testList.emplace_back('Y');
    fmt::print("Allocating Z\n");
    testList.emplace_back('Z');
    fmt::print("Allocating x\n");
    testList.emplace_back('x');
}

int main()
{
    // example_6();
    auto result = memoryConsuptingFunction();
    for (const auto& v : result)
    {
      std::cout << v << '\n';
    }
    // std::for_each(std::cbegin(result), std::cend(result), std::ostream_iterator<MemoryConsuptingType>(std::cout, "\n"));
    return 0;
}