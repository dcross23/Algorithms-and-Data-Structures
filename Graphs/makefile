EXECUTABLE_NAME=graphs

#CFLAGS
CC=gcc
CFLAGS=-c -g

#OTHERFILES
OF = OtherFiles
OF_SRC = $(wildcard $(OF)/*.c)
OF_OBJS = $(patsubst $(OF)/%.c,$(OF)/%.o,$(OF_SRC))

#THIS FOLDER
OBJ = graph.o $(OF_OBJS) main.o

#DEPENDENCIES
DEPS_FLAG = -MMD -MF $(@:.o=.d)
DEP = $(patsubst %.o,%.d,$(OBJ))
-include $(DEP)


.PHONY: all otherFiles run debug clean


all: otherFiles $(EXECUTABLE_NAME)

otherFiles:
	cd $(OF); make all

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: otherFiles main.c
	$(CC) $(CFLAGS) main.c $(DEPS_FLAG)
	
graph.o: otherFiles graph.c
	$(CC) $(CFLAGS) graph.c $(DEPS_FLAG)


run: 
	make
	./$(EXECUTABLE_NAME)

debug:
	make
	gdb ./$(EXECUTABLE_NAME)


clean: 
	cd $(OF); make clean
	rm *.o 
	rm *.d 
	rm $(EXECUTABLE_NAME)
