CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=linkedListQueue

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o linkedListQueue.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

linkedListQueue.o: linkedListQueue.c linkedListQueue.h
	$(CC) $(CFLAGS) linkedListQueue.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
