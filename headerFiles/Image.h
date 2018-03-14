#include <iostream>
#include <SDL2/SDL.h>
#include <string>
namespace game{
//The image class wraps an SDL surface with function to display the image and has a constructor,
//copy constructor, and desctructor to make it easier to use.
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
