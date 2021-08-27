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

		Cell(int, int);
		void link(Cell, bool);
		void unlink(Cell, bool);
		std::unordered_set<Cell*> getLinks();
		bool isLinked(Cell);

};
/*
bool operator== (const Cell& lhs, const Cell& rhs)
{
	return lhs.row == rhs.col && lhs.col == rhs.col;
};

template<> struct std::hash<Cell>
{
	std::size_t operator()(Cell const& c) const noexcept {
		std::size_t h1 = std::hash<int>{}(c.col);
		std::size_t h2 = std::hash<int>{}(c.row);
		return h1 ^ (h2 << 1);
	}
};*/


Cell::Cell(int r, int c)
{
	int row = r;
	int col = c; // TODO list initialization
}

// TODO how to declare class functions?
void Cell::link(Cell cell, bool bidi=true)
{
	links.insert(&cell);
	if (bidi)
	{
		cell.links.insert(this);
	}
}

void Cell::unlink(Cell cell, bool bidi=true)
{
	links.erase(&cell);
	if (bidi)
	{
		cell.links.erase(this);
	}
}

std::unordered_set<Cell*> Cell::getLinks()
{
	return links;
}

bool Cell::isLinked(Cell cell)
{
	std::unordered_set<Cell*>::iterator it;
	it = this->links.find(&cell);
	if (it == this->links.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
