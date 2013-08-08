#include "Label.h"

Label::Label(MainClass *newMainClass, std::string newTitle,
             int newXPos, int newYPos, unsigned int newSize) {
    title.setString(newTitle);
    title.setFont(newMainClass->getFont());
    title.setCharacterSize(newSize);
    title.setPosition(sf::Vector2f(newXPos, newYPos));
}
Label::~Label() {
}

void Label::onDraw(sf::RenderTarget &target) const {
    target.draw(title);
}

void Label::setPosition(unsigned int x, unsigned int y) {
    title.setPosition(x, y);
}
void Label::setText(std::string text) {
    title.setString(text);
}
