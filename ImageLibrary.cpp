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
	const int PLATFORM_WIDTH = 230;
	const int PLATFORM_HEIGHT = 150;
	const int PLATFORM_OFFSET = 50;
		images["BACKGROUND"] = Texture("gameSprites/TestBackground.png", *screenRenderer, 
			{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});	
		images["LUCARIO"] = Texture("gameSprites/lucarioGrid.png", *screenRenderer, {0, 0, 0, 0});
		images["BIDOOF"] = Texture("gameSprites/bidoofGrid.png", *screenRenderer, {0, 0, 0, 0});
		images["PLATFORM"] = Texture("gameSprites/platform.png", *screenRenderer,
			{WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + PLATFORM_OFFSET, PLATFORM_WIDTH, PLATFORM_HEIGHT});	
		images["LOGO"] = Texture("gameSprites/logo.png", *screenRenderer, {0, 0, 495, 200});
		images["START_BUTTON"] = Texture("gameSprites/startButton.png", *screenRenderer, {0, 0, 300, 100});
		images["START_BUTTON_PRESSED"] = Texture("gameSprites/startButtonPressed.png", *screenRenderer, {0, 0, 300, 100});
		images["OPTIONS_BUTTON"] = Texture("gameSprites/optionsButton.png", *screenRenderer, {0, 0, 300, 100});
		images["OPTIONS_BUTTON_PRESSED"] = Texture("gameSprites/optionsButtonPressed.png", *screenRenderer, {0, 0, 300, 100});
		images["QUIT_BUTTON"] = Texture("gameSprites/quitButton.png", *screenRenderer, {0, 0, 300, 100});
		images["QUIT_BUTTON_PRESSED"] = Texture("gameSprites/quitButtonPressed.png", *screenRenderer, {0, 0, 300, 100});
		images["START"] = Texture("gameSprites/play.png", *screenRenderer, {0, 0, 130, 130});
		images["GEAR"] = Texture("gameSprites/gear.png", *screenRenderer, {0, 0, 130, 130});
		images["QUIT"] = Texture("gameSprites/quit.png", *screenRenderer, {0, 0, 130, 130});
		images["START_ANIM"] = Texture("gameSprites/playAnim.png", *screenRenderer, {0, 0, 0, 0});
		images["GEAR_ANIM"] = Texture("gameSprites/gearAnim.png", *screenRenderer, {0, 0, 0, 0});
		images["QUIT_ANIM"] = Texture("gameSprites/quitAnim.png", *screenRenderer, {0, 0, 0, 0});
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


	/*
	* Displays text at the given location
	*/	
	void ImageLibrary::DisplayText(std::string text, int xPos, int yPos) {
		const int FONT_SIZE = 40;
		Font typewriter("fonts/1942.ttf", FONT_SIZE);
		Text test(text, *screenRenderer, &typewriter);
		test.Display(xPos, yPos);
	}
	
	/*returns true if the given point is in the given object
	*/
	SDL_Rect ImageLibrary::IsIn(std::string name, int x, int y) {
		if (images.count(name) == 0) {
			name = "PLATFORM";
		}
		return images[name].IsIn(x,y);		
	}

}
