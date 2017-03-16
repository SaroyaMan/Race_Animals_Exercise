#include <iostream>
#include "competitor.h"
#ifndef frog
#define frog

using namespace std;

class Frog: public Competitor
{
	public:
		Frog();
		Tile* lookAhead(Tile*** map, Point2D end_p); 
		int cheap(Tile* t1, Tile* t2);
		void swim();
		void eat();
		void run();
		void walk();
};

ostream& operator<<(ostream& os, const Frog& f);

#endif
