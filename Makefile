CC = g++
CFLAGS = -I ./headerFiles -Wall -c -g -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_image -o
EXECUTABLE_NAME = executable
define OBJS
source.o Image.o Environment.o Texture.o Renderer.o Window.o ImageLibrary.o Character.o AnimatedCharacter.o CharacterSpriteSheet.o
endef
.PHONY:
all: $(OBJS)
	$(CC) $(OBJS) $(LINKER_FLAGS) $(EXECUTABLE_NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

.PHONY:
clean:
	rm -rf *.o
	rm executable 
