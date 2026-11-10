#include <SFML/Graphics.hpp>
#include <iostream>
#include "prototype.h"
using namespace std;

int main(){

    // testing if pull works or not
    
    // here game_window is the object name and before that RenderWindow is a class 
    // these concepts will be studied in 2nd semester so leave it for now
    // just keep in mind that we will write object name using '_' to identify them
    sf::RenderWindow game_window(sf::VideoMode(1200, 800), "Candy Crush");

    while (game_window.isOpen())
    {
        sf::Event closing_check; // similarly this closing_check is also a name for obj

        while (game_window.pollEvent(closing_check))
        {
            if (closing_check.type == sf::Event::Closed){
                game_window.close();
            }
        }

        game_window.clear(sf::Color::Black);
        game_window.display();
    }

    return 0;
}
