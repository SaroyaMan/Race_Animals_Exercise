#include "competitor.h"

Competitor::Competitor():allMoves(40)
{
	name = "Competitor";
	totalMovementCost = 0;
	currentTile = NULL;	
	countMoves= 0;
}

void Competitor::moveTo(Tile* t)
{
	allMoves.add(*t);
	this->currentTile = t;
	this->countMoves++;
	t->onEnter(this);
}

void Competitor::fastestWayX(Tile*** map,Point2D start_p, Point2D end_p)
{
	this->moveTo(map[start_p.getX()][start_p.getY()]);
	while (this->getCurrentTile()->getPosition() != end_p)
	{
		while (this->getCurrentTile()->getPosition().getX() != end_p.getX())
		{
			if (this->getCurrentTile()->getPosition().getX() > end_p.getX())
				this->moveTo(map[this->getCurrentTile()->getPosition().getX()-1][this->getCurrentTile()->getPosition().getY()]);
			else
				this->moveTo(map[this->getCurrentTile()->getPosition().getX()+1][this->getCurrentTile()->getPosition().getY()]);	
		}
		while (this->getCurrentTile()->getPosition().getY() != end_p.getY())
		{
			if (this->getCurrentTile()->getPosition().getY() < end_p.getY())
				this->moveTo(map[this->getCurrentTile()->getPosition().getX()][this->getCurrentTile()->getPosition().getY()+1]);
			else
				this->moveTo(map[this->getCurrentTile()->getPosition().getX()][this->getCurrentTile()->getPosition().getY()-1]);		
		}
	}
}

void Competitor::fastestWayY(Tile*** map,Point2D start_p, Point2D end_p)
{
	this->moveTo(map[start_p.getX()][start_p.getY()]);
	while (this->getCurrentTile()->getPosition() != end_p)
	{
		while (this->getCurrentTile()->getPosition().getY() != end_p.getY())
		{
			if (this->getCurrentTile()->getPosition().getY() < end_p.getY())
				this->moveTo(map[this->getCurrentTile()->getPosition().getX()][this->getCurrentTile()->getPosition().getY()+1]);
			else
				this->moveTo(map[this->getCurrentTile()->getPosition().getX()][this->getCurrentTile()->getPosition().getY()-1]);		
		}
		while (this->getCurrentTile()->getPosition().getX() != end_p.getX())
		{
			if (this->getCurrentTile()->getPosition().getX() > end_p.getX())
				this->moveTo(map[this->getCurrentTile()->getPosition().getX()-1][this->getCurrentTile()->getPosition().getY()]);
			else
				this->moveTo(map[this->getCurrentTile()->getPosition().getX()+1][this->getCurrentTile()->getPosition().getY()]);	
		}
	}
}


Competitor::~Competitor()
{
}

bool Competitor::canIMoveThere(Tile* t)
{
	Point2D p = t->getPosition();
	for (int i=0; i<countMoves; i++)
	{
		if (allMoves[i].getPosition() == p ) return false;
	}
	return true;
}


void Competitor::printMoves(Tile*** m, Point2D end)
{
	FileParser f;
	Point2D p;
	char** mapper = f.getMap();
	
	int i=0, j=0,k=0;
	for (i=0; i < f.getRows(); i++)
	{
		for (j=0; j < f.getColumns(); j++)
		{
			p.setX(i);	p.setY(j);
			mapper[i][j] = ' ';
				for (k=0; k < this->countMoves; k++)
				{
					if (p == allMoves[k].getPosition())
					{
						 mapper[i][j] = m[i][j]->getSign();
						break;	
					}

				}
		}
	}
	mapper[end.getX()][end.getY()] = 'E';
	for (i=0; i < f.getRows(); i++)
	{
		for (j=0; j < f.getColumns(); j++)
			cout<<mapper[i][j]<<" ";
		cout<<endl;	
	}
}

ostream& operator<<(ostream& os, const Competitor& c)
{
	os<<"Name of the competitor: "<<c.getName()<<endl;
	os<<"Total movement cost of the competitor: "<<c.getTotalMovementCost()<<endl;
	os<<"Current tile of the competitor: ";
	c.getCurrentTile()->whoAmI();
	os<<c.getCurrentTile()->getPosition();
}
