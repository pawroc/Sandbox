#pragma once

#include <optional>

namespace library
{
void foo(std::optional<std::string> arg = std::nullopt);
} // namespace library