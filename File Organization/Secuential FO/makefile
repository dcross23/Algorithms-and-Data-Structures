CC=gcc
CFLAGS=-c -g
EXECUTABLE_NAME=secFO

OBJ = main.o secuentialFO.o

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c secuentialFO.h
	$(CC) $(CFLAGS) main.c

secuentialFO.o: secuentialFO.c secuentialFO.h
	$(CC) $(CFLAGS) secuentialFO.c 

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
