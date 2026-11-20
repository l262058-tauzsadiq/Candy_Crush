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

void displayHowtoPlay(sf::RenderWindow&window_screen)
{
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
