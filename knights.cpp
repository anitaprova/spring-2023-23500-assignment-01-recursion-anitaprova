#include <iostream>
#include <fstream>
#include <string>
#include "map.dat"

int load(std::string filename, std::string *maze)
{
	std::ifstream infile(filename);
	int i = 0;
	while (std::getline(infile, maze[i]))
	{
		i++;
	}
	return i;
}

void print(std::string maze[5][5], int lines)
{
	std::cout << "[0;0H\n";

	for (int i = 0; i < lines; i++)
	{
		std::cout << maze[i] << "\n";
	}
}

std::string me = "N";
std::string empty = " ";
std::string path = ".";

void solve(std::string maze[5][5], int lines, int row, int col, int i, bool solved)
{
	if (maze[row][col] == empty) //out of bounds
	{
		return;
	}

	if(i == 25){
		solved = true;
		return;
	}

	if (!solved) solve(maze, lines, row + 2, col + 1, i++, solved);
	if (!solved) solve(maze, lines, row + 2, col - 1, i++, solved);
	if (!solved) solve(maze, lines, row + 1, col + 2, i++, solved);
	if (!solved) solve(maze, lines, row + 1, col - 2, i++, solved);

	if(!solved) maze[row][col] = i;
}
