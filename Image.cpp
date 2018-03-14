//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include "Image.h"
namespace game { 

using std::cout;
using std::endl;
//Constructs an image given the filename of the image 
Image::Image(const char* file) {	
	theImage = SDL_LoadBMP(file);
	if(theImage == NULL)
	{
		cout << "Unable to load image! SDL Error: " << SDL_GetError() << endl;
	}
	filename = file;
 };
//copy constructor
Image::Image(const Image& toCopy) {
	theImage = SDL_LoadBMP(toCopy.filename.c_str());
	if (theImage == NULL) {
		cout << "Unable to load image! SDL Error" << SDL_GetError() << endl;
	}
	filename = toCopy.filename;
}
//given a surface to display on and a size, optimizes the image for that surface
//and displays it
void Image::DisplayImage(SDL_Surface** screenSurface, int width, int height) {
	if (theImage == NULL) { return; }
	theImage = SDL_ConvertSurface(theImage, (*screenSurface)->format, 0);
	if (theImage == NULL) {
		cout << "Unable to optimize image!" << SDL_GetError() << endl;
		return;
	}
	SDL_Rect imageArea;
	imageArea.x = 0;
	imageArea.y = 0;
	imageArea.w = width;
	imageArea.h = height;
	SDL_BlitScaled(theImage, NULL, *screenSurface, &imageArea);
}
//if image not null, deallocate memory
Image::~Image() {
	if(theImage != NULL) {
		SDL_FreeSurface(theImage);
		theImage = NULL;
	} 
}

}
