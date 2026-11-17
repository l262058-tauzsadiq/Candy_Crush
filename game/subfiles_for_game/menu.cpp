#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

void displayMainMenu (sf::RenderWindow& window_screen){
    sf::Font font_bold;
    font_bold.loadFromFile("assets/font-bold.ttf");
    // not using .. before assets because we have to check the
    // path from main.cpp

    sf::Text text_to_display("Candy Crush", font_bold, 80);

    text_to_display.setFillColor(sf::Color::Red);
    text_to_display.setPosition(165.f, 150.f);
    text_to_display.setFillColor(sf::Color(255, 215, 0));
    text_to_display.setOutlineColor(sf::Color(178, 34, 34));
    text_to_display.setOutlineThickness(3.0f);
    window_screen.draw(text_to_display);
    
    sf::RectangleShape buttons_bg_1(sf::Vector2f(215, 50));

    buttons_bg_1.setFillColor(sf::Color(255, 215, 0));
    buttons_bg_1.setOutlineColor(sf::Color(178, 34, 34));
    buttons_bg_1.setOutlineThickness(3);
    buttons_bg_1.setPosition(255.f, 350.f);
    window_screen.draw(buttons_bg_1);
    
    text_to_display.setString("Start Game");
    text_to_display.setFillColor(sf::Color::White);
    text_to_display.setPosition(270.f, 350.f);
    text_to_display.setCharacterSize(40);
    text_to_display.setFont(font_bold); // no need to add this statement down
    window_screen.draw(text_to_display);

    sf::RectangleShape buttons_bg_2(sf::Vector2f(225, 50));

    buttons_bg_2.setFillColor(sf::Color(255, 215, 0));
    buttons_bg_2.setOutlineColor(sf::Color(178, 34, 34));
    buttons_bg_2.setOutlineThickness(3);
    buttons_bg_2.setPosition(250.f, 465.f);
    window_screen.draw(buttons_bg_2);

    text_to_display.setString("How to Play");
    text_to_display.setPosition(265.f, 465.f);
    window_screen.draw(text_to_display);

    sf::RectangleShape buttons_bg_3(sf::Vector2f(90, 50));

    buttons_bg_3.setFillColor(sf::Color(255, 215, 0));
    buttons_bg_3.setOutlineColor(sf::Color(178, 34, 34));
    buttons_bg_3.setOutlineThickness(3);
    buttons_bg_3.setPosition(315.f, 580.f);
    window_screen.draw(buttons_bg_3);

    text_to_display.setString("Exit");
    text_to_display.setPosition(330.f, 580.f);
    window_screen.draw(text_to_display);

    // clicking actions

    sf::FloatRect area_1 = buttons_bg_1.getGlobalBounds();
    sf::FloatRect area_2 = buttons_bg_2.getGlobalBounds();
    sf::FloatRect area_3 = buttons_bg_3.getGlobalBounds();

    // i was facing a problem that whenever i click once in the area, the program was calling the 
    // functions startGame() and seeInstructions multiple time. therefore i am using a boolean value
    bool mouse_is_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    static bool mouse_was_pressed = false; 
    // static makes the variable lifetime upto termination of program

    if(mouse_is_pressed && !mouse_was_pressed){
        sf::Vector2i click_position = sf::Mouse::getPosition(window_screen);

        if(area_1.contains(float(click_position.x), float(click_position.y))){
            // startGame(window_screen);
            cout << "area 1 working perfectly" << endl;
        }
        if(area_2.contains(float(click_position.x), float(click_position.y))){
            // seeInstructions(window_screen);
            cout << "area 2 working perfectly" << endl;
        }
        if(area_3.contains(float(click_position.x), float(click_position.y))){
            window_screen.close();
        }
    }
    mouse_was_pressed = mouse_is_pressed;
}

