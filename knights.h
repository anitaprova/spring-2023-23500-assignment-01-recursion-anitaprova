#pragma once

void load(std::string filename, std::string *maze);
void print(std::string maze[8][8]);
void solve(std::string maze[8][8], int row, int col, int i, bool solved);