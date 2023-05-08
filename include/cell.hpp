#include <list>

	typedef enum
	{
		DEAD,
		LIVE
	}STATE;
	
class Cell
{
	public:
	Cell(STATE);
	void addFriend(Cell*);
	void calculateNextState();
	STATE getNextState();
	
	private:
	
	STATE state;
	STATE nextState;
	std::list<Cell*> friends;
};
	