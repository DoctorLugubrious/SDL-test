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
	Texture(const char* filename, SDL_Renderer*& renderer, SDL_Rect location);
	Texture(const Texture& toCopy);
	void Display();
	void Display(SDL_Rect& area);
	void UpdatePosition(int x, int y);
	void DisplayFlipped(SDL_Rect& area);
	void init(const char* filename);
	SDL_Rect IsIn(int x, int y);
	void operator=(const Texture& toCopy) {
		thisRenderer = toCopy.thisRenderer;
		theTexture = NULL;
		filename = toCopy.filename;
		xSize = toCopy.xSize;
		ySize = toCopy.ySize;
		xPos = toCopy.xPos;
		yPos = toCopy.yPos;
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
	int xPos;
	int yPos;
};





}

#endif
