#include <SFML/Graphics.hpp>
#include <iostream>
#include "prototype.h"
using namespace std;

int main(){
    sf::RenderWindow game_window(sf::VideoMode(750, 900), "Candy Crush");
    loadCandyTextures();
    initializeBoard();
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
        displayMainMenu(game_window);

        game_window.display();
    }

    return 0;
}
