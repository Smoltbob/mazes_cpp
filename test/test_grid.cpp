#include <gtest/gtest.h>
#include "grid.h"

TEST(Constructor, BasicAssertions) {
	Grid grid(10, 10);
	EXPECT_EQ(grid.rows, 10);
	EXPECT_EQ(grid.cols, 10);
	for (auto i = 0; i < 10; i++)
	{
		for (auto j = 0; j < 10; j++)
		{
			EXPECT_EQ(grid.grid[i][j].row, i);	
			EXPECT_EQ(grid.grid[i][j].col, j);	
		}
	}
}

TEST(ConfigureCells, BasicAssertions) {
	Grid grid(10, 10);
	grid.configureCells();
	EXPECT_EQ(grid.rows, 10);
	EXPECT_EQ(grid.cols, 10);
	for (auto i = 0; i < 10; i++)
	{
		for (auto j = 0; j < 10; j++)
		{
			if (i > 1)
			{
				EXPECT_EQ(grid.grid[i][j].north, &grid.grid[i - 1][j]);
			}
		}
	}
}
