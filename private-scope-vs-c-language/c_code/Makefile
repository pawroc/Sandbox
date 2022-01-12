OBJECTS = my_thread.o

all: $(OBJECTS) libmythread.a

libmythread.a: $(OBJECTS)
	ar rcs $@ $<

.PHONY: clean
clean:
	-rm libmythread.a $(OBJECTS)
