#include "racetrack.h"

RaceTrack::RaceTrack()
{
	Point2D p;
	int x = file.getRows();
	int y = file.getColumns();
	char** matrixMap = file.getMap();
	track = new Tile**[x];
	for (int q=0; q<x; q++)
		track[q] = new Tile*[y];
	int i=0, j=0;
	for (i=0; i<x; i++)
	{
		for (j=0; j<y; j++)
		{
			p.setX(i);		p.setY(j);
			if (matrixMap[i][j] == '#')
			{
				track[i][j] = new NormalTile(p);
			}
			else if (matrixMap[i][j] == '=')
			{
				track[i][j] = new EasyTile(p);
			}			
			else if (matrixMap[i][j] == 'v')
			{
				track[i][j] = new CropTile(p);
			}						
			else if (matrixMap[i][j] == '~')
			{
				track[i][j] = new WaterTile(p);
			}						
			else if (matrixMap[i][j] == 'S')
			{
				track[i][j] = new Tile(p);
				this->start_point = p;
			}						
			else if (matrixMap[i][j] == 'E')
			{
				track[i][j] = new Tile(p);
				this->end_point = p;
			}
		}
	}
}

RaceTrack::~RaceTrack()
{
	int i=0, j=0;
	for (i=0; i<file.getRows(); i++)
	{
		for (j=0; j<file.getColumns(); j++)
		{
			if (track[i][j] != 0)
				delete track[i][j];
		}
	}
}

void RaceTrack::startRace()
{
	int q=0, i=0, j=0;
	int rows = file.getRows(), columns = file.getColumns();
	int rowLimit = file.getRows();
	int columnLimit = file.getColumns();
	char** matrixMap = file.getMap();
	Tile* frogMove;
	Tile* rabbitMove;
	Tile* turtleMove;
	Point2D pFrog, pRabbit, pTurtle;
	int flagFrog=0, flagRabbit=0, flagTurtle=0 , r=0, c=0;
	char u;
	Frog f1, f2, tmpf;
	Rabbit r1, r2, tmpr;
	Turtle t1, t2, tmpt;
	f1.fastestWayX(track, start_point, end_point);
	f2.fastestWayY(track, start_point, end_point);
	r1.fastestWayX(track, start_point, end_point);
	r2.fastestWayY(track, start_point, end_point);
	t1.fastestWayX(track, start_point, end_point);
	t2.fastestWayY(track, start_point, end_point);
	tmpf.moveTo(track[start_point.getX()][start_point.getY()]);
	tmpr.moveTo(track[start_point.getX()][start_point.getY()]);
	tmpt.moveTo(track[start_point.getX()][start_point.getY()]);
	pFrog = tmpf.getCurrentTile()->getPosition();
	pRabbit = tmpr.getCurrentTile()->getPosition();
	pTurtle = tmpt.getCurrentTile()->getPosition();
	
	while (flagFrog ==0 || flagRabbit ==0 || flagTurtle ==0)
	{
		if (pFrog.getX() == end_point.getX() && pFrog.getY() == end_point.getY())
		{
			flagFrog = 1;
		}
		if (pRabbit.getX() == end_point.getX() && pRabbit.getY() == end_point.getY())
		{
			flagRabbit = 1;
		}
		if (pTurtle.getX() == end_point.getX() && pTurtle.getY() == end_point.getY())
		{
			flagTurtle = 1;
		}		
			
		if (flagFrog == 0)
		{
			frogMove = tmpf.lookAhead(track, end_point);
			tmpf.moveTo(frogMove);					
		}
		if (flagRabbit == 0)
		{
			rabbitMove = tmpr.lookAhead(track, end_point);
			tmpr.moveTo(rabbitMove);					
		}
		if (flagTurtle == 0)
		{
			turtleMove = tmpt.lookAhead(track, end_point);
			tmpt.moveTo(turtleMove);					
		}
		if (flagFrog == 0) pFrog = tmpf.getCurrentTile()->getPosition();
		if (flagRabbit == 0) pRabbit = tmpr.getCurrentTile()->getPosition();
		if (flagTurtle ==0) pTurtle = tmpt.getCurrentTile()->getPosition();
	}
	if (f1.getTotalMovementCost() > f2.getTotalMovementCost())
		c_frog = f2;
	else c_frog = f1;
	if (c_frog.getTotalMovementCost() > tmpf.getTotalMovementCost())
		c_frog = tmpf;	
	
	if (r1.getTotalMovementCost() > r2.getTotalMovementCost())
		c_rabbit = r2;
	else c_rabbit = r1;
	if (c_rabbit.getTotalMovementCost() > tmpr.getTotalMovementCost())
		c_rabbit = tmpr;
	
	if (t1.getTotalMovementCost() > t2.getTotalMovementCost())
		c_turtle = t2;
	else c_turtle = t1;
	if (c_turtle.getTotalMovementCost() > tmpt.getTotalMovementCost())
		c_turtle = tmpt;		
	
	
	listType<Tile> movesF(50);
	movesF = c_frog.getAllMoves();
	listType<Tile> movesR(50);
	movesR = c_rabbit.getAllMoves();
	listType<Tile> movesT(50);
	movesT = c_turtle.getAllMoves();
	i=1, j=1, q=1;
	flagFrog =0;	flagRabbit=0;	flagTurtle=0;
	pFrog = movesF[0].getPosition();
	pRabbit = movesR[0].getPosition();
	pTurtle = movesT[0].getPosition();
	c_frog.moveTo(track[start_point.getX()][start_point.getY()]);
	c_turtle.moveTo(track[start_point.getX()][start_point.getY()]);
	c_rabbit.moveTo(track[start_point.getX()][start_point.getY()]);
	int flagS=0;
	while (flagFrog ==0 || flagRabbit ==0 || flagTurtle ==0)
	{
		printMap();
		cout<<"::Positions::\n";
		if (flagS == 0)
		{
			cout<<"The frog is in: "<<movesF[0].getPosition()<<endl;
			cout<<"The Rabbit is in: "<<movesR[0].getPosition()<<endl;
			cout<<"The Turtle is in: "<<movesT[0].getPosition()<<endl;		
		}
		else
		{
			cout<<"The frog is in: "<<movesF[i-1].getPosition()<<endl;
			cout<<"The Rabbit is in: "<<movesR[j-1].getPosition()<<endl;
			cout<<"The Turtle is in: "<<movesT[q-1].getPosition()<<endl;	
		}
		cout<<"Please enter any button to continue to the next turn.\n";
		cin>>u;
		if (pFrog.getX() == end_point.getX() && pFrog.getY() == end_point.getY())
		{
			flagFrog = 1;
		}
		if (pRabbit.getX() == end_point.getX() && pRabbit.getY() == end_point.getY())
		{
			flagRabbit = 1;
		}
		if (pTurtle.getX() == end_point.getX() && pTurtle.getY() == end_point.getY())
		{
			flagTurtle = 1;
		}		
			
		if (flagFrog == 0)
		{
			c_frog.moveTo(&movesF[i]);
			i++;
		}
		if (flagRabbit == 0)
		{
			c_rabbit.moveTo(&movesR[j]);
			j++;				
		}
		if (flagTurtle == 0)
		{
			c_turtle.moveTo(&movesT[q]);
			q++;					
		}
		if (flagFrog == 0) pFrog = c_frog.getCurrentTile()->getPosition();
		if (flagRabbit == 0) pRabbit = c_rabbit.getCurrentTile()->getPosition();
		if (flagTurtle ==0) pTurtle = c_turtle.getCurrentTile()->getPosition();
		flagS=1;
		if (flagFrog ==0 || flagRabbit ==0 || flagTurtle ==0)
			system("cls");
	}
}

void RaceTrack::printMap()
{
	cout<<"::The Map::\n\n";
	int i=0, j=0;
	int r= file.getRows();
	int c= file.getColumns();
	int flagF=0, flagT=0, flagR=0;
	for (i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
		{
			if (c_frog.getCurrentTile()->getPosition() == track[i][j]->getPosition() )
			flagF++;
			if (c_rabbit.getCurrentTile()->getPosition() == track[i][j]->getPosition() )
			flagR++;
			if (c_turtle.getCurrentTile()->getPosition() == track[i][j]->getPosition() )
			flagT++;
			
			if (flagF == 1 && flagR==1 && flagT==1) cout<<"(3)";
			else
			{
				if (flagF == 1) cout<<"(F)";
				if (flagR == 1) cout<<"(R)";
				if (flagT == 1) cout<<"(T)";
			}	
			if (track[i][j]->getPosition() == start_point )
				cout<<"S   ";
			else if (track[i][j]->getPosition() == end_point)
				cout<<"E   ";
			else
			{
				cout<<track[i][j]->getSign()<<"   ";
			}	
			flagF=0;	flagR=0;	flagT=0;
		}
		cout<<endl<<endl<<endl;
	}
}

void RaceTrack::declareWinner()
{
	cout<<"===============Game Result===============\n";
	if (c_frog.getTotalMovementCost() == c_rabbit.getTotalMovementCost() && c_turtle.getTotalMovementCost() == c_frog.getTotalMovementCost())
		cout<<"All the competitors could have been the prince of the navigators!\n";
		
	if (c_frog.getTotalMovementCost() == c_turtle.getTotalMovementCost() && c_frog.getTotalMovementCost() < c_rabbit.getTotalMovementCost())
	{		
		cout<<"1st Place: The Frog & The Turtle could have been the prince of the navigators!  ";
		cout<<"2nd Place:	The Rabbit.\n";		
	}
	if (c_frog.getTotalMovementCost() == c_rabbit.getTotalMovementCost() && c_frog.getTotalMovementCost() < c_turtle.getTotalMovementCost())
	{
		cout<<"1st Place: The Frog & The Rabbit could have been the prince of the navigators!  ";	
		cout<<"2nd Place:	The Turtle.\n";		
	}
	
	if (c_turtle.getTotalMovementCost() == c_rabbit.getTotalMovementCost() && c_turtle.getTotalMovementCost() < c_frog.getTotalMovementCost())
	{
		cout<<"1st Place: The Turtle & The Rabbit could have been the prince of the navigators!";	
		cout<<"2nd Place:	The Frog.\n";		
	}	

	if (c_frog.getTotalMovementCost() < c_rabbit.getTotalMovementCost() && c_frog.getTotalMovementCost() < c_turtle.getTotalMovementCost())
	{
		cout<<"1st Place: The Frog could have been the prince of the navigators!\n";
		if (c_rabbit.getTotalMovementCost() == c_turtle.getTotalMovementCost())
		{
			cout<<"2nd Place:	The Rabbit & The Turtle.\n";
		}
		else if (c_rabbit.getTotalMovementCost() < c_turtle.getTotalMovementCost())
		{
			cout<<"2nd Place:	The Rabbit.\n";
			cout<<"3rd Place:	The Turtle.\n";				
		}
		else
		{
			cout<<"2nd Place:	The Turtle.\n";
			cout<<"3rd Place:	The Rabbit.\n";					
		}
	}

	if (c_rabbit.getTotalMovementCost() < c_frog.getTotalMovementCost() && c_rabbit.getTotalMovementCost() < c_turtle.getTotalMovementCost())
	{
		cout<<"1st Place: The Rabbit could have been the prince of the navigators!\n";
		if (c_frog.getTotalMovementCost() == c_turtle.getTotalMovementCost())
		{
			cout<<"2nd Place:	The Frog & The Turtle.\n";
		}
		else if (c_frog.getTotalMovementCost() < c_turtle.getTotalMovementCost())
		{
			cout<<"2nd Place:	The Frog.\n";
			cout<<"3rd Place:	The Turtle.\n";				
		}
		else
		{
			cout<<"2nd Place:	The Turtle.\n";
			cout<<"3rd Place:	The Frog.\n";					
		}
	}	
	if (c_turtle.getTotalMovementCost() < c_frog.getTotalMovementCost() && c_turtle.getTotalMovementCost() < c_rabbit.getTotalMovementCost())
	{
		cout<<"1st Place: The Turtle could have been the prince of the navigators!\n";
		if (c_frog.getTotalMovementCost() == c_rabbit.getTotalMovementCost())
		{
			cout<<"2nd Place:	The Frog & The Rabbit.\n";
		}
		else if (c_frog.getTotalMovementCost() < c_rabbit.getTotalMovementCost())
		{
			cout<<"2nd Place:	The Frog.\n";
			cout<<"3rd Place:	The Rabbit.\n";				
		}
		else
		{
			cout<<"2nd Place:	The Rabbit.\n";
			cout<<"3rd Place:	The Frog.\n";					
		}
	}
	
	cout<<"Frog cost movement: "<<c_frog.getTotalMovementCost()<<endl;
	cout<<"Rabbit cost movement: "<<c_rabbit.getTotalMovementCost()<<endl;
	cout<<"Turtle cost movement: "<<c_turtle.getTotalMovementCost()<<endl;
	cout<<"The path of the frog was:\n";
	c_frog.printMoves(track, end_point);
	cout<<"The path of the rabbit was:\n";
	c_rabbit.printMoves(track, end_point);
	cout<<"The path of the turtle was:\n";
	c_turtle.printMoves(track, end_point);
}
