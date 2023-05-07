#include "cell.hpp"

Cell::Cell(CELL_STATUS status)
{
	this->status = status;
}

RC Cell::addNeighbor(Cell* neighbor)
{
	neighbors.push_back(neighbor);
	return GOOD;
}

CELL_STATUS Cell::EvaluateNewStatus()
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
			return DEAD;
		}
		else
		{
			return LIVE;
		}
	}
	else
	{
		if (live_neighbors == 3)
		{
			return LIVE;
		}
		else
		{
			return DEAD;
		}
	}
}

RC Cell::UpdateNewStatus()
{
	
}

RC Cell::Print()
{
	
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