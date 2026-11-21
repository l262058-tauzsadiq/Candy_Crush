#include <SFML/Graphics.hpp>
#include <iostream>
#include "prototype.h"
using namespace std;

int main(){
    bool menu_open = true;
    bool instructions_open = false;
    bool game_open = false;

    sf::RenderWindow game_window(sf::VideoMode(750, 900), "Candy Crush");
    //loadCandyTextures();
    //initializeBoard();
    while (game_window.isOpen())
    {
        sf::Event click_check;

        while (game_window.pollEvent(click_check))
        {
            if (click_check.type == sf::Event::Closed){
                game_window.close();
            }
            else if (click_check.type == sf::Event::MouseButtonPressed && click_check.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f click_position = game_window.mapPixelToCoords(sf::Vector2i(click_check.mouseButton.x, click_check.mouseButton.y));

                if(menu_open){
                    if (sf::FloatRect(255.f, 350.f, 215.f, 50.f).contains(click_position.x, click_position.y)) {
                        menu_open = false;
                        game_open = true;
                    }
                    if (sf::FloatRect(250.f, 465.f, 225.f, 50.f).contains(click_position.x, click_position.y)) {
                        menu_open = false;
                        instructions_open = true;
                    }
                    if (sf::FloatRect(315.f, 580.f, 90.f, 50.f).contains(click_position.x, click_position.y)) {
                        game_window.close();
                    }
                }

                // if(game_open){

                // }

                if(instructions_open){
                    if (sf::FloatRect(300.f, 550.f, 150.f, 50.f).contains(click_position.x, click_position.y)) {
                        menu_open = true;
                        instructions_open = false;
                    }
                }
            }
        }

        if (!game_window.isOpen()) {
            break;
        }
        
        if(menu_open){
            displayMainMenu(game_window);
        }
        if(game_open){
            displayDifficultyLevel(game_window);
        }
        if (instructions_open) {
            displayHowtoPlay(game_window);
        }

        game_window.display();
    }

    return 0;
}
