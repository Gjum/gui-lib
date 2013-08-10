#include "Label.h"

Label::Label(MainClass *newMainClass, std::string newTitle,
             int newXPos, int newYPos, unsigned int newSize) {
    init(newMainClass, newTitle, newXPos, newYPos, newSize, TOP_LEFT);
}
Label::Label(MainClass *newMainClass, std::string newTitle,
             int newXPos, int newYPos,
             unsigned int newSize, GuiLabelAlign newAlign) {
    init(newMainClass, newTitle, newXPos, newYPos, newSize, newAlign);
}
Label::~Label() {
}

void Label::onDraw(sf::RenderTarget &target) const {
    target.draw(title);
}

void Label::setPosition(unsigned int x, unsigned int y) {
    title.setPosition(x, y);
    realign();
}
void Label::setText(std::string text) {
    title.setString(text);
    realign();
}

void Label::init(MainClass *newMainClass, std::string newTitle,
                 int newXPos, int newYPos,
                 unsigned int newSize, GuiLabelAlign newAlign) {
    title.setString(newTitle);
    title.setFont(newMainClass->getFont());
    title.setCharacterSize(newSize);
    title.setPosition(newXPos, newYPos);

    align = newAlign;

    realign();
}

void Label::realign() {
    sf::Vector2f oldPos = title.getPosition();

    title.setPosition(0, 0);

    if (align == TOP_LEFT)
        title.setOrigin(0, 0);
    else if (align == TOP_CENTER)
        title.setOrigin(title.findCharacterPos(title.getString().getSize()).x / 2.0, 0);
    else if (align == TOP_RIGHT)
        title.setOrigin(title.findCharacterPos(title.getString().getSize()).x, 0);

    else if (align == MIDDLE_LEFT)
        title.setOrigin(0, title.getCharacterSize() / 2.0);
    else if (align == MIDDLE_CENTER)
        title.setOrigin(title.findCharacterPos(title.getString().getSize()).x / 2.0, title.getCharacterSize() / 2.0);
    else if (align == MIDDLE_RIGHT)
        title.setOrigin(title.findCharacterPos(title.getString().getSize()).x, title.getCharacterSize() / 2.0);

    else if (align == BOTTOM_LEFT)
        title.setOrigin(0, title.getCharacterSize());
    else if (align == BOTTOM_CENTER)
        title.setOrigin(title.findCharacterPos(title.getString().getSize()).x / 2.0, title.getCharacterSize());
    else if (align == BOTTOM_RIGHT)
        title.setOrigin(title.findCharacterPos(title.getString().getSize()).x, title.getCharacterSize());

    title.setPosition(oldPos);
}
