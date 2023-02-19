#pragma once

void load(std::string filename, std::string maze);
void print(std::string maze[5][5]);
void print_solution(std::string solution[5][5]);
void solve(std::string maze[5][5], int row, int col, int i, bool &solved);