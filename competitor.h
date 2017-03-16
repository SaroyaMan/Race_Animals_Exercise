#ifndef competitor_h
#define competitor_h
#include <iostream>
#include <string>
#include "tile.h"
#include "fileparser.h"
#include "listtype.h"
using namespace std;
class Tile;

class Competitor
{
	protected:
		string name;				//name of the competitor.
		Tile* currentTile;			//the current Tile that the competitor stands on.
		float totalMovementCost;	//the cost of the steps.
		listType<Tile> allMoves;	//a list of the moves.
		int countMoves;				//helps to know the size of the list (allMoves).
	public:
		Competitor();
		virtual Tile* lookAhead(Tile*** map,Point2D end_p) {};	//helps to the competitor which way tile to choose.
		void fastestWayX(Tile*** map, Point2D start_p, Point2D end_p);	//go all the way through the map to the end.
		void fastestWayY(Tile*** map, Point2D start_p, Point2D end_p);	//go all the way through the map to the end.
		void moveTo(Tile* t);						//move the competitor to the tile the method gets.
		virtual void swim() {};			//increase the cost of the competitor.
		virtual void eat() {};			//increase the cost of the competitor.
		virtual void run() {};			//increase the cost of the competitor.
		virtual void walk() {};			//increase the cost of the competitor.
		~Competitor();
		bool canIMoveThere(Tile* t);	//check if the competitor visited the tile or not.
		string getName() const {return name;}
		Tile* getCurrentTile() const {return currentTile;}
		int getCountMoves() const {return countMoves;}
		float getTotalMovementCost() const {return totalMovementCost;}
		listType<Tile> getAllMoves() const {return allMoves;}
		void printMoves(Tile*** m,Point2D end);			//print all the way the competitor did.
};

ostream& operator<<(ostream& os, const Competitor& c);

#endif
