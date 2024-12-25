#include "Snake.h"
#include "Board.h"
#include "Food.h"

Snake::Snake(Board* b, Food* f) : board(b), food(f) {
    positions.push({2, 2});
    board->theBoard[2][2] = 'O';
}

void Snake::updatePosition(char direction) {
    auto head = positions.back();
    int newX = head.first;
    int newY = head.second;

    if (direction == 'U') newX--;
    else if (direction == 'D') newX++;
    else if (direction == 'L') newY--;
    else if (direction == 'R') newY++;

    if (newX < 0 || newX >= 16 || newY < 0 || newY >= 32) {
        std::cout << "Collision with wall! Game Over.\n";
        exit(0);
    }

    auto tempQueue = positions;
    while (!tempQueue.empty()) {
        auto segment = tempQueue.front();
        tempQueue.pop();
        if (segment.first == newX && segment.second == newY) {
            std::cout << "Collision with self! Game Over.\n";
            exit(0);
        }
    }

    positions.push({newX, newY});

    if (newX == food->getX() && newY == food->getY()) {
        food->generateFood();
        
    } else {
        auto tail = positions.front();
        positions.pop();
        board->theBoard[tail.first][tail.second] = '_';
    }

    board->updateBoard(positions, *food);
}

