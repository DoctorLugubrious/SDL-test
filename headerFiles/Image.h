#include <iostream>
#include <SDL2/SDL.h>

namespace game{

class Image {
public:
	Image();
	void SetImage(const char* file);
	void DisplayImage(SDL_Surface** screenSurface, int width, int height);
	SDL_Surface* GetImage() { return theImage; };
	~Image();
private:
	SDL_Surface* theImage;
};

}
