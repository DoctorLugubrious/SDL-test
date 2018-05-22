//Using SDL and standard IO
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.h"
#include "Exceptions.h"

namespace game { 

	using std::cout;
	using std::endl;
	//Constructs an image given the filename of the image. Can throw GraphicsException
	Image::Image(std::string file) {
		int imageFlag = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlag) & imageFlag)) {
			std::string error = "Image error: "; 
			error += IMG_GetError();
			throw(GraphicsException(error));
		}	
		theImage = IMG_Load(file.c_str());
		if(theImage == NULL) {
			std::string error = "Unabe to load image! SDL Error: "; 
			error += SDL_GetError();
			throw(GraphicsException(error));
		}
		filename = file;
	 };
	//copy constructor, can throw GraphicsException
	Image::Image(const Image& toCopy) {
		int imageFlag = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlag) & imageFlag)) {
			std::string error = "Image error: ";
			error += IMG_GetError();
			throw(GraphicsException(error));
		}
		theImage = IMG_Load(toCopy.filename.c_str());
		if (theImage == NULL) {
			std::string error = "Unabe to load image! SDL Error: "; 
			error += SDL_GetError();
			throw(GraphicsException(error));
		}
		filename = toCopy.filename;
	}
	//given a surface to display on and a size, optimizes the image for that surface
	//and displays it. can throw GraphicsException
	void Image::DisplayImage(SDL_Surface** screenSurface, int width, int height) {
		if (theImage == NULL) { return; }
		theImage = SDL_ConvertSurface(theImage, (*screenSurface)->format, 0);
		if (theImage == NULL) {
			std::string error = "Unabe to optimize image! SDL Error: "; 
			error += SDL_GetError();
			throw(GraphicsException(error));
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
