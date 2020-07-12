#pragma once
#include <vector>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "part.h"

class Line
{
public:
	
	static const int x = 10;
	static const int y = 10;
	static char check;
	std::vector<Part> parts;
	
	Line();
	void run();
};