#include "c_lib.h"

#include <stdio.h>

void foo(void* p) {
#ifdef MY_DEFINE
    printf("Zdefioniowane\n");
#endif
    printf("Hello foo\n");
}