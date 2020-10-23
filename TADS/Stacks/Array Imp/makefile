CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=arrayStack

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o arrayStack.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

arrayStack.o: arrayStack.c arrayStack.h
	$(CC) $(CFLAGS) arrayStack.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
