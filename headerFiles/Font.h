#ifndef FONT_DOT_H_
#define FONT_DOT_H_
#include <string>

#include <SDL2/SDL_ttf.h>

namespace game {
/*The font class is a ttf font.
 ***Font(const char*, int)
 ***	this constructor needs the filename of a .ttf font and a filesize.
 ***	if the font is not valid, throws a game::GraphicsException.
 ***operator*()
 ***	used for calling SDL functions that reqire a font.
 */
class Font {
public:
	Font(std::string initFilename, int initSize);
	Font(const Font& toCopy); 
	~Font();
	TTF_Font* operator*() {
		return font;
	}
private:
	void init();
	TTF_Font* font;
	int size;
	std::string filename;
};
}

#endif
