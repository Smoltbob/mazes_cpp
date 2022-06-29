#pragma once

#include <vector> //TODO static allocation
#include <iostream>
#include <string>
#include "cell.h"

class Grid
{
	public:
		int rows;
		int cols;
		std::vector<std::vector<Cell>> grid;
		Grid(int, int);
		void configureCells();
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

void Grid::configureCells()
{
	for (int i = 0; i < rows; i++) // TODO improve indices names
	{
		for (int j = 0; j < cols; j++)
		{
			if (i > 0)
			{
				grid[i][j].north = &grid[i - 1][j];
			}
			if (i < rows - 1)
			{
				grid[i][j].south = &grid[i + 1][j];
			}
			if (j > 0)
			{
				grid[i][j].east = &grid[i][j - 1];
			}
			if (j < cols - 1)
			{
				grid[i][j].west = &grid[i][j + 1];
			}
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
			std::string east_boundary = (cell.isLinked(cell.east) ? " " : "|");
			top += body + east_boundary;

			std::string south_boundary = (cell.isLinked(cell.south) ? "   " : "---");
			bottom += south_boundary + "+";
		}

		os << top << std::endl;
		os << bottom << std::endl;
	}
	return os;
}
