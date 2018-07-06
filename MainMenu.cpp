#include <fstream>
#include <sstream>
#include <iostream>

#include <SDL2/SDL.h>

#include "MainMenu.h"
#include "constants.h"

namespace game {
MainMenu::MainMenu(ImageLibrary& images):
	startAnimDone(false),
	frame(0),
	images(images) {
	std::ifstream infile("high_score.txt");
	int high = 0;
	infile >> high;
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
		else if (!this->DisplayButton("START_ANIM")) {
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
		images.Display("OPTIONS_BUTTON_PRESSED", 20, 310);
	}
	else {
		images.Display("OPTIONS_BUTTON", 20, 310);
	}
	if (images.IsIn("QUIT_BUTTON", x, y).h) {
		images.Display("QUIT_BUTTON_PRESSED", 20, 420);
	}
	else {
		images.Display("QUIT_BUTTON", 20, 420);
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
	images.Display("GEAR", 225, 295);
	images.Display("QUIT", 225, 405);
	return STAY;
}

bool MainMenu::DisplayButton(std::string buttonName) {
	static int internalFrame = frame % 10;
	if (startAnimDone) {
		return false;
	}
	internalFrame++;
	if (internalFrame >= 10) {
		internalFrame = 0;
		return false;
	}
	SDL_Rect area = {internalFrame * 130, 0, 130, 130};
	images.Display(buttonName, 225, 185, area);
	return true;
}

}

