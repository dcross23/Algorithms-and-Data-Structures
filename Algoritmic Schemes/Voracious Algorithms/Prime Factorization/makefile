CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=pF

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o primeFact.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

primeFact.o: primeFact.c primeFact.h
	$(CC) $(CFLAGS) primeFact.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
