#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <vector> 

const int ROWS = 20;
const int COL = 40;

extern std::vector<std::vector<int>> grid;
extern std::vector<std::vector<int>> next_grid;
 
void initGame();
void readInitialConfiguration();
void displayGeneration();
void nextGeneration();

#endif

