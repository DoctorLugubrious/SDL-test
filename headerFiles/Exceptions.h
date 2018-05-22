#ifndef EXCEPTIONS_DOT_H_
#define EXCEPTIONS_DOT_H_
#include <string>
namespace game {
	/* The GraphicsException struct contains an error message. It is to be thrown when some graphics error occurs.
	*/
	struct GraphicsException {
		GraphicsException(std::string initError):
			error(initError) 
				{};
		std::string error;
	};
}

#endif

