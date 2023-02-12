#include <iostream>
#include <fstream>
#include <string>
#include "map.dat"

int load(std::string filename, std::string *maze) {
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,maze[i])){
      i++;
    }
  return i;
}

void print(std::string maze[][], int lines){
  std::cout << "[0;0H\n";

  for (int i = 0; i < lines; i++){
    std::cout << maze[i] << "\n";
  }
  
}

char me = 'N';
char empty = '.';
int i = 1;
void solve(std::string maze[][], int row, int col) {
	if(!empty){
		return;
	}
	
	maze[row][col] = me;
	print(maze,lines);

	solve(maze, lines, row + 2, col + 1);
	solve(maze, lines, row + 2, col - 1);
	solve(maze, lines, row + 1, col + 2);
	solve(maze, lines, row + 1, col - 1);

	maze[row][col] = i;
	i++;
}
