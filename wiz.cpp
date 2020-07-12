#include "wiz.h"
#include <iostream>
#include "randgen.h"

 Wiz::Wiz()
 {
	//	initscr(); 
	
 }

Wiz::Wiz( int n,std::vector<Truck> *Trucks, std::vector<Factory> *Factories , Sawmill *sawmill)
{
	
//	initscr(); 
	printw("XXX");
//	mtxMAP = new std::mutex(); //mutexy do okien
//	mtxSM = new std::mutex();
	
	keypad(stdscr,TRUE);
	curs_set(FALSE);
	
	//currmap=Map;
	currmill=sawmill;
	currtrucks=Trucks;
	
	this->n=n;
	
	for(int i = 10; i<30;i++) //punktu do lasu
	{
		 for(int j = 0; j<40;j++)
		{
			 int r = RandinRange(0,100);
			if (r<35)
			 {
				 point p(i,j);
			 forest.push_back(p);
			 }
		 }
	 }
	
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_CYAN);
	init_pair(4, COLOR_RED,COLOR_BLUE);
	init_pair(5, COLOR_BLUE,COLOR_YELLOW);	
	init_pair(6,COLOR_RED,COLOR_YELLOW);
	init_pair(7,COLOR_BLACK,COLOR_GREEN);
	
}

void Wiz::rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void Wiz::showMap(int n,std::vector<Truck>* trucks) //args
{
	
	erase();
	attrset(COLOR_PAIR(2));
	mvprintw(0,0, "Wcisnij t, aby zobaczyc tartak | 1-9 aby zobaczyc fabryki | q KONIEC PROGRAMU");
	
	//wyswitlanie ciezarowek
	// for(int i = 0; i < trucks.size();i++)
	// {
		// if(trucks.at(i).state == trucks.at(i).State::free)
		// {
			// wattrset(MAP,COLOR_PAIR(5));
		// }
		// else if(trucks.at(i).state == trucks.at(i).State::travel)
		// {
			// wattrset(MAP,COLOR_PAIR(6));
		// }
		// else if(trucks.at(i).state == trucks.at(i).State::wood)
		// {
			// wattrset(MAP,COLOR_PAIR(7));
		// }
		// mvwprintw(MAP,trucks.at(i).cy,trucks.at(i).cx,"T");
	// }
	
	//attrset
//	mvwprintw(sw->x,sw->y,std::string("TARTAK").c_str());
//	mvwprintw(sw->x+3,sw->y+1,std::string("press").c_str());
	//mvwprintw(sw->x+4,sw->y+3,std::string("T").c_str());
	//rectangle(sw->x+1,sw->y,sw->x+8,sw->y+7);
	
	refresh();
}

	// void Wiz::generateforest()
	// {
				// for(int i = 10; i<30;i++)
	// {
		 // for(int j = 0; j<40;j++)
		// {
			 // int r = RandinRange(0,100);
			// if (r<35)
			 // {
			 // forest.push_back(point(i,j));
			 // }
		 // }
	 // }
	// }


void Wiz::showMill(Sawmill *currmill)
{
	erase();
	for(point p : forest) //wyswietlenie lasu
	{
		attrset(COLOR_PAIR(2));
		mvaddch(p.x,p.y,'*');
	}
	
	attrset(COLOR_PAIR(6));
	mvprintw(0,COLS,(std::to_string(currmill->hours) + ":" + std::to_string(currmill->minutes)).c_str());
	
	attrset(COLOR_PAIR(7));
	mvprintw(currmill->fb.x,currmill->fb.y,"[]");
	
//	mvprintw(currentSW->truck->cx,currentSW->truck->cy,"[***]");

refresh();
}

void Wiz::showFactory(Factory& f)
{
	//while()
	
	erase();
	
	for(int j = 0; j<f.w;j++)
	{
		for(int i = 0; i < 360; i++)
		{
			int x = (3)*cos(angle*i + angle/(double)2)+LINES/2 + 15*j;
			int y = (5)*sin(angle*i + angle/(double)2)+COLS/2;
  //          mvprintw(factories->at(i).x-10,y-20,":");

		}
	}
	
	refresh();
}

 void Wiz::keyListen(bool isRunning)
 {
	 nodelay(stdscr,TRUE);
	 noecho();
	 char c = 'm';
	 while(isRunning == true)
	 {
		 if(c == 'q') 
		 {		
			// c = getch();
				 isRunning = false;
		 }
		 else if(c == 'm')
		 {
			 while(c != 't' || c != 'q')
			 {
				 c = getch();
				 showMap(n,currtrucks);
			 }
		 }
		 else if(c == 't')
		 {
			 while(c != 'm' || c != 'q')
			 {
			 c = getch();
			 showMill(currmill);
			 }
		 }
			
		// //fabryki todo

		// c = getch();
	 }	
	
 }

Wiz::~Wiz()
{
	curs_set(TRUE);
	endwin();
//	delete mtxMAP;
//	delete mtxSM;
}