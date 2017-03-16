#include "turtle.h"

Turtle::Turtle()
{
	this->name = "Turtle";
}

Tile* Turtle::lookAhead(Tile*** map,Point2D end_p)
{
	Tile *left=0, *right=0, *up=0, *down=0;
	int size=0;
	FileParser file1;
	int rLimit = file1.getRows();
	int cLimit = file1.getColumns();
	Point2D currPoint = this->getCurrentTile()->getPosition();
	if (currPoint.getX() == 0 && currPoint.getY() == 0)	//if the frog is in the left-top corner
	{
		right = map[0][1];
		down = map[1][0];
	}
	else if (currPoint.getX() == 0 && currPoint.getY() == (cLimit-1))	//if the frog is in the right-top corner
	{
		left = map[0][currPoint.getY() - 1];
		down = map[1][currPoint.getY()];	
	}
	else if (currPoint.getX() == (rLimit-1) && currPoint.getY() == 0)	//if the frog is in the left-bottom corner
	{
		right = map[currPoint.getX()][1];
		up = map[currPoint.getX() - 1][0];

	}	
	else if (currPoint.getX() == (rLimit-1) && currPoint.getY() == (cLimit-1))	//if the frog is in the right-bottom corner
	{
		left = map[currPoint.getX()][currPoint.getY() - 1];
		up = map[currPoint.getX() - 1][currPoint.getY()];
	}
	else if (currPoint.getX() == 0)
	{
		left = map[0][currPoint.getY()-1];
		right = map[0][currPoint.getY()+1];
		if (rLimit != 1)
		{
			down = map[1][currPoint.getY()];
		}
	}
	else if (currPoint.getX() == (rLimit-1))
	{
		right = map[currPoint.getX()][currPoint.getY()+1];
		left = map[currPoint.getX()][currPoint.getY()-1];
		if (rLimit != 1)
		{
			up = map[currPoint.getX()-1][currPoint.getY()];
		}
	}
	else if (currPoint.getY() == 0)
	{
		up = map[currPoint.getX()-1][currPoint.getY()];
		down = map[currPoint.getX()+1][currPoint.getY()];
		if (cLimit != 1)
		{
			right = map[currPoint.getX()][currPoint.getY()+1];
		}
	}
	else if (currPoint.getY() == (cLimit-1))
	{
		up = map[currPoint.getX()-1][currPoint.getY()];
		down = map[currPoint.getX()+1][currPoint.getY()];
		if(cLimit != 1)
		{
			left = map[currPoint.getX()][currPoint.getY()-1];
		}
	}
	else
	{
		left = map[currPoint.getX()][currPoint.getY()-1];
		right = map[currPoint.getX()][currPoint.getY()+1];
		up = map[currPoint.getX()-1][currPoint.getY()];
		down = map[currPoint.getX()+1][currPoint.getY()];
	}
	
	int c=0;
	Tile* finalChoice=0;
	int newSize=0, i=0, fSize=0 ,tmp=0, tmp2=0;
	
	 //takes only the tiles that has not been visited.
	if (up != 0)
	{
		if (this->canIMoveThere(up) == false) 
			up = 0;	
	}
	if (down != 0)
	{
		if (this->canIMoveThere(down) == false) 
			down = 0;	
	}
	if (left != 0)
	{
		if (this->canIMoveThere(left) == false) 
			left = 0;	
	}
	if (right != 0)
	{
		if (this->canIMoveThere(right) == false) 
			right = 0;
	}

	
	//if the frog is close to the end.
	if (up != 0)
	{
		if (up->getPosition() == end_p)
		{
			finalChoice = up;
			return finalChoice;
		}			
	}

	if (down != 0)
	{
		if (down->getPosition() == end_p)
		{
			finalChoice = down;
			return finalChoice;
		}			
	}
	if (right != 0)
	{
		if (right->getPosition() == end_p)
		{
			finalChoice = right;
			return finalChoice;
		}			
	}
	if (left != 0)
	{
		if (left->getPosition() == end_p)
		{
			finalChoice = left;
			return finalChoice;
		}			
	}

	
	//takes only the step which makes you closer to the end.
	if (left != 0 && right != 0)
	{
		tmp = (left->getPosition().getY() - end_p.getY() );
		tmp2 = (right->getPosition().getY() - end_p.getY() );
		abso(tmp);	abso(tmp2);
		if (tmp > tmp2)
			left = 0;
		else right = 0;	
	}
	
	if (up != 0 && down != 0)
	{
		tmp = (up->getPosition().getX() - end_p.getX() );
		tmp2 = (down->getPosition().getX() - end_p.getX() );
		abso(tmp);	abso(tmp2);
		if (tmp > tmp2)
			up = 0;
		else down = 0;	
	}
	
	if (up != 0 && right != 0)
	{
		c = cheap(up, right);
		if (c==1) right=0;
		if (c==2) up= 0;
		if (c==0)
		{
			if (this->getCurrentTile()->getPosition().getY() == end_p.getY()) right=0;
			else up=0;
		}
	}
	if (up != 0 && left != 0)
	{
		c = cheap(up, left);
		if (c==1) left=0;
		if (c==2) up= 0;
		if (c==0)
		{
			if (this->getCurrentTile()->getPosition().getY() == end_p.getY()) left=0;
			else up=0;
		}		
	}
	if (down != 0 && right != 0)
	{
		c = cheap(down, right);
		if (c==1) right=0;
		if (c==2) down= 0;
		if (c==0)
		{
			if (this->getCurrentTile()->getPosition().getY() == end_p.getY()) right=0;
			else down=0;
		}				
		
	}
	if (down != 0 && left != 0)
	{
		c = cheap(down, left);
		if (c==1) left=0;
		if (c==2) down= 0;
		if (c==0)
		{
			if (this->getCurrentTile()->getPosition().getY() == end_p.getY()) left=0;
			else down=0;
		}		
		
	}	

	if (up != 0)
		return up;
	else if (down != 0)
		return down;
	else if (left != 0)
		return left;
	else if (right != 0)
		return right;		

}

int Turtle::cheap(Tile* t1, Tile* t2)
{
	float v1=0, v2=0;
	if (t1->getType() == easyTile) v1=0.75;
	if (t1->getType() == normalTile) v1=1;
	if (t1->getType() == cropTile) v1=1;
	if (t1->getType() == waterTile) v1=1;
	
	if (t2->getType() == easyTile) v2=0.75;
	if (t2->getType() == normalTile) v2=1;
	if (t2->getType() == cropTile) v2=1;
	if (t2->getType() == waterTile) v2=1;	
	
	if (v1 < v2)
		return 1;
	else if (v1 > v2) 
		return 2;
	else
		return 0;	
	
}

void Turtle::swim()
{
	this->totalMovementCost+=1;
}

void Turtle::eat()
{
	this->totalMovementCost+=1;
}

void Turtle::run()
{
	this->totalMovementCost+=0.75;
}

void Turtle::walk()
{
	this->totalMovementCost+=1;
}

ostream& operator<<(ostream& os, const Turtle& t)
{
	os<<"Name of the competitor: "<<t.getName()<<endl;
	os<<"Total movement cost of the competitor: "<<t.getTotalMovementCost()<<endl;
	os<<"Current tile of the competitor: ";
	t.getCurrentTile()->whoAmI();
	os<<t.getCurrentTile()->getPosition();
}
