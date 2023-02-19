#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "knights.cpp"
#include "map"

int main()
{
	std::string maze[5][5];
	int solution[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			solution[5][5] = 0;
		}
	}

	load("map.txt", maze);
	bool solved = false;

	solve(maze, 0, 3, 1, solved, solution);
	print(solution);

	return 0;
}