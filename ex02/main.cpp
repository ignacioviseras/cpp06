#include "Includes.hpp"

int main()
{
	Base* obj = generate();
	
	std::cout << "identify use ptr: ";
	identify(obj);

	
	std::cout << "identify use ref: ";
	identify(*obj);
	delete obj;
	return 0;
}
