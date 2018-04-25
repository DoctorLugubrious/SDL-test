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
		ySize(0)
 	{}
	
	//parameterized constructor that takes a filename and a renderer to render to
	Texture::Texture(const char* initFilename, SDL_Renderer*& renderer, size_t width, size_t height):
		 theTexture(NULL),
		 thisRenderer(renderer),
		 filename(initFilename),
		 xSize(width),
		 ySize(height) {
		this->init(filename.c_str());
	}

	//copy constructor
	Texture::Texture(const Texture& toCopy):
		 theTexture(NULL),
		 thisRenderer(toCopy.thisRenderer),
		 filename(toCopy.filename),
		 xSize(toCopy.xSize),
		 ySize(toCopy.ySize) {
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
	void Texture::Display(int xPos, int yPos) {
		SDL_Rect clip = { xPos, yPos, xSize, ySize };

		SDL_RenderCopyEx(thisRenderer, theTexture, NULL, &clip, 0.0, NULL, SDL_FLIP_NONE);
	}

	//deallocates memory for the texture
	Texture::~Texture() {
		if (theTexture != NULL) {
			SDL_DestroyTexture(theTexture);
		}
		theTexture = NULL;
	}

}
