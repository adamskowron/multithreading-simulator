#pragma once
#include <vector>
#include<cmath>
#include <string>
#include <ncurses.h>
#include <mutex>
#include <unistd.h>
#include "factory.h"
#include "lumberjack.h"
#include "worker.h"
#include "part.h"
#include "truck.h"
#include "sawmill.h"
#include <condition_variable>
class map;
class Sawmill;
class factory;
struct fuel_barrell;
struct axe_station;

struct point
	{
		int x,y;
		point(int a,int b)
		{	
			x=a;
			b=y;
		}
	};

class Wiz
{
	
	public:
	Sawmill *currmill;
	std::vector<factory> *factories;
	std::vector<Truck> *currtrucks;
	std::mutex *mtxMAP, *mtxSM ;
	
	int n;
	
	std::condition_variable printcv;
		std::mutex printmtx;
		int screen;
	
 	std::vector<point> forest;


//	WINDOW* mapW; //okno mapy
	std::vector<WINDOW*> facW; // okna fabryk
	const double angle = 2*M_PI/360; 
	Wiz();
	Wiz(int n, std::vector<Truck> *Trucks, std::vector<Factory> *Factories , Sawmill *sawmill); //inicjalizacja okna 
	 void showMap(int n,std::vector<Truck>* trucks ); //rysowanie mapy
	 void showFactory(Factory& f); //rysowanie fabryki 
	// void showMill(int n, int fx, int fy,fuel_barrell fb,axe_station as,std::vector<Lumberjack> lj ,Terminal t,int min,int hrs);
	void showMill(Sawmill *sw);
	void keyListen(bool isRunning); //do watku sluchajacego ???
	void rectangle(int y1, int x1, int y2, int x2);
	~Wiz(); 
};
