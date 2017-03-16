#include <iostream>
#include "tile.h"
#include "competitor.h"
#ifndef watertile
#define watertile
using namespace std;

class WaterTile: public Tile
{
	public:
		WaterTile(Point2D p): Tile(p){sign = '~';}
		void whoAmI(){cout<<"Its a Water-Tile ('~')\n";}
		void onEnter(Competitor* c)  {c->swim(); }
		tileKind getType() {return waterTile;}
};

#endif
