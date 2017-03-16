#include <iostream>
#include "fileparser.h"
#include "easytile.h"
#include "normaltile.h"
#include "croptile.h"
#include "watertile.h"
#include "frog.h"
#include "rabbit.h"
#include "turtle.h"
#ifndef racetrack
#define racetrack
using namespace std;
class RaceTrack
{
	private:
		FileParser file;		//the file - to scan it for the track - done in constructor.
		Point2D start_point;	//represents the start point of the map.
		Point2D end_point;		//represents the end point of the map.
		Tile*** track;			//represents the map of the game.
		Frog c_frog;			//represents the frog.
		Rabbit c_rabbit;		//represents the rabbit.
		Turtle c_turtle;		//represents the turtle.
	public:
		RaceTrack();
		~RaceTrack();
		void startRace();		//starts and finish the race.
		void printMap();		//prints the current status of the map.
		void declareWinner();	//prints the winner, the costs, and the path of each competitor.
		
};
#endif
