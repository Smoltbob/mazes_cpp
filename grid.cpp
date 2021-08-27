#include <vector> //TODO static allocation
#include <iostream>
#include <string>
#include "cell.cpp"

class Grid
{
	public:
		int rows;
		int cols;
		std::vector<std::vector<Cell>> grid;
		Grid(int, int);
		friend std::ostream& operator<<(std::ostream& os, const Cell& c); // TODO what is friend?

};

Grid::Grid(int r, int c): rows{r}, cols{c}
{
	// TOOD std::size_t i{0U} ? Why?
	for (int i = 0; i < rows; i++)
	{
		std::vector<Cell> newRow;
		grid.push_back(newRow);
		for (int j = 0; j < cols; j++)
		{
			grid[i].push_back(Cell(i,j));
		}
	}
}


std::ostream& operator<<(std::ostream& os, const Grid& g)
{
	// Top line
	os << "+";
       	for (auto i = 0; i < g.cols; i++)
	{
		os << "---+";
	}
	os << std::endl;

	for (auto i = 0; i < g.rows; i++)
	{
		std::string top = "|";
		std::string bottom = "+";

		for (auto cell: g.grid[i])
		{
			std::string body = "   ";
			std::string east_boundary = (cell.isLinked(*cell.east) ? " " : "|");
			top += body + east_boundary;

			std::string south_boundary = (cell.isLinked(*cell.south) ? "   " : "---");
			bottom += south_boundary + "+";
		}

		os << top << std::endl;
		os << bottom << std::endl;
	}
	return os;
}
