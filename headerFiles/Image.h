#ifndef IMAGE_DOT_H_
#define IMAGE_DOT_H
#include <iostream>
#include <string>

#include <SDL2/SDL.h>
namespace game{
/*The Image class allows a software image to be displayed. It is not reccomended to use it,
 *but the texture class needs one to load a hardware Texture.
 ***Image(std::string file)
 ***	opens the image at the given filename
 ***DisplayImage(SDL_Surface**, int, int)
 ***	Displays the image given on the surface at the given width and height
 */
class Image {
public:
	Image(std::string file);
	Image(const Image& toCopy);
	void DisplayImage(SDL_Surface** screenSurface, int width, int height);
	SDL_Surface* GetImage() { return theImage; };
	SDL_Surface* operator*() { return theImage; };
	~Image();
private:
	SDL_Surface* theImage;
	std::string filename;
};

}

#endif
