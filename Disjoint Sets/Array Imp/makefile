CC=gcc

#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=arrayDisjointSets

OBJ = main.o arrayDisjointSet.o

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c arrayDisjointSet.h
	$(CC) $(CFLAGS) main.c

arrayDisjointSet.o: arrayDisjointSet.c arrayDisjointSet.h
	$(CC) $(CFLAGS) arrayDisjointSet.c 

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
