#include "Checkbox.h"

Checkbox::Checkbox(MainClass *newMainClass, int newXPos, int newYPos) {
    init(newMainClass, newXPos, newYPos, 30, 30, false);
}
Checkbox::Checkbox(MainClass *newMainClass, int newXPos, int newYPos, bool newEnabled) {
    init(newMainClass, newXPos, newYPos, 30, 30, newEnabled);
}
Checkbox::Checkbox(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight) {
    init(newMainClass, newXPos, newYPos, newWidth, newHeight, false);
}
Checkbox::Checkbox(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight, bool newEnabled) {
    init(newMainClass, newXPos, newYPos, newWidth, newHeight, newEnabled);
}
Checkbox::~Checkbox() {
}

void Checkbox::onEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseMoved) {
        if (event.mouseMove.x > xPos
                && event.mouseMove.x < xPos + width
                && event.mouseMove.y > yPos
                && event.mouseMove.y < yPos + height
           ) hovering = true;
        else hovering = false;
    }
    else if (hovering
             && event.type == sf::Event::MouseButtonPressed
             && event.mouseButton.button == sf::Mouse::Left
            ) enabled = !enabled;
}
void Checkbox::onDraw(sf::RenderTarget &target) const {
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setPosition(xPos, yPos);
    background.setOutlineThickness(2);
    background.setOutlineColor(sf::Color(0, 0, 0, 255));
    if (hovering) {
        background.setFillColor(sf::Color(0, 0, 255, 255));
    }
    else {
        background.setFillColor(sf::Color(0, 0, 255, 128));
    }
    target.draw(background);

    if (enabled) {
        sf::RectangleShape dot(sf::Vector2f(width / 2, height / 2));
        dot.setPosition(sf::Vector2f(xPos + width / 4, yPos + height / 4));
        dot.setFillColor(sf::Color(0, 0, 0));
        target.draw(dot);
    }
}

bool Checkbox::isEnabled() const {
    return enabled;
}
void Checkbox::setEnabled(bool value) {
    enabled = value;
}

void Checkbox::init(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight, bool newEnabled) {
    xPos = newXPos;
    yPos = newYPos;
    width = newWidth;
    height = newHeight;
    enabled = newEnabled;

    hovering = false;
}
