CC=gcc

#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=TreeDisjointSets

OBJ = main.o TreeDisjointSet.o

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c TreeDisjointSet.h
	$(CC) $(CFLAGS) main.c

TreeDisjointSet.o: TreeDisjointSet.c TreeDisjointSet.h
	$(CC) $(CFLAGS) TreeDisjointSet.c 

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
