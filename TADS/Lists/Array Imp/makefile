CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=arrayList

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o arrayList.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

arrayList.o: arrayList.c arrayList.h
	$(CC) $(CFLAGS) arrayList.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
	
