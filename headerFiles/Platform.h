#ifndef PLATFORM_DOT_H_
#define PLATFORM_DOT_H_

#include "ImageLibrary.h"
#include <string>
namespace game {

	/*
	 * The platform class is a platform you can jump on
	 */

	class Platform {
	public:
		Platform(ImageLibrary*);
		void Display();
		bool IsIn(int, int);
	private:
		int xPos;
		int yPos;
		size_t width;
		size_t height;
		ImageLibrary* sprites;
	};
}
#endif
