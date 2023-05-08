#include <gtest/gtest.h>
#include <stdio.h>
#include "cell.hpp"

TEST(cellNextState, LiveWithThreeLiveFriends)
{
	Cell c1(LIVE);
	for (int i = 1; i <= 3; i++)
	{
		c1.addFriend(new Cell(LIVE));
	}
	for (int i = 1; i <= 2; i++)
	{
		c1.addFriend(new Cell(DEAD));
	}
	c1.calculateNextState();
	ASSERT_EQ(c1.getNextState(), LIVE);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

