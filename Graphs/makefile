CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=graphs

OF = OtherFiles
OBJ = main.o graph.o $(OF)/linkedListQueue.o $(OF)/linkedListStack.o

all: otherFiles $(EXECUTABLE_NAME)

otherFiles:
	cd $(OF); make

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) graph.c

.PHONY: clean
clean: 
	cd $(OF); make clean
	rm *.o
	rm $(EXECUTABLE_NAME)
