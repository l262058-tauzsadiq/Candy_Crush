#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "prototype.h"
using namespace std;

int main(){
    bool menu_open = true;
    bool instructions_open = false;
    bool difficulty_open = false;
    bool game_start = false;

    int candy_type, size;

    sf::RenderWindow game_window(sf::VideoMode(750, 900), "Candy Crush");
    //loadCandyTextures();
    //initializeBoard();

    // i have used random function but everytime it used to generate 
    // same board therefore using this function
    srand(static_cast<unsigned int>(time(nullptr)));

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
                        difficulty_open = true;
                    }
                    if (sf::FloatRect(250.f, 465.f, 225.f, 50.f).contains(click_position.x, click_position.y)) {
                        menu_open = false;
                        instructions_open = true;
                    }
                    if (sf::FloatRect(315.f, 580.f, 90.f, 50.f).contains(click_position.x, click_position.y)) {
                        game_window.close();
                    }
                }

                else if (difficulty_open) {
                    if (sf::FloatRect(267.f, 350.f, 215.f, 60.f).contains(click_position.x, click_position.y)) {
                        difficulty_open = false;
                        game_start = true;
                        candy_type = 3;
                        size = 5;
                    }
                    else if (sf::FloatRect(267.f, 465.f, 215.f, 60.f).contains(click_position.x, click_position.y)) {
                        difficulty_open = false;
                        game_start = true;
                        candy_type = 4;
                        size = 8;
                    }
                    else if (sf::FloatRect(267.f, 580.f, 215.f, 60.f).contains(click_position.x, click_position.y)) {
                        difficulty_open = false;
                        game_start = true;
                        candy_type = 5;
                        size = 10;
                    }
                }

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
        else if(difficulty_open){
            displayDifficultyLevel(game_window);
        }
        if (instructions_open) {
            displayHowtoPlay(game_window);
        }

        if(game_start){
            initializeBoard(size, candy_type);
            // i have added this because after one game start the board was
            // generated continously because game start was set to be true
            game_start = false;
        }

        game_window.display();
    }

    return 0;
}
