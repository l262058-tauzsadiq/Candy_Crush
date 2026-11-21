#include <SFML/Graphics.hpp>
#include <iostream>
#include <prototype.h>
using namespace std;

void displayHowtoPlay(sf::RenderWindow&window_screen)
{
    window_screen.clear(sf::Color::Black);
    background(window_screen);

    sf::Font font_bold;
    font_bold.loadFromFile("assets/font-bold.ttf");
    sf::Text heading("How to Play", font_bold, 60);
    heading.setPosition(240.f,100.f);
    heading.setFillColor(sf::Color(255,215,0));
    heading.setOutlineColor(sf::Color(178,34,34));
    heading.setOutlineThickness(3.0f);
    window_screen.draw(heading);
    sf::Text instruction1("1. Select a candy by clicking on it", font_bold, 28);
    instruction1.setPosition(100.f,230.f);
    instruction1.setFillColor(sf::Color::White);
    instruction1.setOutlineColor(sf::Color(178, 34, 34));
    instruction1.setOutlineThickness(1.5f);
    window_screen.draw(instruction1);
    sf::Text instruction2("2. Swap it with a nearby candy", font_bold, 28);
    instruction2.setPosition(100.f,290.f);
    instruction2.setFillColor(sf::Color::White);
    instruction2.setOutlineColor(sf::Color(178, 34, 34));
    instruction2.setOutlineThickness(1.5f);
    window_screen.draw(instruction2);
    sf::Text instruction3("3. Match three or more identical candies", font_bold, 28);
    instruction3.setPosition(100.f,350.f);
    instruction3.setFillColor(sf::Color::White);
    instruction3.setOutlineColor(sf::Color(178, 34, 34));
    instruction3.setOutlineThickness(1.5f);
    window_screen.draw(instruction3);
    sf::Text instruction4("4. Matches can be horizontally, vertically", font_bold, 28);
    instruction4.setPosition(100.f,410.f);
    instruction4.setFillColor(sf::Color::White);
    instruction4.setOutlineColor(sf::Color(178, 34, 34));
    instruction4.setOutlineThickness(1.5f);
    window_screen.draw(instruction4);
    sf::Text instruction5(" or diagonally", font_bold, 28);
    instruction5.setPosition(100.f,450.f);
    instruction5.setFillColor(sf::Color::White);
    instruction5.setOutlineColor(sf::Color(178, 34, 34));
    instruction5.setOutlineThickness(1.5f);
    window_screen.draw(instruction5);
//back button
    sf::RectangleShape back_button(sf::Vector2f(150.f,50.f));
    back_button.setFillColor(sf::Color(255,215,0));
    back_button.setOutlineColor(sf::Color(178,34,34));
    back_button.setOutlineThickness(3.0f);
    back_button.setPosition(300.f,550.f);
    window_screen.draw(back_button);

    sf::Text back_text("Back",font_bold,35);
    back_text.setFillColor(sf::Color::White);
    back_text.setPosition(345.f,555.f);
    back_text.setOutlineColor(sf::Color(178, 34, 34));
    back_text.setOutlineThickness(1.5f);
    window_screen.draw(back_text);
}