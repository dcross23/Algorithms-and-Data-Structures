CC=gcc

#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=disjointSets

OBJ = main.o disjointSet.o

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c disjointSet.h
	$(CC) $(CFLAGS) main.c

disjointSet.o: disjointSet.c disjointSet.h
	$(CC) $(CFLAGS) disjointSet.c 

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
