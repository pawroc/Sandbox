#pragma once

#include <fmt/format.h>

struct Test
{
    Test(char i_) { i[0] = i_; std::cout << "Test(" << i << ")\n"; }
    ~Test() { std::cout << "~Test(" << i << ")\n"; }

    Test(const Test&) = default;
    Test& operator=(const Test&) = default;
    Test(Test&&) = default;
    Test& operator=(Test&&) = default;

    char i[512];
};

// https://fmt.dev/latest/api.html#format-api
template <> struct fmt::formatter<Test> : formatter<char> {
  template <typename FormatContext>
  auto format(const Test& t, FormatContext& ctx) -> decltype(ctx.out()) {
    return formatter<char>::format(t.i[0], ctx);
  }
};