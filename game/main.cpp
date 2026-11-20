#include <SFML/Graphics.hpp>
#include <iostream>
#include "prototype.h"
using namespace std;

int main(){
    sf::RenderWindow game_window(sf::VideoMode(750, 900), "Candy Crush");
    //loadCandyTextures();
    //initializeBoard();
    while (game_window.isOpen())
    {
        sf::Event closing_check;

        while (game_window.pollEvent(closing_check))
        {
            if (closing_check.type == sf::Event::Closed){
                game_window.close();
            }
        }
        
        game_window.clear(sf::Color::Black);

        background(game_window);
       // displayMainMenu(game_window);
        displayHowtoPlay(game_window);                 // i was testing the code that's why i commented these
      // displayDifficultyLevel (game_window);         // i don't know how to add screens , hope that you will handle all that stuff
        game_window.display();
    }

    return 0;
}
