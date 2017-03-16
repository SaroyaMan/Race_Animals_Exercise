#include <iostream>
#include "racetrack.h"
using namespace std;

//All rights reserved to ®Yoav Saroya - 304835887

int main(int argc, char** argv)
{
	RaceTrack r;				//a declaration of the RaceTrack.
	r.startRace();				// The race is start & finish.
	r.declareWinner();			//prints the result of the race.
	return 0;
}
