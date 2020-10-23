CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=LLDList

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o LLDList.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

LLDList.o: LLDList.c LLDList.h
	$(CC) $(CFLAGS) LLDList.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
