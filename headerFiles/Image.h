#include <iostream>
#include <SDL2/SDL.h>
#include <string>
namespace game{

class Image {
public:
	Image(const char* file);
	Image(const Image& toCopy);
	void DisplayImage(SDL_Surface** screenSurface, int width, int height);
	SDL_Surface* GetImage() { return theImage; };
	~Image();
private:
	SDL_Surface* theImage;
	std::string filename;
};

}
