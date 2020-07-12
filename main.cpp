#include "map.h"
#include <thread>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <atomic>
#include <mutex>

int main(int argc, char* argv[])
{
	if(argc == 3)
	{
		std::cout<<"poczatek";
		// n fabryki, w pracownicy
		int n = atoi(argv[1]);
		int w = atoi(argv[2]);
		
		// std::mutex* mtx = new std::mutex();
		// mtx->lock();
		// //bool isRunning = true; //warunek zakonczenia programu
		// mtx->unlock();
		
		Map map(n,w);
		
		
		//std::thread mapThread(&Map::run,&map,&isRunning);
		
		//keyThread.join();
		//mapThread.join();
	//	delete mtx;
	}
	else
	{
		std::cout << "zla liczba argumentow\n";
	}
	return 0;
}