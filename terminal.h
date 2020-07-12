#pragma once
#include <condition_variable>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include "truck.h"

class Terminal {
	public:
	std::string state;
	int x,y;
	
	Terminal() = default;
	Terminal(int x, int y);
	void run(std::vector<Truck> trucks);
	
};