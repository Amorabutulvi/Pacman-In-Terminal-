void setup() {
    srand(time(NULL));
    pacmanX = rand() % WIDTH;
    pacmanY = rand() % HEIGHT;
    scoreCount = rand() % 10 + 1;

    for (int i = 0; i < scoreCount; i++) {
        scores[i][0] = -1;
        scores[i][1] = -1;
    }
}

void generateScores() {
    for (int i = 0; i < scoreCount; i++) {
        int x, y;
        do {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        } while (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1 || (x == pacmanX && y == pacmanY));
        scores[i][0] = x;
        scores[i][1] = y;
    }
}

void draw() {
    system("cls");

    for (int i = 0; i <= WIDTH + 1; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < HEIGHT; i++) {
        cout << "#";
        for (int j = 0; j < WIDTH; j++) {
            if (i == pacmanY && j == pacmanX) {
                cout << "P";
            }
            else {
                bool isScore = false;
                for (int k = 0; k < scoreCount; k++) {
                    if (j == scores[k][0] && i == scores[k][1]) {
                        cout << "*";
                        isScore = true;
                        break;
                    }
                }
                if (!isScore) {
                    cout << " ";
                }
            }
        }
        cout << "#" << endl;
    }

    for (int i = 0; i <= WIDTH + 1; i++) {
        cout << "#";
    }
    cout << endl;

    cout << "Score: " << scoreCount << endl;
}
void update(char direction) {
    switch (direction) {
    case 'w':
        if (pacmanY > 0) {
            pacmanY--;
        }
        break;
    case 'a':
        if (pacmanX > 0) {
            pacmanX--;
        }
        break;
    case 's':
        if (pacmanY < HEIGHT - 1) {
            pacmanY++;
        }
        break;
    case 'd':
        if (pacmanX < WIDTH - 1) {
            pacmanX++;
        }
        break;
    default:
        break;
    }


    if (pacmanX == 0 || pacmanX == WIDTH - 1 || pacmanY == 0 || pacmanY == HEIGHT - 1) {
        draw();
        cout << "Game over!" << endl;
        exit(0);
    }


    for (int i = 0; i < scoreCount; i++) {
        if (pacmanX == scores[i][0] && pacmanY == scores[i][1]) {
            scoreCount--;
            scores[i][0] = -1;
            scores[i][1] = -1;


            for (int j = i; j < scoreCount; j++) {
                scores[j][0] = scores[j + 1][0];
                scores[j][1] = scores[j + 1][1];
            }
            break;
        }
    }


    if (scoreCount == 0) {
        draw();
        cout << "You Won " << endl;
        exit(0);
    }
}
