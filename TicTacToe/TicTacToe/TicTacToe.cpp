// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

/*
0 = empty
1 = x
2 = o
*/

int gameState[3][3] = {{0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0}};

void showGameState(int gameState[3][3]) {
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "  ";

        for (int j = 0; j < 3; j++) {
            switch (gameState[i][j]) {
                case 0:
                    if (i == 2) {
                        std::cout << " ";
                    }
                    else {
                        std::cout << "_";
                    }
                    break;
                case 1:
                    std::cout << "x";
                    break;
                case 2:
                    std::cout << "o";
                    break;
            }
            
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void updateGameState(int gameState[3][3], std::string input, int *currentPlayer) {
    bool validInput = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (input == std::to_string(i) + std::to_string(j)) {
                int a = int(input[0]) - 48;
                int b = int(input[1]) - 48;

                if (gameState[a][b] != 0) {
                    continue;
                }

                gameState[a][b] = *currentPlayer;

                if (*currentPlayer == 1) {
                    *currentPlayer = 2;
                }
                else {
                    *currentPlayer = 1;
                }

                validInput = true;
            }
        }
    }

    if (!validInput) {
        std::cout << "invalid input, try again" << std::endl;
    }
}

bool checkForWin(int gameState[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (gameState[i][0] != 0 && gameState[i][0] == gameState[i][1] && gameState[i][0] == gameState[i][2]) {
            return true;
        }
        else if (gameState[0][i] != 0 && gameState[0][i] == gameState[1][i] && gameState[0][i] == gameState[2][i]) {
            return true;
        }
    }

    if (gameState[1][1] == 0) {
        return false;
    }

    if (gameState[0][0] == gameState[1][1] && gameState[0][0] == gameState[2][2]) {
        return true;
    }
    else if (gameState[0][2] == gameState[1][1] && gameState[0][2] == gameState[2][0]) {
        return true;
    }

    return false;
}

bool checkForDraw(int gameState[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameState[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string input;
    int currentPlayer = 1;

    showGameState(gameState);

    while(true) {
        std::cin >> input;
        updateGameState(gameState, input, &currentPlayer);
        showGameState(gameState);

        if (checkForWin(gameState)) {
            if (currentPlayer == 1) {
                std::cout << "Player o wins" << std::endl;
            }
            else {
                std::cout << "Player x wins" << std::endl;
            }
            break;
        }
        else if (checkForDraw(gameState)) {
            std::cout << "It's a draw" << std::endl;
            break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
