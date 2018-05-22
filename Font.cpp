#include "Font.h"
#include "Exceptions.h"
#include <string>
#include <iostream>
namespace game {
		//Initializes the font
		Font::Font(std::string initFilename, int initSize):
			font(NULL),
			size(initSize),
			filename(initFilename) {
			this->init();
		}

		//Copy constructor to initialize the font
		Font::Font(const Font& toCopy): 
			font(NULL),
			size(toCopy.size),
			filename(toCopy.filename) {
			this->init();
		}

		//opens the font
		void Font::init() {
                	font = TTF_OpenFont(filename.c_str(), size);
			if (font == NULL) {
				std::string error = "Could not load font! SDL Error: ";
				error += SDL_GetError();
				throw(GraphicsException(error));
			}
		}
		//Prevents memory leaks
		Font::~Font() {
			TTF_CloseFont(font);
			font = NULL;
		}
}

