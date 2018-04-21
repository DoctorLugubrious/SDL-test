#include "ImageLibrary.h"

namespace game {
	class Character {
	public:
		Character(ImageLibrary* init);
		void MoveRight();
		void MoveLeft();
		void Jump();
		void Idle();
		void Duck();
	private:
		int xPos;
		int yPos;
		size_t width;
		size_t height;
		ImageLibrary* sprites;
	};
}
