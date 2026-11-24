// here we have to write the prototypes of the functions we are going to use in this project

// bg.cpp
void background(sf::RenderWindow& window_screen);
// menu.cpp
void displayMainMenu(sf::RenderWindow& window_screen);
// how_to_play.cpp
void displayHowtoPlay(sf::RenderWindow&window_screen);
//  difficulty.cpp
void displayDifficultyLevel(sf::RenderWindow& window_screen);
// game.cpp
void initializeBoard(int board[10][10], int size, int candyTypes);
void displayBoard(sf::RenderWindow& window_screen, int board[10][10], int size);
bool candyMatch(int board[10][10], int size);
