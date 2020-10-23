CC=gcc
CFLAGS=-c
#CFLAGS=-c -g
EJECUTABLE_NAME=eje

all: $(EJECUTABLE_NAME)

$(EJECUTABLE_NAME): main.o searchAlgorithms.o arraysUtility.o
	$(CC) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) main.c

searchAlgorithms.o: searchAlgorithms.c searchAlgorithms.h
	$(CC) $(CFLAGS) searchAlgorithms.c

arraysUtility.o: arraysUtility.c arraysUtility.h
	$(CC) $(CFLAGS) arraysUtility.c

#%.o: %.c %.h
#	$(CC) -c %.c


clean: 
	rm *.o
	rm $(EJECUTABLE_NAME)
