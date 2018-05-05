#ifndef FONT_DOT_H_
#define FONT_DOT_H_
#include <string>
#include <SDL2/SDL_ttf.h>

namespace game {
	class Font {
	public:
		Font(const char* initFilename, int initSize);
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
