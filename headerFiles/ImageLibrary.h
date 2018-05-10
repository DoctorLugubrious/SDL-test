#ifndef IMAGE_LIBRARY_DOT_H_
#define IMAGE_LIBRARY_DOT_H_
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>
#include "Texture.h"
#include "Renderer.h"
#include "Window.h"

namespace game {

/*
	The Image Library class contains an std::unordered_map of Textures
	with a window and a renderer to display said images
*/
class ImageLibrary {
public:
	ImageLibrary();
	void Display(std::string name);
	void Display(std::string name, int xPos, int yPos);
	void Display(std::string name, int xPos, int yPos, SDL_Rect& area);
	void DisplayFlipped(std::string name, int xPos, int yPos, SDL_Rect& area);
	void Render();
	void Background();
	void DisplayText(std::string text, int xPos, int yPos);
	SDL_Rect IsIn(std::string name, int x, int y);
private:
	std::unordered_map<std::string, Texture> images;
	Window mainWindow;
	Renderer screenRenderer;
};

}

#endif
