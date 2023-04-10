#include <iostream>
#include <conio.h>

#include "Header.h"
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

int pacmanX, pacmanY;
int scoreCount;
int scores[10][2];


int main() {
    setup();
    generateScores();

    while (scoreCount > 0) {
        draw();
        char direction = _getch();
        update(direction);
    }

    draw();
    cout << "You Won" << endl;

    return 0;
}