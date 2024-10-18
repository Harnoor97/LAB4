#include <ncurses.h>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "game_of_life.h"

std::vector<std::vector<int>> grid(ROWS, std::vector<int>(COL));
std::vector<std::vector<int>> next_grid(ROWS, std::vector<int>(COL));

void initGame() {
    for(int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COL; ++j) {
            grid[i][j] = 0;
        }
    }
    next_grid = grid;
}

void displayGeneration() {
    clear();
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COL; ++j) {
            if (grid[i][j] == 1) {
                mvprintw(i, j, "X");
            } else {
                mvprintw(i, j, " ");
            }
        }
    }
    refresh();
}

void nextGeneration() {
    std::cout << "Next generation called" << std::endl; 
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COL; ++j) {
            int liveNeighbor = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if(x == 0 && y == 0) continue;
                    int r = i + x;
                    int c = j + y;
                    if(r >= 0 && r < ROWS && c >= 0 && c < COL) {
                        liveNeighbor += grid[r][c];
                    }
                }
            }
            if (grid[i][j] == 1) {
                next_grid[i][j] = (liveNeighbor == 2 || liveNeighbor == 3) ? 1 : 0;
            } else {
                next_grid[i][j] = (liveNeighbor == 3) ? 1 : 0;
            }
        }
    }
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COL; ++j) {
            std::cout << next_grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    grid = next_grid;
    displayGeneration();
}