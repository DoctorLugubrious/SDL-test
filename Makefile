CC = g++
CFLAGS = -I ./headerFiles -Wall -c -std=c++11 
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -o
EXECUTABLE_NAME = executable
OBJS = source.o Image.o Environment.o Texture.o Renderer.o Window.o ImageLibrary.o AnimatedCharacter.o \
CharacterSpriteSheet.o Text.o Font.o Platform.o AuraSphere.o StaticEntity.o Character.o EnemySpriteSheet.o Enemy.o \
EnemyHorde.o MainMenu.o


# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

.PHONY:
all: $(OBJS)
	$(CC) $(OBJS) $(LINKER_FLAGS) $(EXECUTABLE_NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $<
	$(CC) -MM $(CFLAGS) $*.cpp > $*.d

.PHONY:
clean:
	rm -rf *.o
	rm -rf *.d
	rm executable 
