#include <gtest/gtest.h>
#include "cell.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
	Cell c1(0,0);
	Cell c2(0,1);
	c1.link(&c2, false);
	EXPECT_EQ(c1.isLinked(&c2), true);
	EXPECT_EQ(c2.isLinked(&c1), false);
	c1.link(&c2, true);
	EXPECT_EQ(c2.isLinked(&c1), true);
}
