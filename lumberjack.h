#pragma once
#include <string>
#include "truck.h"


class Lumberjack {
	
public:
	int x,y;
	int id;
	int speed;
	int health;
	//Truck truck; 
//	bool hasAxe = false;
	
	Lumberjack() = default;
	Lumberjack(int id, int x, int y, Truck truck);
	bool move(int x, int y);
	void run(bool isRunning);
};