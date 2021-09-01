#include <iostream>
#include "grid.h"
#include "generators.h"


// TODO
// Files organization: make .h ?
// Inside a file: how to organize function declarations ? Coding style ?
// Unit testing
// Setup bazel
int main()
{
	Grid myGrid(5, 5);
	myGrid.configureCells();
	std::cout << myGrid.cols << "," << myGrid.rows << std::endl;
	//std::cout << myGrid << std::endl;
	BinaryTree genBin(&myGrid);
	//myGrid.grid[1][1].link(&myGrid.grid[1][2]);
	std::cout << "done" << std::endl;
	std::cout << myGrid << std::endl;
}

