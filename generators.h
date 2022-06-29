#pragma once

#include <vector>
#include "grid.h"
#include "cell.h"

class BinaryTree
{
	public:
		BinaryTree(Grid*);
	
};

BinaryTree::BinaryTree(Grid* g)
{
	for (int i = 0; i < g->rows; i++)
	{
		for (int j = 0; j < g->cols; j++)
		{
			auto cell = &g->grid[i][j];
			std::vector<Cell*> neighbors;
			if (cell->north != nullptr)
			{
				neighbors.push_back(cell->north);
			}
			if (neighbors.size() > 0)
			{
				int choice = 0;
				cell->link(neighbors[0]);
			}
		}
	}
}
