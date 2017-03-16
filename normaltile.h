#include <iostream>
#include "tile.h"
#include "competitor.h"
#ifndef normaltile
#define normaltile
using namespace std;

class NormalTile: public Tile
{
	public:
		NormalTile(Point2D p): Tile(p){sign = '#';}
		void whoAmI(){cout<<"Its a Normal-Tile ('#')\n";}
		void onEnter(Competitor* c)  {c->walk(); }		
		tileKind getType() {return normalTile;}
};

#endif
