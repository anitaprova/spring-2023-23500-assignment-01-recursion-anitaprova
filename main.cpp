#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "knights.cpp"
#include "map"

int main()
{
	std::string maze[5][5];
	load("map.txt", maze);
	bool solved = false;

	print(maze);
	solve(maze, 0, 3, 1, solved);

	return 0;
}