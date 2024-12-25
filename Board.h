#ifndef BOARD_H
#define BOARD_H

#include <queue>
#include <utility>
#include <iostream>
class Food; // Forward declaration

class Board {
public:
    char theBoard[16][32];

    Board();
    void createBoard();
    void printBoard();
    void updateBoard(const std::queue<std::pair<int, int>>& positions, const Food& food);
};

#endif
