#include <SFML/Graphics.hpp>
#include <prototype.h>

bool candyMatch(int board[10][10], int size)
{
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

            if (match_length >= 3) {
                match_found = true;

                if (match_length >= 5) {
                    clear_board = true;
                }
                else if (match_length == 4) {
                    // every match is replaced by 1
                    for (int clear_col = 0; clear_col < size; clear_col++) {
                        grid[row][clear_col] = true;
                        // here [row] is the row number where 4 candies are matcherd
                        // and [clear_col] starts from 0 to end of col/row
                    }
                }
                else { // these conditions are for length = 3
                    for (int match_col = col; match_col < col + match_length; ++match_col) {
                        grid[row][match_col] = true;
                    }
                }
            }

            // Skip the rest of this run because it has already been checked.
            col += match_length - 1;
        }
    }

    // Check each column for vertical matches.
    for (int col = 0; col < size; col++) {
        // Check each candy in this column as a possible start of a match.
        for (int row = 0; row < size; row++) {
            if (board[row][col] == -1) {
                continue;
            }

            int match_length = 1;
            // Count matching candies below this candy.
            for (int next_row = row + 1; next_row < size; next_row++) {
                if (board[next_row][col] != board[row][col]) {
                    break;
                }
                match_length++;
            }

            if (match_length >= 3) {
                match_found = true;

                if (match_length >= 5) {
                    clear_board = true;
                }
                else if (match_length == 4) {
                    // A vertical match of four marks every cell in its column.
                    for (int clear_row = 0; clear_row < size; ++clear_row) {
                        grid[clear_row][col] = true;
                    }
                }
                else {
                    // A vertical match of three marks only its matching cells.
                    for (int match_row = row; match_row < row + match_length; ++match_row) {
                        grid[match_row][col] = true;
                    }
                }
            }

            // Skip the rest of this run because it has already been checked.
            row += match_length - 1;
        }
    }

    if (clear_board) {
        // A match of five or more clears every cell on the board.
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                board[row][col] = -1;
            }
        }
    }
    else {
        // Otherwise, clear only the cells marked during the row and column scans.
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (grid[row][col]) {
                    board[row][col] = -1;
                }
            }
        }
    }

    return match_found;
}
