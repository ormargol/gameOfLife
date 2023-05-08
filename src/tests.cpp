#include <gtest/gtest.h>
#include <stdio.h>
#include "cell.hpp"

TEST(EvaluateNewStatus, NoNeighbors) {
    Cell c1(LIVE);
    ASSERT_EQ(c1.EvaluateNewStatus(), GOOD);
    ASSERT_EQ(c1.getNextStatus(), DEAD);
    Cell c2(DEAD);
    ASSERT_EQ(c1.EvaluateNewStatus(), GOOD);
    ASSERT_EQ(c1.getNextStatus(), DEAD);
}
TEST(EvaluateNewStatus, oneNeighbor) {
    Cell c1(LIVE), c1n1(LIVE);
	c1.addNeighbor(&c1n1);
	ASSERT_EQ(c1.EvaluateNewStatus(), GOOD);
	ASSERT_EQ(c1.getNextStatus(), DEAD);
    Cell c2(DEAD);
	ASSERT_EQ(c1.EvaluateNewStatus(), GOOD);
	ASSERT_EQ(c1.getNextStatus(), DEAD);
}

TEST(EvaluateNewStatus, allCases) {// count, count of live
	CELL_STATUS newExpectedStatusForLiveCell[6][6] = {
		{DEAD, ERR,  ERR,  ERR,  ERR,  ERR},
		{DEAD, DEAD, ERR,  ERR,  ERR,  ERR},
		{DEAD, DEAD, LIVE, ERR,  ERR,  ERR},
		{DEAD, DEAD, LIVE, LIVE, ERR,  ERR},
		{DEAD, DEAD, LIVE, LIVE, DEAD, ERR},
		{ERR,  ERR,  ERR,  ERR,  ERR,  ERR}
	};
	CELL_STATUS newExpectedStatusForDeadCell[6][6] = {
		{DEAD, ERR,  ERR,  ERR,  ERR,  ERR},
		{DEAD, DEAD, ERR,  ERR,  ERR,  ERR},
		{DEAD, DEAD, DEAD, ERR,  ERR,  ERR},
		{DEAD, DEAD, DEAD, ERR, ERR,  ERR},
		{DEAD, DEAD, DEAD, LIVE, DEAD, ERR},
		{ERR,  ERR,  ERR,  ERR,  ERR,  ERR}
	};
	CELL_STATUS statuses[] = {LIVE, DEAD};
	int neibors_count, live_neibors_count, status_i, neibors_create_i;
	CELL_STATUS status;
	for (status_i = 0; status_i < sizeof(statuses) / sizeof(CELL_STATUS); status_i++) {
		for (neibors_count = 0; neibors_count < 5; neibors_count++) {
			for (live_neibors_count = 0; live_neibors_count < neibors_count; live_neibors_count++) {
				printf("status = %d, neibors_count = %d, live_neibors_count = %d\n", statuses[status_i], neibors_count, live_neibors_count);
				Cell c1(statuses[status_i]);
				for (neibors_create_i = 0; neibors_create_i < live_neibors_count; neibors_create_i++) {
					c1.addNeighbor(new Cell(LIVE));
				}
				while (neibors_create_i++ < neibors_count)
				{
					c1.addNeighbor(new Cell(DEAD));
				}
				if (statuses[status_i] == LIVE)
				{
					ASSERT_EQ(c1.EvaluateNewStatus(), GOOD);
					ASSERT_EQ(c1.getNextStatus(), newExpectedStatusForLiveCell[neibors_count][live_neibors_count]);
				}
				else
				{
					ASSERT_EQ(c1.EvaluateNewStatus(), GOOD);
					ASSERT_EQ(c1.getNextStatus(), newExpectedStatusForDeadCell[neibors_count][live_neibors_count]);
				}
			}
		}
	}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

