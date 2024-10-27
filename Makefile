# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -o
# build and run the program
all: 
	make main
	make run
	
# Target to compile the C file
main: main.c
	$(CC) $(CFLAGS) ./build/main main.c
# Target to build and run the program
run: main
	./build/main



