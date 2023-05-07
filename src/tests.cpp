#include <gtest/gtest.h>

TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, -1);
    ASSERT_EQ(-1.0, 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

