#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "map"

std::string me = "N";
std::string path = ".";
std::string visited = "v";

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
	std::cout << "[0;0H\n";

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

void print(int solution[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (solution[i][j] < 10 && solution[i][j] > 0)
			{
				std::cout << " ";
			}
			std::cout << std::to_string(solution[i][j]) + ":";
		}
		std::cout << "\n";
	}
}

void solve(std::string maze[5][5], int row, int col, int i, bool solved, int s[5][5])
{
	if (maze[row][col] == me || maze[row][col] == visited)
	{
		return;
	}

	if (i == 25) // no empty spaces left
	{
		solved = true;
		return;
	}

	maze[row][col] = me;
	s[row][col] = i;
	i++;
	usleep(150000);
	print(maze);

	if (!solved && row + 2 < 5 && col + 1 < 5) // doesnt go out of bounds
		solve(maze, row + 2, col + 1, i, solved, s);

	if (!solved && row + 2 < 5 && col - 1 >= 0)
		solve(maze, row + 2, col - 1, i, solved, s);

	if (!solved && row + 1 < 5 && col + 2 < 5)
		solve(maze, row + 1, col + 2, i, solved, s);

	if (!solved && row + 1 < 5 && col - 2 >= 0)
		solve(maze, row + 1, col - 2, i, solved, s);

	if (!solved && row - 1 >= 0 && col - 2 >= 0)
		solve(maze, row - 1, col - 2, i, solved, s);

	if (!solved && row - 1 >= 0 && col + 2 < 5)
		solve(maze, row - 1, col + 2, i, solved, s);

	if (!solved && row - 2 >= 0 && col - 1 >= 0)
		solve(maze, row - 2, col - 1, i, solved, s);

	if (!solved && row - 2 >= 0 && col + 1 < 5)
		solve(maze, row - 2, col + 1, i, solved, s);

	if (!solved)
		maze[row][col] = visited;
}
