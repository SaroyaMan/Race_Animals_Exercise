#ifndef tile
#define tile
#include <iostream>
#include "point2d.h"
#include "competitor.h"

typedef enum tileKind{defaultTile ,easyTile, normalTile, cropTile, waterTile}tileKind;
						//enum which represents the kind of the tile.
class Competitor;
class Tile
{
	protected:
		Point2D position;
		char sign;
	public:
		Tile(): sign('S') {};
		Tile(Point2D p): position(p), sign('S') {};
		virtual void onEnter(Competitor* c) {};	
		virtual void whoAmI(){cout<<"Its a Default-Tile\n";}
		virtual tileKind getType() {return defaultTile;}			
		Point2D getPosition(){return position;}
		char getSign(){return sign;}
};
#endif
