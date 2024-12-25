#include <iostream>
#include <cstdlib>
#include "Board.h"
#include "Snake.h" 
#include "Food.h"
#include <termios.h>
#include <unistd.h>
using namespace std;

void enableRawMode() {
    termios raw;
    tcgetattr(STDIN_FILENO, &raw);   // Get current terminal attributes
    raw.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &raw); // Apply the settings
}

void disableRawMode(termios original) {
    tcsetattr(STDIN_FILENO, TCSANOW, &original); // Restore terminal settings
}
int main() {
    termios original;
    tcgetattr(STDIN_FILENO, &original); // Save the original terminal settings
    enableRawMode();

    Board b;           // Create the board
    Food f(&b);        // Create food linked to the board
    Snake s(&b, &f);   // Create snake linked to the board and food

    b.printBoard();    // Display the initial board state
    std::cout << "Use W (up), A (left), S (down), D (right) to move the snake. Press 'q' to quit.\n";

    while (true) {
        char ch = getchar(); // Capture user input
        if (ch == 'q') {
            std::cout << "Game Over. Exiting...\n";
            break;
        }

        // Handle WASD keys
        switch (ch) {
            case 'w': s.updatePosition('U'); break; // Move up
            case 's': s.updatePosition('D'); break; // Move down
            case 'a': s.updatePosition('L'); break; // Move left
            case 'd': s.updatePosition('R'); break; // Move right
        }

        b.printBoard(); // Refresh the board
        usleep(100000); // Delay for smoother gameplay
    }

    disableRawMode(original);
    return 0;
}
