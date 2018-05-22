#ifndef RENDERER_DOT_H_
#define RENDERER_DOT_H_
#include <SDL2/SDL.h>

/*Wrapper class for SDL_Renderer* for ease of use in rendering images to the screen
 ***Renderer(SDL_Window*&)
 ***	constructs the renderer for the given window
 */

namespace game {
class Renderer {
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
private:
	void init();
	
	SDL_Renderer* theRenderer;
	SDL_Window*& window;
};

}

#endif
