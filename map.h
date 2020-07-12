#pragma once
#include <thread>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "factory.h"
#include "truck.h"
#include "manager.h"
#include "wiz.h"
#include "truck.h"
#include <mutex>

class Map
{
	public:
		int n,w;
		int x,y;
		Manager manager;
		Wiz* wiz;
		
		
		bool isRunning = true;
	
		std::vector<int> cords;
		std::vector<Truck> trucks;
		std::vector<Factory> factories;
		Sawmill *sm;
		std::vector<std::thread> ft;
		

		
		Map() = default;
		Map(int n, int w); //fab work
		void rfresh();
		~Map();
		
		//TODO
		//linia logistyczna pomiedzy fabrykami
};