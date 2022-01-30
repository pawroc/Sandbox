#pragma once

#include <stdint.h>

#define LOG(...) c_wrapper(__FILE__, __LINE__, __VA_ARGS__)

void c_wrapper(const char* file, uint32_t line, const char* fmt, ...);