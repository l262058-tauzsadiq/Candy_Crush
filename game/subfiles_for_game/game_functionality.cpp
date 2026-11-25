#include <SFML/Graphics.hpp>
#include <prototype.h>
#include <cstdlib>

bool candyMatch(int board[10][10], int size) {
    bool grid[10][10] = {}; // every element is 0
    bool match_found = false, clear_board = false; // if 5 elements are same

    // this loop checks horizontal mathces
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == -1) {
                continue; 
            }

            int match_length = 1;
            // counting candies row wise
            for (int next = col + 1; next < size; next++) {
                if (board[row][next] != board[row][col]) {
                    break;
                }
                match_length++;
            }

            if (match_length == 3) {
                match_found = true;
                for (int clear_col = col; clear_col < col + match_length; clear_col++) {
                    grid[row][clear_col] = true;
                }
            }
            else if (match_length == 4) {
                match_found = true;
                for (int clear_col = 0; clear_col < size; clear_col++) {
                    grid[row][clear_col] = true;
                }
            }
            else if (match_length >= 5) {
                match_found = true;
                clear_board = true;
            }
        }
    }

    // this loop checks verticle matches
    for (int col = 0; col < size; col++) {
        for (int row = 0; row < size; row++) {
            if (board[row][col] == -1) {
                continue;
            }

            int match_length = 1;
            for (int next = row + 1; next < size; next++) {
                if (board[next][col] != board[row][col]) {
                    break;
                }
                match_length++;
            }

            if (match_length == 3) {
                match_found = true;
                for (int clear_row = row; clear_row < row + match_length; clear_row++) {
                    grid[clear_row][col] = true;
                }
            }
            else if (match_length == 4) {
                match_found = true;
                for (int clear_row = 0; clear_row < size; clear_row++) {
                    grid[clear_row][col] = true;
                }
            }
            else if (match_length >= 5) {
                match_found = true;
                clear_board = true;
            }
        }
    }

    if (clear_board) {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                // -1 on means that we will clear those candies
                board[row][col] = -1;
            }
        }
    }
    else {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (grid[row][col] == true) {
                    board[row][col] = -1;
                }
            }
        }
    }

    return match_found;
}

void collapseAndRefill(int board[10][10], int size, int candyTypes) {
    for (int col = 0; col < size; col++) {
        int move_candy_place = size - 1;

        for (int row = size - 1; row >= 0; row--) {
            if (board[row][col] != -1) {
                board[move_candy_place][col] = board[row][col];
                move_candy_place--;
            }
        }

        for (int row = move_candy_place; row >= 0; row--) {
            board[row][col] = rand() % candyTypes;
        }
    }
}
