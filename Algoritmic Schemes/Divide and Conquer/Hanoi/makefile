CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=hanoi

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o hanoi.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

hanoi.o: hanoi.c hanoi.h
	$(CC) $(CFLAGS) hanoi.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
