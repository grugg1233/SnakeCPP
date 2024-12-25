#include "Board.h"
#include "Food.h"

Board::Board() {
    createBoard();
}

void Board::createBoard() {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            theBoard[i][j] = '_';
        }
    }
}

void Board::printBoard() {
    std::cout << "\033[2J\033[1;1H";
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            std::cout << theBoard[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::updateBoard(const std::queue<std::pair<int, int>>& positions, const Food& food) {
    createBoard();
    auto tempQueue = positions;
    while (!tempQueue.empty()) {
        auto segment = tempQueue.front();
        tempQueue.pop();
        theBoard[segment.first][segment.second] = 'O';
    }
    theBoard[food.getX()][food.getY()] = 'F';
}
