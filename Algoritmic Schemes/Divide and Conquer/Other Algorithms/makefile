CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=dc

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o dcAlgorithms.o arraysListsUtilities.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

dcAlgorithms.o: dcAlgorithms.c dcAlgorithms.h
	$(CC) $(CFLAGS) dcAlgorithms.c 

arraysListsUtilities.o: arraysListsUtilities.c arraysListsUtilities.h
	$(CC) $(CFLAGS) arraysListsUtilities.c

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
