#pragma once
#include <mutex>
#include <string>
#include <stdlib.h>

class Part
{
	public:
	std::string name;
	int x,y;
	std::mutex *mtx;
	
	Part(std::string n);
};