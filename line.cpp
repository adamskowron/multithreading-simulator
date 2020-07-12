#include "line.h"

Line::Lineine()
{
	x=10;
	y=10;
}

Line::run()
{
	//while (check != 'q')
	{
		//linia produkcyjna
		sleep(3);
		
		int r = rand % 100;
		if (r < 25)
		{
			parts.push_back(new part("wood"));
		}
		else if(r <= 25 && r <=50)
		{
			parts.push_back(new part("steel"));
		}
		else if(r <= 25 && r <=50)
		{
			parts.push_back(new part("rubber"));
		}
		else
		{
			parts.push_back(new part("cotton"));
		}
		
		for(auto &e : parts)
		{
			e.y = e.y+1;
			if(e.y > 40) //koniec lini usunac przedmiot
			{
				e.remove();
			}
		}
	}
	
	
}