CC=gcc
CFLAGS=-c -g
EXECUTABLE_NAME=bstrees

OBJ = main.o BSTree.o

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c BSTree.h
	$(CC) $(CFLAGS) main.c

BSTree.o: BSTree.c BSTree.h
	$(CC) $(CFLAGS) BSTree.c 

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
