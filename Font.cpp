#include "Font.h"
#include <string>
#include <iostream>
namespace game {
		Font::Font(const char* initFilename, int initSize):
			font(NULL),
			size(initSize),
			filename(initFilename) {
			this->init();
		}
		Font::Font(const Font& toCopy): 
			font(NULL),
			size(toCopy.size),
			filename(toCopy.filename) {
			this->init();
		}
		void Font::init() {
                	font = TTF_OpenFont(filename.c_str(), size);
			if (font == NULL) {
				std::cout << "Could not load font! SDL Error: "
					<< SDL_GetError() << std::endl;
			}
		}
		Font::~Font() {
			TTF_CloseFont(font);
			font = NULL;
		}
}

