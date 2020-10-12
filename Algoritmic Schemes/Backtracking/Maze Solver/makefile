CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=mazeSolver

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o mazeSolver.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

mazeSolver.o: mazeSolver.c mazeSolver.h
	$(CC) $(CFLAGS) mazeSolver.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
