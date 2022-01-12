#include "my_thread.h"
#include <stdio.h>

void my_thread_impl(foo_t foo) {
    printf("Wolam foo z C\n");
    foo();
}