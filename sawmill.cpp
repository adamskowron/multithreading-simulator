#include "sawmill.h"

Sawmill::Sawmill(bool isRunning,int x, int y, int fx, int fy, int Lcount,Wiz& wiz)
{
	this->x=60;
	this->y=20;

	minutes= 0;
	hours = 5;
	
	std::thread t(&Sawmill::time,this,std::ref(isRunning),std::ref(wiz));
	t.join();
	x_forest = 10;
	y_forest = 0;
	frngx = x+20;
	frngy = y+40;
	
	fb.x=40;
	fb.y=150;
	
	truck = new Truck(LINES,COLS);
	
	for(int i = 0;i<Lcount;i++)
	{
		Lumberjack* j = new Lumberjack(i,30+i,140,*truck);
		lumberjacks.push_back(*j);
		std::thread thr(&Lumberjack::run,lumberjacks.at(i),&isRunning); //ok?

		Lthreads.push_back(std::move(thr));
		
	}
	
	//	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	//truck->move(0,0);
	
//	truck = new Truck(20,40);
	//truck -> move(50, 50);
	//tt= std::thread(&Truck::SWrun,truck,std::ref(isRunning));
	
}

void Sawmill::time(bool isRunning, Wiz& wiz) {
    while(isRunning) {
        std::this_thread::sleep_for (std::chrono::milliseconds(500));
        minutes++;
        minutes = minutes%60;

        if (minutes==0) {
            hours++;
        }
	
        
       
    }
}

void Sawmill::run()
{
	
}

Sawmill::~Sawmill()
{
			for(auto &a : Lthreads)
	{
		a.join();
	}
}