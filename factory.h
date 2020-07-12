#pragma once
#include <vector>
#include <thread>
#include "factory.h"
#include "part.h"
#include "line.h"
#include "worker.h"
#include <cstdlib>
#include <mutex>
#include "terminal.h"

class Factory
{
public:
int id;
int w; //pracownicy
//int m; //stanowiska

Terminal terminal;
//std::vector<Worker> workers;
//std::vector<std::thread> threads;
std::mutex *mtx;

	Factory(int countWorkers, int countMachines);
	void run();		
};
