#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "knights.cpp"
#include "map"

int main()
{
	std::string maze[8][8];
	load("map.txt", maze);
	bool solved = false;

	print(maze);
	solve(maze, 1, 1, 1, solved);

	return 0;
}