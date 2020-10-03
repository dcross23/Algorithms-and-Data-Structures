CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=eje

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o sortingAlgorithms.o arraysUtility.o
	$(CC) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) main.c

sortingAlgorithms.o: sortingAlgorithms.c sortingAlgorithms.h
	$(CC) $(CFLAGS) sortingAlgorithms.c

arraysUtility.o: arraysUtility.c arraysUtility.h
	$(CC) $(CFLAGS) arraysUtility.c

#%.o: %.c %.h
#	$(CC) -c %.c


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
