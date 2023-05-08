#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Cell.hpp"

/*
                Cell(CELL_STATUS status);
                RC addNeighbor(Cell* neighbor);
                RC EvaluateNewStatus();
                RC UpdateNewStatus();
                RC Print();
                std::list<Cell*> getNeighbors();
                CELL_STATUS getStatus();
                CELL_STATUS getNextStatus();
*/

int main(int argc, char** argv)
{
	Cell matrix[10][10];
	int options[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1,1 }};
	int i, j, k, opti, optj;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 8; k++) {
				opti = i + options[k][0];
				optj = j + options[k][1];
				if (opti >= 0 && opti < 10 && optj >= 0 && optj < 10) {
					matrix[i][j].addNeighbor(&matrix[opti][optj]);
				}
			}
		}
	}
	matrix[2][1].Live();
	matrix[2][2].Live();
	matrix[2][3].Live();
	while (1) {
		system("clear");
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				matrix[i][j].Print();
				matrix[i][j].EvaluateNewStatus();
			}
			printf("\n");
		}
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				matrix[i][j].UpdateNewStatus();
			}
		}
		sleep(1);
	}
	printf("hello\n");
	return 0;
}
