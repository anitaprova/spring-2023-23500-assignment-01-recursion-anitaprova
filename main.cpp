#include <iostream>
#include <string>
#include "knights.cpp"

int main()
{
	std::string maze[5][5];
	load("map.txt", maze);
	bool solved = false;

	solve(maze, 0, 0, 1, solved);

	return 0;
}