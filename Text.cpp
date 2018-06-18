#include "Text.h"
#include "Image.h"
#include "Exceptions.h"
#include "constants.h"

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
		width(0),
		height(0),
		theText(NULL), 
		thisRenderer(NULL), 
		font (NULL),
		contents("") {}
	
	//parameterized constructor that takes a filename and a renderer to render to
	Text::Text(std::string initContents, SDL_Renderer*& renderer, Font* font):
		width(0),
		height(0),
		theText(NULL),
		thisRenderer(renderer),
		font(font),
		contents(initContents) {
		this->init();
	}

	//copy constructor
	Text::Text(const Text& toCopy):
		width(0),
		height(0),
		theText(NULL),
		thisRenderer(toCopy.thisRenderer),
		font(toCopy.font),
		contents(toCopy.contents) {
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
			std::string error = "Unable to create text! SDL Error: "; 
			error += SDL_GetError();
			throw(GraphicsException(error));
		}
		//load text
		theText = SDL_CreateTextureFromSurface(thisRenderer, textSurface);
		if (theText == NULL) {	
			std::string error = "Unable to create texture! SDL Error: "; 
			error += SDL_GetError();
			throw(GraphicsException(error));
		}

		width = textSurface->w;
		height = textSurface->h;

		SDL_FreeSurface(textSurface);
		font = NULL;
	}

	
	//displays the texture on the current surface
	void Text::Display(int x, int y) {
		SDL_Rect area = {x, y, width, height};
		if (x < 0) { area.x = 0; }
		else if (x + area.w > WINDOW_WIDTH) { area.x = WINDOW_WIDTH - area.w; }
		if (y < 0) { area.y = 0; }
		else if (y + area.h > WINDOW_HEIGHT) { area.y = WINDOW_HEIGHT - area.h; }
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
