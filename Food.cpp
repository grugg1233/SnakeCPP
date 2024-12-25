#include "Food.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>

Food::Food(Board* b) : board(b) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(nullptr));
        initialized = true;
    }
    generateFood();
}

void Food::generateFood() {
    do {
        xFood = rand() % 16;
        yFood = rand() % 32;
    } while (board->theBoard[xFood][yFood] != '_');
    board->theBoard[xFood][yFood] = 'F';
}
