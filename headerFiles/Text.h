#ifndef TEXT_DOT_H_
#define TEXT_DOT_H_

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Font.h"

namespace game {
/*The Text class creates some text and can display it on the screen
 ***Text(std::string initContents, SDL_Renderer*& renderer, Font* font)
 ***	creates the text with initContents as text for the renderer in the given font
 ***Display(int x, int y)
 ***	displays the text at x,y
 */
class Text {
public:
	Text();
	Text(std::string initContents, SDL_Renderer*& renderer, Font* font);
	Text(const Text& toCopy);
	void Display(int x, int y);
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
	void init();

 	int width;
	int height;

	SDL_Texture* theText;
	SDL_Renderer* thisRenderer;
	Font* font;

	std::string contents;
};





}

#endif
