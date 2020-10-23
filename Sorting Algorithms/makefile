CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=eje

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o sortingAlgorithms.o arraysListsUtilities.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

sortingAlgorithms.o: sortingAlgorithms.c sortingAlgorithms.h
	$(CC) $(CFLAGS) sortingAlgorithms.c

arraysListsUtilities.o: arraysListsUtilities.c arraysListsUtilities.h
	$(CC) $(CFLAGS) arraysListsUtilities.c

#%.o: %.c %.h
#	$(CC) -c %.c


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
