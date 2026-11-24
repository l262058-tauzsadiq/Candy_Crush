#include <SFML/Graphics.hpp>

void background(sf::RenderWindow& window_screen){
    sf::Texture bg_img;
    bg_img.loadFromFile("assets/bg_image.png");
    sf::Sprite bg;
    bg.setTexture(bg_img);

    // resizing the image
    bg.setScale(750.0f / bg_img.getSize().x, 900.0f / bg_img.getSize().y);

    window_screen.draw(bg);
}
