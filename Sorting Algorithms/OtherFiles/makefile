CC=gcc
#CFLAGS=-c
CFLAGS=-c -g 

all: arraysListsUtilities.o heap.o 

arraysListsUtilities.o: arraysListsUtilities.c arraysListsUtilities.h
	$(CC) $(CFLAGS) arraysListsUtilities.c
	
heap.o: heap.c heap.h
	$(CC) $(CFLAGS) heap.c	

clean: 
	rm *.o
