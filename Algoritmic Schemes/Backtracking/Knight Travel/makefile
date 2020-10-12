CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=knightTravel

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o knightTravel.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

knightTravel.o: knightTravel.c knightTravel.h
	$(CC) $(CFLAGS) knightTravel.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
