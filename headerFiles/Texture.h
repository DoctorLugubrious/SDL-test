#ifndef TEXTURE_DOT_H_
#define TEXTURE_DOT_H_

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
namespace game {
/*The Texture class allows hardware accelarated displaying of PNG images.
 ***Texture()
 ***	in general, should not be called. Necessary for convient insertion into std::unordered_map and the like.
 ***Texture(std::string filename, SDL_Renderer*& renderer, SDL_Rect location);
 ***	filename is the location and name of the file to be loaded. Location is where it will display by default.
 ***	It needs a renderer to display on to function.
 ***UpdatePosition(int x,int y)
 ***	updates the x and y position that the texture will display on by default.
 ***Display()
 ***	Displays at the default location as specified above.
 ***Display(SDl_Rect& area) 
 ***	Displays the area of the image specified by the parameter.
 ***DisplayFlipped(SDL_Rect& area)
 ***	same as ave but flips the image horizontally
 ***IsIn(x, y)
 ***	if (x,y) is in the current position, returns the SDL_Rect. Otherwise, returns 
 ***	{0, 0, 0, 0}.
 */

class Texture {
public:
	Texture();
	Texture(std::string filename, SDL_Renderer*& renderer, SDL_Rect location);
	Texture(const Texture& toCopy);
	void Display();
	void Display(SDL_Rect& area);
	void UpdatePosition(int x, int y);
	void DisplayFlipped(SDL_Rect& area);
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
	void init(const char* filename);

	int xSize;
	int ySize;
	int xPos;
	int yPos;

	SDL_Texture* theTexture;
	SDL_Renderer* thisRenderer;

	std::string filename;
};





}

#endif
