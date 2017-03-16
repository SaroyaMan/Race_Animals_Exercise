#include <iostream>
#include "tile.h"
#include "competitor.h"
#ifndef croptile
#define croptile
using namespace std;

class CropTile: public Tile
{
	public:
		CropTile(Point2D p): Tile(p){sign = 'v';}
		void whoAmI(){cout<<"Its a Crop-Tile ('v')\n";}
		void onEnter(Competitor* c)  {c->eat(); }
		tileKind getType() {return cropTile;}
};

#endif
