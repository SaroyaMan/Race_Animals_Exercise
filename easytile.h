#include <iostream>
#include "tile.h"
#include "competitor.h"
#ifndef easytile
#define easytile
using namespace std;

class EasyTile: public Tile
{
	public:
		EasyTile(Point2D p): Tile(p){sign = '=';}
		void whoAmI(){cout<<"Its an Easy-Tile ('=')\n";}
		void onEnter(Competitor* c) {c->run(); }
		tileKind getType() {return easyTile;}
};

#endif
