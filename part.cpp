#include "part.h"

Part::Part(std::string n)
{
	name = n;
	mtx = new std::mutex();
}