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
	void Display(const char* name);
	void Display(const char* name, int xPos, int yPos);
	void Display(const char* name, int xPos, int yPos, SDL_Rect& area);
	void DisplayFlipped(const char* name, int xPos, int yPos, SDL_Rect& area);
	void Render();
	void Background();
private:
	std::unordered_map<std::string, Texture> images;
	Window mainWindow;
	Renderer screenRenderer;
};

}

#endif
