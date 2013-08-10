#include "Button.h"

Button::Button(MainClass *newMainClass, std::string newTitle, int newXPos, int newYPos) {
    init(newMainClass, newTitle, newXPos, newYPos, 200, 30);
}
Button::Button(MainClass *newMainClass, std::string newTitle, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight) {
    init(newMainClass, newTitle, newXPos, newYPos, newWidth, newHeight);
}
Button::~Button() {
}

// returns true if clicked
bool Button::onEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseMoved) {
        if (event.mouseMove.x > xPos
                && event.mouseMove.x < xPos + width
                && event.mouseMove.y > yPos
                && event.mouseMove.y < yPos + height
           ) hovering = true;
        else hovering = false;
    }

    if (hovering
            && event.type == sf::Event::MouseButtonPressed
            && event.mouseButton.button == sf::Mouse::Left
       ) return true;

    return false;
}
void Button::onDraw(sf::RenderTarget &target) const {
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setOrigin(-xPos, -yPos);
    background.setOutlineColor(sf::Color(0, 0, 0));
    background.setOutlineThickness(2);
    if (hovering) background.setFillColor(sf::Color(0, 0, 255, 255));
    else background.setFillColor(sf::Color(0, 0, 255, 128));

    target.draw(background);

    target.draw(title);
}

void Button::init(MainClass *newMainClass, std::string newTitle, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight) {
    xPos = newXPos;
    yPos = newYPos;
    width = newWidth;
    height = newHeight;

    title.setString(newTitle);
    title.setFont(newMainClass->getFont());
    title.setCharacterSize(15);
    title.setOrigin(title.findCharacterPos(title.getString().getSize()).x / 2.0, title.getCharacterSize() / 2.0);
    title.setPosition(xPos + width / 2.0, yPos + height / 2.0);

    hovering = false;
}
