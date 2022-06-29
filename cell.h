#pragma once

#include <unordered_set>
#include <set>


class Cell
{
	public:
		int row;
		int col;
		Cell* north;
		Cell* south;
		Cell* east;
		Cell* west;
		//std::unordered_map<Cell*, bool> links;
		std::unordered_set<Cell*> links;

		Cell(int r, int c): row{r}, col{c} {};
		void link(Cell*, bool);
		void unlink(Cell*, bool);
		std::unordered_set<Cell*> getLinks();
		bool isLinked(Cell*);

};


// TODO how to declare class functions?
void Cell::link(Cell* cell, bool bidi=true)
{
	links.insert(cell);
	if (bidi)
	{
		cell->links.insert(this);
	}
}

void Cell::unlink(Cell* cell, bool bidi=true)
{
	links.erase(cell);
	if (bidi)
	{
		cell->links.erase(this);
	}
}

std::unordered_set<Cell*> Cell::getLinks()
{
	return links;
}

bool Cell::isLinked(Cell* cell)
{
	std::unordered_set<Cell*>::iterator it;
	it = this->links.find(cell);
	if (it == this->links.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
