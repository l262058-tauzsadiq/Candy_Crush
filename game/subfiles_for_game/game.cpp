#include <cstdlib>
#include <iostream>
using namespace std;

int board[10][10];

void initializeBoard(int size, int candyTypes)
{
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            board[row][col] = rand() % candyTypes;
        }
    }

    std::cout << "Generated " << size << "x" << size << " board:\n";
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            std::cout << board[row][col] << '\t';
        }
        std::cout << '\n';
    }
}