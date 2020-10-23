CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=backPack

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o backPack.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

backPack.o: backPack.c backPack.h
	$(CC) $(CFLAGS) backPack.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
