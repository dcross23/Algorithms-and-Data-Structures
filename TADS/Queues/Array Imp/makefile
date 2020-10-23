CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=arrayQueue

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o arrayQueue.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

arrayQueue.o: arrayQueue.c arrayQueue.h
	$(CC) $(CFLAGS) arrayQueue.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
