CC=gcc
CFLAGS=-c -g
EXECUTABLE_NAME=hashFO

OBJ = main.o hashFO.o

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c hashFO.h
	$(CC) $(CFLAGS) main.c

hashFO.o: hashFO.c hashFO.h
	$(CC) $(CFLAGS) hashFO.c 

clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
