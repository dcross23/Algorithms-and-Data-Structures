CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=graphs

OF = OtherFiles
OBJ = main.o graph.o $(OF)/linkedListQueue.o $(OF)/linkedListStack.o $(OF)/heap.o

.PHONY: all
all: otherFiles $(EXECUTABLE_NAME)

.PHONY: otherFiles
otherFiles:
	cd $(OF); make

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c graph.h
	$(CC) $(CFLAGS) main.c

graph.o: graph.c graph.h $(OF)/linkedListQueue.h $(OF)/linkedListStack.h $(OF)/heap.h
	$(CC) $(CFLAGS) graph.c

.PHONY: clean
clean: 
	cd $(OF); make clean
	rm *.o
	rm $(EXECUTABLE_NAME)
