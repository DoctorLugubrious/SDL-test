#include "ImageLibrary.h"
#include "constants.h"
#include "Text.h"
#include "Font.h"
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
		images["BACKGROUND"] = Texture("gameSprites/TestBackground.png", *screenRenderer, 
			{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});	
		images["LUCARIO"] = Texture("gameSprites/lucarioGrid.png", *screenRenderer, {0, 0, 0, 0});
		images["PLATFORM"] = Texture("gameSprites/platform.png", *screenRenderer, {WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 280, 240});	
	}	

	/*
	 * Displays the image with the given name
	 * Displays default if given name not in library
	 */
	void ImageLibrary::Display(std::string name) {
		if (images.count(name) == 0) {
			name = "BACKGROUND";
		}
		images[name].Display();
	}

	/*
	 * Displays the image with the given name at the
	 * location given (xPos, yPos)
	 */
	void ImageLibrary::Display(std::string name, int xPos, int yPos) {
		if (images.count(name) == 0) {
			name = "NEUTRAL";
		}	
		images[name].UpdatePosition(xPos, yPos);
		images[name].Display();
	}

	/*
	 * Displays the image with the given name at the
	 * location given (xPos, yPos)
	 */
	void ImageLibrary::Display(std::string name, int xPos, int yPos, SDL_Rect& area) {
		if (images.count(name) == 0) {
			name = "LUCARIO";
		}
		this->DisplayText("Player 1", xPos, yPos - SPRITE_HEIGHT); 
		images[name].UpdatePosition(xPos, yPos);
		images[name].Display(area);
	}
	/*
	 * Displays the image with the given name at the
	 * location given (xPos, yPos)
	 */
	void ImageLibrary::DisplayFlipped(std::string name, int xPos, int yPos, SDL_Rect& area) {
		if (images.count(name) == 0) {
			name = "LUCARIO";
		}	
		this->DisplayText("Player 1", xPos, yPos - SPRITE_HEIGHT); 
		images[name].UpdatePosition(xPos, yPos);
		images[name].DisplayFlipped(area);
	}
	/*
	 * Displays the background
	 */
	void ImageLibrary::Background() {
		SDL_RenderClear(*screenRenderer);
		images["BACKGROUND"].Display();
	}

	/*
	 * This takes everything that the renderer has displayed on it and	
	 * sends it to the screen
	 */
	void ImageLibrary::Render() {
		SDL_RenderPresent(*screenRenderer);
	}
	
	void ImageLibrary::DisplayText(std::string text, int xPos, int yPos) {
		Font typewriter("fonts/1942.ttf", 40);
		Text test(text, *screenRenderer, &typewriter);
		test.Display(xPos, yPos);
	}
	
	SDL_Rect ImageLibrary::IsIn(std::string name, int x, int y) {
		if (images.count(name) == 0) {
			name = "PLATFORM";
		}
		return images[name].IsIn(x,y);		
	}

}
