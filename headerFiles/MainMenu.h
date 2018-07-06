#ifndef MAIN_MENU_DOT_H_
#define MAIN_MENU_DOT_H_
#include <string>

#include "ImageLibrary.h"

namespace game {
/*The Main menu class runs the main menu.
 ***MenuState Render();
 ***	Displays and runs the main menu. returns the state that the game should be in.
 */
enum MenuState {STAY, START, QUIT};

class MainMenu {
public:
	MainMenu(ImageLibrary& images);
	MenuState Render();
private:
	bool DisplayButton(std::string name);
	bool startAnimDone;
	int frame;
	std::string highScore;
	ImageLibrary& images;
};



}

#endif
