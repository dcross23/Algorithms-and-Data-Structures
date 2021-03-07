CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=sortAlg

OF = OtherFiles
OBJ = main.o sortingAlgorithms.o $(OF)/arraysListsUtilities.o $(OF)/heap.o

all: otherFiles $(EXECUTABLE_NAME)

otherFiles:
	cd $(OF); make

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

sortingAlgorithms.o: sortingAlgorithms.c sortingAlgorithms.h
	$(CC) $(CFLAGS) sortingAlgorithms.c

clean: 
	cd $(OF); make clean
	rm *.o
	rm $(EXECUTABLE_NAME)
