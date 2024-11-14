CC = gcc
CFLAGS = 

testObjects = tests/test.o src/clv.o

kickstart:

tests: $(testObjects)
	$(CC) -o test $^

$(testObjects): %.o: %.c
	$(CC) -o $@ -c ./$^

.PHONY: clean
clean:
	rm ./**/*.o
