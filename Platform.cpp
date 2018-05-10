#include "Platform.h"
#include "constants.h"
namespace game {


		Platform::Platform(ImageLibrary* init): 
			xPos(WINDOW_WIDTH/2),
			yPos(WINDOW_HEIGHT/2),
			width(280),
			height(240), 		
			sprites(init) {};
		
		void Platform::Display() {
			sprites->Display("PLATFORM"); 
		}
	
		bool Platform::IsIn(int x, int y) {
			return sprites->IsIn("PLATFORM", x, y);
		}
}

