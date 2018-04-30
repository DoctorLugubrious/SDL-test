#ifndef TEXTURE_DOT_H_
#define TEXTURE_DOT_H_

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
namespace game {
	//The Texture class contains an underlying SDL_Texture and a way to display it.
class Texture {
public:
	Texture();
	Texture(const char* filename, SDL_Renderer*& renderer, size_t width, size_t height);
	Texture(const Texture& toCopy);
	void Display(int xPos, int yPos);
	void Display(int xPos, int yPos, SDL_Rect& area);
	void DisplayFlipped(int xPos, int yPos, SDL_Rect& area);
	void init(const char* filename);
	void operator=(const Texture& toCopy) {
		thisRenderer = toCopy.thisRenderer;
		theTexture = NULL;
		filename = toCopy.filename;
		xSize = toCopy.xSize;
		ySize = toCopy.ySize;
		if (filename != "") {
			this->init(toCopy.filename.c_str());
		}
	}
	~Texture();
private:
	SDL_Texture* theTexture;
	SDL_Renderer* thisRenderer;
	std::string filename;
	int xSize;
	int ySize;
};





}

#endif
