#include <SFML/Graphics.hpp>
#include <iostream>
#include "prototype.h"
using namespace std;

int main()

{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Candy Crush");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}