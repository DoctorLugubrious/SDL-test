#include "ImageLibrary.h"
#include <string>
namespace game {
	class Character {
	public:
		Character(ImageLibrary* init);
		void MoveRight();
		void MoveLeft();
		void Jump();
		void Idle();
		void Duck();
		void UpdatePosition();
		void Display();
	private:
		int xPos;
		int yPos;
		int xVelocity;
		int yVelocity;
		size_t width;
		size_t height;
		ImageLibrary* sprites;
		std::string currentSprite;
		bool jump;
	};
}
