#include "ImageLibrary.h"
#include <iostream>
#include <SDL2/SDL_image.h>

using std::cout;
using std::endl;

namespace game {
	const int imageWidth = 64;
	const int imageHeight = 48;
	const int windowWidth = 640;
	const int windowHeight = 480;
	/*
	 * The default constructor loads the window that we will be rendering to and
	 * sets up the std::unordered_map conatining the images needed.
	 * It also displays the background when initialized 
	 */
	ImageLibrary::ImageLibrary(): mainWindow(), screenRenderer(*mainWindow) {
		images["UP"] = Texture("gameSprites/up.png", *screenRenderer, 
			imageWidth, imageHeight);	
		images["DOWN"] = Texture("gameSprites/down.png", *screenRenderer,	
			imageWidth, imageHeight);	
		images["LEFT"] = Texture("gameSprites/left.png", *screenRenderer,	
			imageWidth, imageHeight);	
		images["RIGHT"]= Texture("gameSprites/right.png", *screenRenderer,	
			imageWidth, imageHeight);	
		images["NEUTRAL"]= Texture("gameSprites/neutral.png", *screenRenderer,	
			imageWidth, imageHeight);	
		images["BACKGROUND"] = Texture("gameSprites/TestBackground.png", *screenRenderer, 
			windowWidth, windowHeight);	
	images["BACKGROUND"].Display(0, 0);
	}	

	/*
	 * Displays the image with the given name
	 * Displays default if given name not in library
	 */
	void ImageLibrary::Display(const char* name) {
		if (images.count(name) == 0) {
			name = "BACKGROUND";
		}
		images[name].Display(0,windowHeight - imageHeight);
	}

	void ImageLibrary::Display(const char* name, int xPos, int yPos) {
		if (images.count(name) == 0) {
			name = "NEUTRAL";
		}
		images[name].Display(xPos, (windowHeight - imageHeight) + yPos);
		SDL_RenderPresent(*screenRenderer);
	}

	void ImageLibrary::Background() {
		SDL_RenderClear(*screenRenderer);
		images["BACKGROUND"].Display(0,0);
	}

}
