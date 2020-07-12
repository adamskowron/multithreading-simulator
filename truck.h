#pragma once
#include <string>
#include <vector>
#include <unistd.h>
#include "part.h"
#include "worker.h"
#include "manager.h"

enum State
	{
		ready, travel, wood
	};

class Truck {
public:
	int id;
	int cx,cy;
	int progress = 0;
	
	State state;
	std::string name;
	std::vector<Part> parts;
	std::vector<Worker> workers;
	
	Truck() = default;
	Truck(std::string name,int id, int x, int y);
	Truck(int x, int y);
	Truck& operator=(const Truck& other) ;
	bool move(int x, int y);
	void run(Manager& man ,bool isRunning);
	
	void SWrun(bool isRunning);
};