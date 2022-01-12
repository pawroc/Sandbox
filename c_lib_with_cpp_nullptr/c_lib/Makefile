SRCS = c_lib.c

ifeq ($(MY_DEFINE), True)
	CFLAGS = -D MY_DEFINE
endif

all: c_lib.o libc_lib.a

c_lib.o: c_lib.c c_lib.h
	gcc $(CFLAGS) -c -o c_lib.o $(SRCS)

libc_lib.a:
	ar rcs libc_lib.a c_lib.o

.PHONY: clean
clean:
	rm -fr libc_lib.a c_lib.o