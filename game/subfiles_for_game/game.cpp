// #include<SFML/Graphics.hpp>
// using namespace std;

// const int rows=8;
// const int cols=8;
// int board[rows][cols];

// sf::Texture redTexture;
// sf::Texture orangeTexture;
// sf::Texture blueTexture;
// sf::Texture greenTexture;
// sf::Texture purpleTexture;
// void loadCandyTextures()              // didn't add this function in prototype.h yet!
// {
//     redTexture.loadFromFile("assets/redcandy.png");
//     orangeTexture.loadFromFile("assets/orangecandy.png");
//     blueTexture.loadFromFile("assets/bluecandy.png");
//     greenTexture.loadFromFile("assets/greencandy.png");
//     purpleTexture.loadFromFile("assets/purplecandy.png");
// }
// void initializeBoard()
// {
//     for(int i=0;i<rows;i++)
//     {
//         for(int j=0;j<cols;j++)
//         {
//             board[i][j]=(i+j)%5;             // gives a number between 0 and 4
//         }                                    // there are 5 candies , i let one candy = one digit
//     }
// }
// void drawBoard(sf::RenderWindow& window)
// {
//     for(int i=0;i<rows;i++)
//     {
//         for(int j=0;j<cols;j++)
//         {
//             sf::Sprite candy;
//             if(board[i][j]==0)
//             {
//                 candy.setTexture(redTexture);
//             }
//             else if(board[i][j]==1)
//             {
//                 candy.setTexture(blueTexture);
//             }
//             else if(board[i][j]==2)
//             {
//                 candy.setTexture(orangeTexture);
//             }
//             else if(board[i][j]==3)
//             {
//                 candy.setTexture(greenTexture);
//             }
//             else
//             {
//                 candy.setTexture(purpleTexture);
//             }
//         }
//     }   
// }