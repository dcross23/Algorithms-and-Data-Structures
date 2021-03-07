#CFLAGS
CC=gcc
CFLAGS=-c -g 

#SOURCE AND OBJECT FILES
SRC = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRC))

#DEPENDENCIES
DEPS_FLAGS = -MMD -MF $(@:.o=.d)
DEPS = $(patsubst %.o,%.d,$(OBJS))
-include $(DEPS)


.PHONY: all clean

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< $(DEPS_FLAGS)
	
clean: 
	rm *.o
	rm *.d
