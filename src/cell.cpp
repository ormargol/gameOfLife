/*
#include <list>

	typedef enum
	{
		DEAD,
		LIVE
	}STATE;
	
class Cell
{
	public:
	void addFriend(Cell*);
	void calculateNextState();
	STATE getNextState();
	
	private:
	
	STATE state;
	STATE nextState;
	std::list<Cell*> friends;
};
	
*/

#include "cell.hpp"

Cell::Cell(STATE state)
{
	this->state = state;
}

void Cell::addFriend(Cell* cell)
{
	friends.push_back(cell);
}

STATE Cell::getNextState()
{
	return nextState;
}

void Cell::calculateNextState()
{
	int numOfNeighbors = 0;
	for (std::list<Cell*>::iterator it = friends.begin(); it != friends.end(); ++it){
		numOfNeighbors += (int)((*it)->state);
	}
if ((state == LIVE && numOfNeighbors >= 2 && numOfNeighbors <= 3) ||
	(state == DEAD && numOfNeighbors == 3))
	{
		nextState = LIVE;
	}
	else
	{
		nextState = DEAD;
	}		
}