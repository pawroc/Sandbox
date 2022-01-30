# Problem statement

We want to reuse the same header between C and C++ code. In this case, this is `common_lib.h` defining LOG macro.
The problem is that C++ code uses class acomplishing this task. As we know, C cannot include C++ code.
Therefore, there is a need to define some abstraction layer, so called `common_lib.cpp` over `common_lib.h`.
In order to pass variadic number of arguments from `variadic function` into class' method, we should
pass `va_list` into the method.