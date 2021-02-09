CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=heap

OBJ = main.o heap.o

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c heap.h
	$(CC) $(CFLAGS) main.c

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) heap.c 

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
