#pragma once

#include "grid.h"
#include "distances.h"

class DistanceGrid: public Grid
{
	public:
		Distances dists;
		DistanceGrid(int, int);
		void setDistances(Distances);
		std::string contentsOf(Cell* c);
		
};

DistanceGrid::DistanceGrid(int r, int c): Grid(r, c) 
{
}

void DistanceGrid::setDistances(Distances d)
{
	dists = d;
}

std::string DistanceGrid::contentsOf(Cell* c)
{
	return "" + std::to_string(dists[c]);
}
