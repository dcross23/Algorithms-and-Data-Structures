CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=eightQueens

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o eightQueens.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

eightQueens.o: eightQueens.c eightQueens.h
	$(CC) $(CFLAGS) eightQueens.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
clean-txt:
	rm *.txt
