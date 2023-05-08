#include <list>

typedef enum {LIVE, DEAD, ERR} CELL_STATUS;
typedef enum {GOOD, BAD} RC;

class Cell {
	private:
		std::list<Cell*> neighbors;
		CELL_STATUS status;
		CELL_STATUS nextStatus;
		
	public:
		Cell(CELL_STATUS status);
		RC addNeighbor(Cell* neighbor);
		RC EvaluateNewStatus();
		RC UpdateNewStatus();
		RC Print();
		std::list<Cell*> getNeighbors();
		CELL_STATUS getStatus();
		CELL_STATUS getNextStatus();
};
