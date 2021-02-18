CC=gcc

#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=LLDisjointSets

OBJ = main.o LLDisjointSet.o

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c LLDisjointSet.h
	$(CC) $(CFLAGS) main.c

LLDisjointSet.o: LLDisjointSet.c LLDisjointSet.h
	$(CC) $(CFLAGS) LLDisjointSet.c 

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
