#pragma once

#include <unordered_set>
#include "distances.h"


class Cell
{
	public:
		int row;
		int col;
		Cell* north{nullptr};
		Cell* south{nullptr};
		Cell* east{nullptr};
		Cell* west{nullptr};
		//std::unordered_map<Cell*, bool> links;
		std::unordered_set<Cell*> links;

		Cell(int r, int c): row{r}, col{c} {};
		void link(Cell*, bool);
		void unlink(Cell*, bool);
		std::unordered_set<Cell*> getLinks();
		bool isLinked(Cell*);
		Distances getDistances();

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

Distances Cell::getDistances()
{
	Distances dists(this);
	std::unordered_set<Cell*> frontier;
	frontier.insert(this);

	while (frontier.size() > 0)
	{
		//std::cout << frontier.size() << std::endl;
		std::unordered_set<Cell*> new_frontier;
		for (auto const& cell: frontier)
		{
			for (auto const& linked: cell->getLinks())
			{
				if (dists.isExplored(linked) == false)
				{
					dists[linked] = dists[cell] + 1;
					new_frontier.insert(linked);
				}
			}
		}
		frontier = new_frontier;
	}

	return dists;
}




