#include "point2d.h"

bool Point2D::operator==(const Point2D& p2)
{
	if (this->getX() == p2.getX() && this->getY() == p2.getY()) return true;
	return false;
	
}


bool Point2D::operator!=(const Point2D& p2)
{
	if (this->getX() == p2.getX() && this->getY() == p2.getY()) return false;
	return true;	
}

ostream& operator<<(ostream& os, const Point2D& p)
{
	os<<"["<<p.getX()<<"] ["<<p.getY()<<"]";
	return os;
}

void abso(int& x)
{
	if (x < 0 ) x=-x;
}

