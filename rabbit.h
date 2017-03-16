#include <iostream>
#include "competitor.h"
#ifndef rabbit
#define rabbit
using namespace std;

class Rabbit: public Competitor
{
	public:
		Rabbit();
		Tile* lookAhead(Tile*** map,Point2D end_p); 
		int cheap(Tile* t1, Tile* t2);
		void swim();
		void eat();
		void run();
		void walk();
};

ostream& operator<<(ostream& os, const Rabbit& r);

#endif
