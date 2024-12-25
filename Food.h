#ifndef FOOD_H
#define FOOD_H

class Board; // Forward declaration

class Food {
private:
    Board* board;
    int xFood;
    int yFood;

public:
    Food(Board* b);
    void generateFood();
    int getX() const { return xFood; }
    int getY() const { return yFood; }
};

#endif
