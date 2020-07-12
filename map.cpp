#include "map.h"
#include <iostream>


Map::Map(int n, int w)
{
		std::cout<<"6";
	//n - ilosc fabryk | w - ilosc pracownikow
	this->n = n;
	this->w = w;
	//manager = new Manager();
	x = 0;
	y = 0;
	
	for(int i = 0; i < n; i++) // tworzenie watkow fabryk
	{
			factories.push_back(Factory(n,w));
//			std::thread f(&Factory::run,std::ref(factories.at(i)));
	//		this -> ft.push_back(std::move(f));
	}
		std::cout<<"1";
		for(int i = 0; i<n;i++) //ciezarowki do fabryk
	{
			trucks.push_back(Truck("ciezarowka" + std::to_string(i),i,35+i,5));
		//	std::thread t(&Truck::run,&trucks.at(i),std::ref(this->manager),std::ref(isRunning));
			//this -> ft.push_back(std::move(t));
	}
		sm=new Sawmill(&isRunning,10, 10, 10, 10, 6,*wiz); //tartak
std::cout<<"2";
//const std::vector<Truck> &Trucks, const std::vector<Factory> &Factories ,const Sawmill *sawmill
		wiz = new Wiz(n,&trucks,&factories,sm);
	
		std::thread keyThread(&Wiz::keyListen, std::ref(wiz) ,std::ref(isRunning)); //sluchanie klawisza
		this -> ft.push_back(std::move(keyThread)); 
	
}

Map::~Map()
{
	for(auto &elem : ft)
        {
               elem.join();
        }
		delete wiz;
		delete sm;
}

// void Map::run()
// {
			// trucks.at(0).move(20,20);

	// //while(isRunning == true)
	// //{
	
	// //}
// }