#ifndef SNAKE_H
#define SNAKE_H

#include <queue> // For managing positions
#include <utility> // For std::pair

class Board; // Forward declaration
class Food;  // Forward declaration

class Snake {
private:
    std::queue<std::pair<int, int>> positions;
    Board* board;
    Food* food;

public:
    Snake(Board* b, Food* f);
    void updatePosition(char direction);
    void grow();
};

#endif
