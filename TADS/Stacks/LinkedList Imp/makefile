CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=linkedListStack

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o linkedListStack.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

linkedListStack.o: linkedListStack.c linkedListStack.h
	$(CC) $(CFLAGS) linkedListStack.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
