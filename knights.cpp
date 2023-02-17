#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "map"

std::string me = "N";
std::string path = ".";

void load(std::string filename, std::string maze[5][5])
{
	std::ifstream infile(filename);
	int r = 0;
	int c = 0;
	std::string line;
	while (std::getline(infile, line))
	{ // gets each line
		for (int i = 0; i < line.length(); i++)
		{
			maze[r][c] = line[i];
			c++;
		}
		r++;
		c = 0;
	}
}

void print(std::string maze[5][5])
{
	//std::cout << "[0;0H\n";

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << maze[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void solve(std::string maze[5][5], int row, int col, int i, bool solved)
{
	if(maze[row][col] == me) {
		return;
	}

	if (i == 25) // no empty spaces left
	{
		solved = true;
		return;
	}

	maze[row][col] = me;
	print(maze);

	if (!solved && row + 2 > 5 && col + 1 > 5) //doesnt go out of bounds
		solve(maze, row + 2, col + 1, i++, solved);

	if (!solved && row + 2 > 5 && col - 1 > 5)
		solve(maze, row + 2, col - 1, i++, solved);

	if (!solved && row + 1 > 5 && col + 2 > 5)
		solve(maze, row + 1, col + 2, i++, solved);

	if (!solved && row + 1 > 5 && col - 2 > 5)
		solve(maze, row + 1, col - 2, i++, solved);

	if (!solved)
		maze[row][col] = i;
}
