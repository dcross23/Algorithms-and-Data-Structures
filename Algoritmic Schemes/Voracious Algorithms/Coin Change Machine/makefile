CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=chm

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o chm.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

chm.o: chm.c chm.h
	$(CC) $(CFLAGS) chm.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
