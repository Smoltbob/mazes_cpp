#include <iostream>
#include "grid.cpp"


// TODO
// Files organization: make .h ?
// Inside a file: how to organize function declarations ? Coding style ?
// Unit testing
// Setup bazel
int main()
{
	Grid myGrid(10, 10);
	std::cout << myGrid.cols << "," << myGrid.rows << std::endl;
	std::cout << myGrid << std::endl;
}

