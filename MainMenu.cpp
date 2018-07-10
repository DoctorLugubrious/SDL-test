#include <fstream>
#include <sstream>
#include <iostream>

#include <SDL2/SDL.h>

#include "MainMenu.h"
#include "constants.h"

using std::ios;

namespace game {
MainMenu::MainMenu(ImageLibrary& images):
	startAnimDone(false),
	gearAnimDone(false),
	quitAnimDone(false),
	frame(0),
	images(images) {
	std::ifstream infile("high_score.txt", ios::in | ios::binary);
	int high = 0;
	infile.read((char*)&high, sizeof(int));
	highScore = "Current high score: " + std::to_string(high);
};

MenuState MainMenu::Render() {
	++frame;
	SDL_Event event;
	images.Display("LOGO", 300, 20);
	images.DisplayText(highScore, 40, 530);
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (images.IsIn("START_BUTTON", x, y).h) {
		images.Display("START_BUTTON_PRESSED", 20, 200);
		if (startAnimDone) {
			images.Display("START", 225, 185);
		}
		else if (!this->DisplayButton("START_ANIM", 225, 185)) {
			startAnimDone = true;
			images.Display("START", 225, 185);
		}
	}
	else {
		startAnimDone = false;
		images.Display("START_BUTTON", 20, 200);
		images.Display("START", 225, 185);
	}
	if (images.IsIn("OPTIONS_BUTTON", x, y).h) {
		images.Display("OPTIONS_BUTTON_PRESSED", 20, 330);
		if (gearAnimDone) {
			images.Display("GEAR", 225, 315);
		}
		else if (!this->DisplayButton("GEAR_ANIM", 225, 315)) {
			gearAnimDone = true;
			images.Display("GEAR", 225, 315);
		}
	}
	else {
		gearAnimDone = false;
		images.Display("OPTIONS_BUTTON", 20, 330);
		images.Display("GEAR", 225, 315);
	}
	if (images.IsIn("QUIT_BUTTON", x, y).h) {
		images.Display("QUIT_BUTTON_PRESSED", 20, 460);
		if (quitAnimDone) {
			images.Display("QUIT", 225, 445);
		}
		else if (!this->DisplayButton("QUIT_ANIM", 224, 445)) {
			quitAnimDone = true;
			images.Display("QUIT", 225, 445);
		}
	}
	else {
		quitAnimDone = false;
		images.Display("QUIT_BUTTON", 20, 460);
		images.Display("QUIT", 225, 445);
	}
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			return QUIT;
		}
		else if (event.type == SDL_KEYDOWN) {
			return START;
		}
		else if  (event.type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (images.IsIn("START_BUTTON", x, y).h) {
				return START;
			}
			if (images.IsIn("OPTIONS_BUTTON", x, y).h) {
				std::cout << "OPTIONS NOT IMPLEMENTED" << std::endl;
			}
			if (images.IsIn("QUIT_BUTTON", x, y).h) {
				return QUIT;
			}
		}
		else /*if (event.type == SDL_MOUSEMOTION)*/ {
		}
	}
	return STAY;
}

bool MainMenu::DisplayButton(std::string buttonName, int x, int y) {
	static int internalFrame = frame % 10;
	if (startAnimDone) {
		return false;
	}
	internalFrame++;
	if (internalFrame >= 30) {
		internalFrame = 0;
		return false;
	}
	SDL_Rect area = {(internalFrame / 3)* 130, 0, 130, 130};
	images.Display(buttonName, x, y, area);
	return true;
}

}

