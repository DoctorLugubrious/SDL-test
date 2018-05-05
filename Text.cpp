#include "Text.h"
#include "Image.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

using std::cout;
using std::endl;

namespace game {
	/*
	 * The default constructor is necessary for putting the texture in certain
	 * data structures and really shouldn't be called other than that, since
	 * it won't be able to do anything.
	 */
	Text::Text(): 
		theText(NULL), 
		thisRenderer(NULL), 
		contents(""),
		width(0),
		height(0)
 	{}
	
	//parameterized constructor that takes a filename and a renderer to render to
	Text::Text(std::string initContents, SDL_Renderer*& renderer, Font* font):
		theText(NULL),
		thisRenderer(renderer),
		contents(initContents),
		width(0),
		height(0),
		font(font) {
		this->init();
	}

	//copy constructor
	Text::Text(const Text& toCopy):
		theText(NULL),
		thisRenderer(toCopy.thisRenderer),
		contents(toCopy.contents), 
		width(0),
		height(0),
		font(toCopy.font) {
		if (contents != "") {
			this->init();
		}
	}

	//initialize the texture
	void Text::init() {
		//Initialize library
		if (TTF_Init() == -1) {
			std::cout << "SDL_ttf could not initialize! SDL Error: " 
				<< SDL_GetError() << std::endl;
			
		}

		//Load initial surface
		SDL_Surface* textSurface = TTF_RenderText_Solid(*(*font), contents.c_str(), {0, 0, 0}); 
		if (textSurface == NULL) {
			std::cout << "Unable to create text! SDL Error: " 
				<< SDL_GetError() << std::endl;
		}
		//load text
		theText = SDL_CreateTextureFromSurface(thisRenderer, textSurface);
		if (theText == NULL) {	
			std::cout << "Unable to create texture! SDL Error: " 
				<< SDL_GetError() << std::endl;
		}

		width = textSurface->w;
		height = textSurface->h;

		SDL_FreeSurface(textSurface);
		font = NULL;
	}

	
	//displays the texture on the current surface
	void Text::Display(int x, int y) {
		SDL_Rect area = {x, y, width, height};
		SDL_RenderCopy(thisRenderer, theText, NULL, &area);
	}

	//deallocates memory for the texture
	Text::~Text() {
		if (theText != NULL) {
			SDL_DestroyTexture(theText);
		}
		theText = NULL;
		TTF_Quit();
	}

}
