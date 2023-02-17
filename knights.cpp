#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "map"

std::string me = "N";
std::string empty = " ";
std::string path = ".";

void load(std::string filename, std::string maze[8][8])
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

void print(std::string maze[8][8])
{
	std::cout << "[0;0H\n";

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << maze[i][j];
		}
		std::cout << "\n";
	}
}

void solve(std::string maze[8][8], int row, int col, int i, bool solved)
{
	if (maze[row][col] == empty) // out of bounds
	{
		return;
	}

	if (i == 64) //no empty spaces left
	{
		solved = true;
		return;
	}

	print(maze);

	if (!solved)
		solve(maze, row + 2, col + 1, i++, solved);
	if (!solved)
		solve(maze, row + 2, col - 1, i++, solved);
	if (!solved)
		solve(maze, row + 1, col + 2, i++, solved);
	if (!solved)
		solve(maze, row + 1, col - 2, i++, solved);

	if (!solved)
		maze[row][col] = i;
}
