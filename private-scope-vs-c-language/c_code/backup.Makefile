all: my_thread.o libmythread.a

%.o: %.c
	gcc -O -c $< -I. -o $@

libmythread.a: my_thread.o
	ar rcs $@ $<

clean:
	rm libmythread.a my_thread.o