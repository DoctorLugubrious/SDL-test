CC = g++
CFLAGS = -I ./headerFiles -Wall -c  
LINKER_FLAGS = -lSDL2 -o
EXECUTABLE_NAME = executable
OBJS = source.o Image.o Environment.o

.PHONY:
all: $(OBJS)
	$(CC) $(OBJS) $(LINKER_FLAGS) $(EXECUTABLE_NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

.PHONY:
clean:
	rm -rf *.o
	rm executable 
