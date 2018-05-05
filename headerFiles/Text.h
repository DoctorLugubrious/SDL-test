#ifndef TEXT_DOT_H_
#define TEXT_DOT_H_

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Font.h"

namespace game {
	//The Text class contains an underlying SDL_Texture and a way to display it.
class Text {
public:
	Text();
	Text(std::string initContents, SDL_Renderer*& renderer, Font* font);
	Text(const Text& toCopy);
	void Display(int x, int y);
	void init();
	void operator=(const Text& toCopy) {
		thisRenderer = toCopy.thisRenderer;
		theText = NULL;
		contents = toCopy.contents;
		font = toCopy.font;
		if (contents != "") {
			this->init();
		}
	}
	~Text();
private:
	SDL_Texture* theText;
	SDL_Renderer* thisRenderer;
	std::string contents;
	int width;
	int height;
	Font* font;
};





}

#endif
