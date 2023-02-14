#include <iostream>
#include <string>
#include "knights.cpp"

int main()
{
	std::string maze[5][5];
	int lines;
	lines = load("maze.dat", maze);
	bool solved = false;

	print(maze, lines);
	//solve(maze, lines, 0, 0, 1, solved);

	return 0;
}