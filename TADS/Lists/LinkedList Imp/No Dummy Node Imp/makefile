CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=LLNDList

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o LLNDList.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

LLNDList.o: LLNDList.c LLNDList.h
	$(CC) $(CFLAGS) LLNDList.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
