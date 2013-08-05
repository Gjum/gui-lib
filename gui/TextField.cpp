#include "TextField.h"

TextField::TextField(Game *newGame, int newXPos, int newYPos) {
}
TextField::TextField(Game *newGame, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight) {
    xPos = newXPos;
    yPos = newYPos;
    width = newWidth;
    height = newHeight;

    title.setFont(newGame->getFont());
    title.setCharacterSize(15);
    title.move(sf::Vector2f(xPos + title.getCharacterSize() / 2.0, yPos + height / 2.0 - title.getCharacterSize() / 2.0));

    active = false;
}
TextField::~TextField() {
}

void TextField::onEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed
            && event.mouseButton.button == sf::Mouse::Left
       ) {
        if (event.mouseButton.x > xPos
                && event.mouseButton.x < xPos + width
                && event.mouseButton.y > yPos
                && event.mouseButton.y < yPos + height
           ) active = true;
        else active = false;
    }
    else if (active && event.type == sf::Event::TextEntered) {
        std::string newText = title.getString();
        if (event.text.unicode == 8) {
            newText = newText.substr(0, newText.size()-1);
        }
        else if (event.text.unicode <= 126 && event.text.unicode >= 32) {
            newText += static_cast<char>(event.text.unicode);
        }

        title.setString(newText);
    }
}
void TextField::onDraw(sf::RenderTarget &target) const {
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setOrigin(-xPos, -yPos);
    background.setFillColor(sf::Color(0, 0, 0, 0));
    background.setOutlineThickness(2);
    if (active) background.setOutlineColor(sf::Color(0, 0, 255, 255));
    else background.setOutlineColor(sf::Color(0, 0, 255, 128));

    target.draw(background);

    target.draw(title);
}

std::string TextField::getContent() const {
    return title.getString();
}
