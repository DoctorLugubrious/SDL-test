#include "ImageLibrary.h"
#include "constants.h"
#include <iostream>
#include <SDL2/SDL_image.h>

using std::cout;
using std::endl;

namespace game {
	/*
	 * The default constructor loads the window that we will be rendering to and
	 * sets up the std::unordered_map conatining the images needed.
	 * It also displays the background when initialized 
	 */
	ImageLibrary::ImageLibrary(): mainWindow(), screenRenderer(*mainWindow) {
		images["UP"] = Texture("gameSprites/up.png", *screenRenderer, 
			IMAGE_WIDTH, IMAGE_HEIGHT);	
		images["DOWN"] = Texture("gameSprites/down.png", *screenRenderer,	
			IMAGE_WIDTH, IMAGE_HEIGHT);	
		images["LEFT"] = Texture("gameSprites/left.png", *screenRenderer,	
			IMAGE_WIDTH, IMAGE_HEIGHT);	
		images["RIGHT"]= Texture("gameSprites/right.png", *screenRenderer,	
			IMAGE_WIDTH, IMAGE_HEIGHT);	
		images["NEUTRAL"]= Texture("gameSprites/neutral.png", *screenRenderer,	
			IMAGE_WIDTH, IMAGE_HEIGHT);	
		images["BACKGROUND"] = Texture("gameSprites/TestBackground.png", *screenRenderer, 
			WINDOW_WIDTH, WINDOW_HEIGHT);	
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
		images[name].Display(0,WINDOW_HEIGHT - IMAGE_HEIGHT);
	}

	/*
	 * Displays the image with the given name at the
	 * location given (xPos, yPos)
	 */
	void ImageLibrary::Display(const char* name, int xPos, int yPos) {
		if (images.count(name) == 0) {
			name = "NEUTRAL";
		}
		images[name].Display(xPos, (WINDOW_HEIGHT - IMAGE_HEIGHT) + yPos);
	}

	/*
	 * Displays the background
	 */
	void ImageLibrary::Background() {
		SDL_RenderClear(*screenRenderer);
		images["BACKGROUND"].Display(0,0);
	}

	/*
	 * This takes everything that the renderer has displayed on it and	
	 * sends it to the screen
	 */
	void ImageLibrary::Render() {
		SDL_RenderPresent(*screenRenderer);
	}

}
