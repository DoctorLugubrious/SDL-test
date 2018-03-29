#include "Texture.h"
#include "Image.h"
#include <iostream>

using std::cout;
using std::endl;

namespace game {

	//parameterized constructor that takes a filename and a renderer to render to
	Texture::Texture(const char* initFilename, SDL_Renderer*& renderer) {
		filename = initFilename;
		Image initImage(filename.c_str());
		thisRenderer = renderer;
		if (thisRenderer != NULL) {
			theTexture = SDL_CreateTextureFromSurface(thisRenderer, initImage.GetImage());
			if (theTexture == NULL) {
				std::cout << "Unable to create texture! SDL Error: " 
					<< SDL_GetError() << std::endl;
			} 
		}
	}

	//copy constructor
	Texture::Texture(const Texture& toCopy) {
		filename = toCopy.filename;
		Image initImage(toCopy.filename.c_str());
		thisRenderer = toCopy.thisRenderer;
		if (thisRenderer != NULL ) {
			theTexture = SDL_CreateTextureFromSurface(thisRenderer, initImage.GetImage());
			if (theTexture == NULL) {	
				std::cout << "Unable to create texture! SDL Error: " 
					<< SDL_GetError() << std::endl;
			}
		}
	}

	//displays the texture on the current surface
	void Texture::Display() {
		SDL_RenderClear(thisRenderer);
		SDL_RenderCopy(thisRenderer, theTexture, NULL, NULL);
		SDL_RenderPresent(thisRenderer);
	}

	//deallocates memory for the texture
	Texture::~Texture() {
		if (theTexture != NULL) {
			SDL_DestroyTexture(theTexture);
		}
		theTexture = NULL;
	}




}
