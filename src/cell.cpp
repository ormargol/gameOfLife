#include <stdio.h>
#include "cell.hpp"

Cell::Cell()
{
	status = DEAD;
}

Cell::Cell(CELL_STATUS status)
{
	this->status = status;
}

RC Cell::addNeighbor(Cell* neighbor)
{
	neighbors.push_back(neighbor);
	return GOOD;
}

RC Cell::EvaluateNewStatus()
{
	int live_neighbors = 0;
	std::list<Cell*>::iterator it;
	for (it = neighbors.begin(); it != neighbors.end(); ++it){
		if ((*it)->getStatus() == LIVE)
		{
			live_neighbors++;
		}
	}
	if (status == LIVE)
	{
		if (live_neighbors < 2 || live_neighbors > 3)
		{
			nextStatus = DEAD;
		}
		else
		{
			nextStatus = LIVE;
		}
	}
	else
	{
		if (live_neighbors == 3)
		{
			nextStatus = LIVE;
		}
		else
		{
			nextStatus = DEAD;
		}
	}
	return GOOD;
}

RC Cell::UpdateNewStatus()
{
	status = nextStatus;
}

RC Cell::Print()
{
	if (status == LIVE) { printf("%c", (char)219); }
	else { printf(" "); }
	return GOOD;
}

std::list<Cell*> Cell::getNeighbors()
{
	return neighbors;
}

CELL_STATUS Cell::getStatus()
{
	return status;
}

CELL_STATUS Cell::getNextStatus()
{
	return nextStatus;
}
