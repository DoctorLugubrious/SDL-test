#ifndef IMAGE_LIBRARY_DOT_H_
#define IMAGE_LIBRARY_DOT_H_
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>
#include "Texture.h"
#include "Renderer.h"
#include "Window.h"

namespace game {

/*The Image Library class contains Textures to display.
 ***Display(string name)
 ***	displays the image with name at 0,0
 ***Display(string, int x, int y)
 ***	displays the image with name at x, y
 ***Display(string, int x, int y, SDL_Rect& area)
 ***	displays the portion of the image specified by area at x, y
 ***DisplayFlipped(string, int x, int y, SDL_Rect& area)
 ***	same as above but flips horizontally
 ***Render()
 ***	needed to clear the screen and display everything at its new position
 ***Background()
 **	Displays the background
 ***DisplayText(string, int x, int y)
 ***	displays the text in string at x,y
 ***SDL_Rect isIn(string name, int x, int y)
 ***	if (x, y) is in the image with name, returns the SDL_Rect of that image.
 ***	else returns {0, 0, 0, 0}
 *with a window and a renderer to display said images
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
