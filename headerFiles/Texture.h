#ifndef TEXTURE_DOT_H_
#define TEXTURE_DOT_H_

#include <SDL2/SDL.h>
#include <string>

namespace game {

class Texture {
public:
	Texture(const char* filename, SDL_Renderer*& renderer);
	Texture(const Texture& toCopy);
	void Display();
	~Texture();
private:
	SDL_Texture* theTexture;
	SDL_Renderer* thisRenderer;
	std::string filename;
};





}

#endif
