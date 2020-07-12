#pragma once
#include "lumberjack.h"
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "wiz.h"
#include <condition_variable>
#include "terminal.h"
#include "truck.h"

class Wiz;

struct axe_station
{
	int x,y;
};

struct fuel_barrell
{
	int x,y;
	int capacity = 1000;
};

class Sawmill {
public:
	int minutes, hours;
	int x,y, x_forest,y_forest, frngx, frngy;
	int Lcount;
	axe_station station;
	fuel_barrell fb;
	Terminal terminal;
	Truck *truck;
	std::vector<Lumberjack> house;
	std::vector<Lumberjack> lumberjacks;
	std::vector<std::thread> Lthreads;
	const std::string name = "TARTAK";
	
//	Wiz* wiz;
	
	std::thread timeThread;
	std::thread TruckThread;
	
	std::condition_variable timecv;
	std::mutex timemtx;
	
	Sawmill() = default;
	Sawmill(bool isRunning,int x, int y, int fx, int fy, int Lcount,Wiz& wiz);
	void run();
	void time(bool isRunning,Wiz& wiz);
	~Sawmill();
};