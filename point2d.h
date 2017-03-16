#include <iostream>
#ifndef point2d
#define point2d
using namespace std;

class Point2D			//a class that helps to build the map.
{
	int x, y;
	public:
		Point2D(int _x=0, int _y=0):x(_x), y(_y){};
		void setX(int _x) {x=_x;}
		void setY(int _y) {y=_y;}
		int getX() const {return x;}
		int getY() const {return y;}
		bool operator==(const Point2D& p2);
		bool operator!=(const Point2D& p2);
};

ostream& operator<<(ostream& os, const Point2D& p);
void abso(int& x);

#endif
