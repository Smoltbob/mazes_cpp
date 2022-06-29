#pragma once

#include <vector> //TODO static allocation
#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

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
		void to_png(int);
		virtual std::string contentsOf(Cell*);
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
				grid[i][j].west = &grid[i][j - 1];
			}
			if (j < cols - 1)
			{
				grid[i][j].east = &grid[i][j + 1];
			}
		}
	}
}

std::string Grid::contentsOf(Cell* c)
{
	return " ";
}

// TODO cleaner characters (page 46)
std::ostream& operator<<(std::ostream& os, Grid& g)
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

		for (auto j = 0; j < g.cols; j++)
		{
			Cell cell = g.grid[i][j];
			Cell* pcell = &(g.grid[i][j]);
			//std::cout << pcell << std::endl;
			std::string body = " " + g.contentsOf(pcell) + " ";
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

void Grid::to_png(int cell_size = 10)
{
	int img_width = cell_size * cols;
	int img_height = cell_size * rows;
	cv::Scalar background(255, 255, 255);
	cv::Scalar wall(0, 0, 0);

	cv::Mat image = cv::Mat(img_height + 1, img_width + 1, CV_8UC3, background);

	for (auto i = 0; i < rows; i++)
	{
		for (auto j = 0; j < cols; j++)
		{
			auto cell = grid[i][j];
			int x1 = cell.col * cell_size;
			int y1 = cell.row * cell_size;
			int x2 = (cell.col + 1) * cell_size;
			int y2 = (cell.row + 1) * cell_size;

			if (cell.north == nullptr)
			{
				auto pt1 = cv::Point(x1, y1);
				auto pt2 = cv::Point(x2, y1);
				cv::line(image, pt1, pt2, wall);
			}
			if (cell.west == nullptr)
			{
				auto pt1 = cv::Point(x1, y1);
				auto pt2 = cv::Point(x1, y2);
				cv::line(image, pt1, pt2, wall);
			}
			if (!cell.isLinked(cell.east))
			{
				auto pt1 = cv::Point(x2, y1);
				auto pt2 = cv::Point(x2, y2);
				cv::line(image, pt1, pt2, wall);
			}
			if (!cell.isLinked(cell.south))
			{
				auto pt1 = cv::Point(x1, y2);
				auto pt2 = cv::Point(x2, y2);
				cv::line(image, pt1, pt2, wall);
			}

		}
	}
	std::cout << cv::imwrite("maze.png", image) << std::endl;
}

