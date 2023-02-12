#include <iostream>
#include <string>
#include "knights.cpp"

int main() {
	std::string maze[5][5];
	int lines = load("maze.dat", maze);
	solve(maze, lines, 0, 4);
	
	return 0;
}