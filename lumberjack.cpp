#include "lumberjack.h"

Lumberjack::Lumberjack(int x, int y, int speed,Truck truck)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
//	this->truck = truck;
}

void Lumberjack::run(bool isRunning)
{
	// while(isRunning)
	// {
		// move(truck.cx,truck.cy); //dojscie do punktu ciezarowki 
	// }
}


bool Lumberjack::move(int x, int y)
{
	while(this->y != y || this->x != x)
	{
		usleep(100000);
		if(this->y< y)
		{
			this->y++;
		}
		if(this->y > y)
		{
			this->y--;
		}
	
		if(this->x< x)
		{
			this->x++;
		}
		if(this->x > x)
		{
			this->x--;
		}

	}
	return true;
}