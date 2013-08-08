#include "Label.h"

Label::Label(MainClass *newMainClass, std::string newTitle,
             int newXPos, int newYPos, unsigned int newSize) {
    title.setString(newTitle);
    title.setFont(newMainClass->getFont());
    title.setCharacterSize(newSize);
    title.move(sf::Vector2f(newXPos, newYPos));
}
Label::~Label() {
}

void Label::onDraw(sf::RenderTarget &target) const {
    target.draw(title);
}
