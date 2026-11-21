#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

void displayDifficultyLevel (sf::RenderWindow& window_screen)
{
    sf::Font font_bold;
    font_bold.loadFromFile("assets/font-bold.ttf");

    sf::Text text_to_display("Select Difficulty Level", font_bold, 60);
    text_to_display.setPosition(80.f, 150.f);
    text_to_display.setFillColor(sf::Color(255, 215, 0));
    text_to_display.setOutlineColor(sf::Color(178, 34, 34));
    text_to_display.setOutlineThickness(3.0f);
    window_screen.draw(text_to_display);
    
    sf::RectangleShape buttons_bg_1(sf::Vector2f(215, 60));

    buttons_bg_1.setFillColor(sf::Color(255, 215, 0));
    buttons_bg_1.setOutlineColor(sf::Color(178, 34, 34));
    buttons_bg_1.setOutlineThickness(3);
    buttons_bg_1.setPosition(267.f, 350.f);
    window_screen.draw(buttons_bg_1);
    
    text_to_display.setString("Easy");
    text_to_display.setFillColor(sf::Color::White);
    text_to_display.setCharacterSize(40);
    text_to_display.setPosition(335.f, 355.f);
    window_screen.draw(text_to_display);

    sf::RectangleShape buttons_bg_2(sf::Vector2f(215, 60));

    buttons_bg_2.setFillColor(sf::Color(255, 215, 0));
    buttons_bg_2.setOutlineColor(sf::Color(178, 34, 34));
    buttons_bg_2.setOutlineThickness(3);
    buttons_bg_2.setPosition(267.f, 465.f);
    window_screen.draw(buttons_bg_2);

    text_to_display.setString("Medium");
    text_to_display.setPosition(300.f, 470.f);
    window_screen.draw(text_to_display);

    sf::RectangleShape buttons_bg_3(sf::Vector2f(215, 60));

    buttons_bg_3.setFillColor(sf::Color(255, 215, 0));
    buttons_bg_3.setOutlineColor(sf::Color(178, 34, 34));
    buttons_bg_3.setOutlineThickness(3);
    buttons_bg_3.setPosition(267.f, 580.f);
    window_screen.draw(buttons_bg_3);

    text_to_display.setString("Hard");
    text_to_display.setPosition(333.f, 585.f);
    window_screen.draw(text_to_display);
}