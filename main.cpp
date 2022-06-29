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
	Grid myGrid(10, 10);
	//myGrid.configureCells();
	std::cout << myGrid.cols << "," << myGrid.rows << std::endl;
	//std::cout << myGrid << std::endl;
	BinaryTree genBin(myGrid);
	std::cout << myGrid << std::endl;
}

