#pragma once

class Cell;
#include "cell.h"
#include <unordered_map>

class Distances
{
	public:
		Cell* root;
		std::unordered_map<Cell*, int> cells;
		Distances();
		Distances(Cell*);
		int& operator[](Cell*);
		bool isExplored(Cell*);
};

Distances::Distances()
{
	Cell* dummy;
	cells[dummy] = 0;
}

Distances::Distances(Cell* r): root{r}
{
	cells[root] = 0;
}

bool Distances::isExplored(Cell* c)
{
	std::unordered_map<Cell*, int>::iterator it;
	it = this->cells.find(c);
	if (it == this->cells.end())
	{
		return false;
	}
	else
	{
		return true;
	}

}

int& Distances::operator[](Cell* c)
{
	// OBS! Undefined if c not in hashmap
	return cells[c];
}


