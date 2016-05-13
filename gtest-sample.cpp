#include <iostream>
#include "gtest/gtest.h"

TEST(Group1,Subtest1) {
	EXPECT_EQ(1,0);
}

TEST(Group2,Subtest1) {
	EXPECT_EQ(0,0);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	return result;
}
