CC = gcc
CFLAGS = 

testObjects = tests/test.o src/clv.o

tests: $(testObjects)
	$(CC) -o $@ $^

$(testObjects): %.o: %.c
	$(CC) -o $@ -c ./$^

clean:
	rm ./**/*.o
