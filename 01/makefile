CC=g++
FLAGS=-std=c++17 -Wall -pedantic -Wextra -Wno-unused-variable

all: test
	
test: test.o Allocator.o
	$(CC) $(FLAGS) -o test test.o Allocator.o

test.o: test.cpp Allocator.h
	$(CC) $(FLAGS) -c test.cpp

Allocator.o: Allocator.cpp Allocator.h
	$(CC) $(FLAGS) -c Allocator.cpp

clean:
	rm -rf *.o test

