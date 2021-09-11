#include <iostream>
#include "grid.h"
#include "distance_grid.h"
#include "generators.h"
#include "distances.h"


// TODO
// Files organization: make .h ?
// Inside a file: how to organize function declarations ? Coding style ?
// Unit testing
// Setup bazel
// std::unique_ptr ?
// std::make_unique ?
int main()
{
	DistanceGrid myGrid(4, 4);
	myGrid.configureCells();
	BinaryTree genBin(&myGrid);
	Distances dists(myGrid.grid[0][0].getDistances());
	myGrid.setDistances(dists);
	std::cout << myGrid << std::endl;
	myGrid.to_png();
}

