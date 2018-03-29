#ifndef RENDERER_DOT_H_
#define RENDERER_DOT_H_
#include <SDL2/SDL.h>

/*
Wrapper class for SDL_Renderer* for ease of use in rendering images to the screen
*/

namespace game {
	class Renderer {
	private:
		SDL_Renderer* theRenderer;
		SDL_Window*& window;
		void init();	
	public:
		Renderer(const Renderer&);
		Renderer(SDL_Window*&);
		~Renderer();
		SDL_Renderer*& operator*() { return theRenderer; };
		//copy assignment operator
		void operator=(const Renderer& toCopy) {
			theRenderer = NULL;
			window = NULL;
			this->window = toCopy.window;
			this->init();
		 };
	};

}

#endif
