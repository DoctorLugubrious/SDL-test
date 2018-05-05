#include "Texture.h"
#include "Image.h"
#include <iostream>

using std::cout;
using std::endl;

namespace game {
	/*
	 * The default constructor is necessary for putting the texture in certain
	 * data structures and really shouldn't be called other than that, since
	 * it won't be able to do anything.
	 */
	Texture::Texture(): 
		theTexture(NULL), 
		thisRenderer(NULL), 
		filename(""),
		xSize(0),
		ySize(0),
		xPos(0),
		yPos(0)
 	{}
	
	//parameterized constructor that takes a filename and a renderer to render to
	Texture::Texture(const char* initFilename, SDL_Renderer*& renderer, SDL_Rect location):
		theTexture(NULL),
		thisRenderer(renderer),
		filename(initFilename),
		xSize(location.w),
		ySize(location.h),
		xPos(location.x),
		yPos(location.y) {
		this->init(filename.c_str());
	}

	//copy constructor
	Texture::Texture(const Texture& toCopy):
		theTexture(NULL),
		thisRenderer(toCopy.thisRenderer),
		filename(toCopy.filename),
		xSize(toCopy.xSize),
		ySize(toCopy.ySize),
		xPos(toCopy.xPos),
		yPos(toCopy.yPos) {
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
				std::cout << "Unable to create texture! SDL Error: " 
					<< SDL_GetError() << std::endl;
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

	//deallocates memory for the texture
	Texture::~Texture() {
		if (theTexture != NULL) {
			SDL_DestroyTexture(theTexture);
		}
		theTexture = NULL;
	}

}
