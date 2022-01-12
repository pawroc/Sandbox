#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void(*foo_t)(void);

void my_thread_impl(foo_t foo);

#ifdef __cplusplus
} //end extern "C"
#endif