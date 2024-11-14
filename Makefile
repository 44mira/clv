CC = gcc
CFLAGS = 

objects = test.o clv.o

src/tests: src/test.o src/clv.o
	$(CC) -o $@ $^

$(objects): %.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm ./src/*.o
