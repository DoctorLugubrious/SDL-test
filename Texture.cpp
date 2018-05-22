#include "Texture.h"
#include "Image.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

namespace game {
	/*
	 * The default constructor is necessary for putting the texture in certain
	 * data structures and really shouldn't be called other than that, since
	 * it won't be able to do anything.
	 */
	Texture::Texture(): 
		xSize(0),
		ySize(0),
		xPos(0),
		yPos(0),
		theTexture(NULL), 
		thisRenderer(NULL), 
		filename("") {}
	
	//parameterized constructor that takes a filename and a renderer to render to
	Texture::Texture(std::string initFilename, SDL_Renderer*& renderer, SDL_Rect location):
		xSize(location.w),
		ySize(location.h),
		xPos(location.x),
		yPos(location.y),
		theTexture(NULL),
		thisRenderer(renderer),
		filename(initFilename) {
		this->init(filename.c_str());
	}

	//copy constructor
	Texture::Texture(const Texture& toCopy):
		xSize(toCopy.xSize),
		ySize(toCopy.ySize),
		xPos(toCopy.xPos),
		yPos(toCopy.yPos),
		theTexture(NULL),
		thisRenderer(toCopy.thisRenderer),
		filename(toCopy.filename) {
		if (filename != "") {
			this->init(filename.c_str());
		}
	}

	//initialize the texture
	void Texture::init(const char* filename) {
		Image initImage(filename);
		if (thisRenderer != NULL ) {
			SDL_SetColorKey(*initImage, SDL_TRUE, SDL_MapRGB( (*initImage)->format, 0x00, 0xff, 0x00));
			theTexture = SDL_CreateTextureFromSurface(thisRenderer, initImage.GetImage());
			if (theTexture == NULL) {	
				std::string error = "Unable to create texture! SDL Error: "; 
				error += SDL_GetError();
				throw(GraphicsException(error));
			}
		}
	}

	//displays the texture on the current surface
	void Texture::Display() {
		SDL_Rect clip = { xPos, yPos, xSize, ySize };

		SDL_RenderCopyEx(thisRenderer, theTexture, NULL, &clip, 0.0, NULL, SDL_FLIP_NONE);
	}
	
	//displays the texture on the current surface
	void Texture::Display(SDL_Rect& area) {
		SDL_Rect clip = { xPos, yPos, area.w, area.h };

		SDL_RenderCopyEx(thisRenderer, theTexture, &area, &clip, 0.0, NULL, SDL_FLIP_NONE);
	}

	//displays the texture on the current surface
	void Texture::DisplayFlipped(SDL_Rect& area) {
		SDL_Rect clip = { xPos, yPos, area.w, area.h };

		SDL_RenderCopyEx(thisRenderer, theTexture, &area, &clip, 0.0, NULL, SDL_FLIP_HORIZONTAL);
	}

	void Texture::UpdatePosition(int x, int y) {
		xPos = x;
		yPos = y;
	}

	SDL_Rect Texture::IsIn(int x, int y) {
		if (x > xPos && y > yPos && x < xPos + xSize && y < yPos + ySize) {
			return {xPos, yPos, xSize, ySize};
		}
		return {0, 0, 0, 0};
	}

	//deallocates memory for the texture
	Texture::~Texture() {
		if (theTexture != NULL) {
			SDL_DestroyTexture(theTexture);
		}
		theTexture = NULL;
	}

}
