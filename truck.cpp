#include "truck.h"

Truck::Truck(std::string n,int id,int x, int y)
{
	this->id = id;
	cx = x;
	cy = y;
	name = n;
	state = ready;
}

Truck::Truck(int x, int y)
{
	cx = x;
	cy = y;
}

bool Truck::move(int x, int y)
{
	while(cy != y || cx != x)
	{
		usleep(100000);
		if(cy< y)
		{
			cy++;
		}
		if(cy > y)
		{
			cy--;
		}
	
		if(cx< x)
		{
			cx++;
		}
		if(cx > x)
		{
			cx--;
		}

	}
	return true;
}

Truck& Truck::operator=(const Truck& other) // copy assignment
{
    if (this != &other) { // self-assignment check expected
			cx = other.cx;
			cy=other.cy;
        } 
    return *this;
}

void Truck::run(Manager& man, bool isRunning)
{
	int i =0;
}

void Truck::SWrun(bool isRunning)
{
	while(isRunning)
	{
		usleep(10000);
		move(10,0);
	}
}