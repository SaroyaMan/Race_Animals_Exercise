#include <iostream>
#include "competitor.h"
#ifndef turtle
#define turtle
using namespace std;

class Turtle: public Competitor
{
	public:
		Turtle();
		Tile* lookAhead(Tile*** map,Point2D end_p);
		int cheap(Tile* t1, Tile* t2);
		void swim();
		void eat();
		void run();
		void walk();
};

ostream& operator<<(ostream& os, const Turtle& t);

#endif
