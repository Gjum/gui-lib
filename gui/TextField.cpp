#include "TextField.h"

TextField::TextField(MainClass *newMainClass, int newXPos, int newYPos) {
    init(newMainClass, newXPos, newYPos, 200, 30);
}
TextField::TextField(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight) {
    init(newMainClass, newXPos, newYPos, newWidth, newHeight);
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
           ) {
            active = true;
            // TODO set caret position
            caretPos = title.getString().getSize();
            while (title.findCharacterPos(caretPos).x > event.mouseButton.x
                    && caretPos > 0)
                caretPos--;
        }
        else active = false;
    }
    else if (active && event.type == sf::Event::TextEntered) {
        if (event.text.unicode <= 126 && event.text.unicode >= 32) { // printable ASCII
            std::string str = title.getString();
            title.setString(str.substr(0, caretPos)
                            + static_cast<char>(event.text.unicode)
                            + str.substr(caretPos, str.size() - 1));
            caretPos++;
        }
    }
    else if (event.type == sf::Event::KeyPressed) {
        std::string str = title.getString();
        if (event.key.code == sf::Keyboard::Key::BackSpace && caretPos > 0) {
            title.setString(str.substr(0, caretPos - 1)
                            + str.substr(caretPos, str.size() - 1));
            caretPos--;
        }
        else if (event.key.code == sf::Keyboard::Key::Delete && caretPos < str.size()) {
            title.setString(str.substr(0, caretPos)
                            + str.substr(caretPos + 1, str.size() - 1));
        }
        else if (event.key.code == sf::Keyboard::Key::Right && caretPos < str.size())
            caretPos++;
        else if (event.key.code == sf::Keyboard::Key::Left && caretPos > 0)
            caretPos--;
        else if (event.key.code == sf::Keyboard::Key::Home)
            caretPos = 0;
        else if (event.key.code == sf::Keyboard::Key::End)
            caretPos = str.size();
    }
}
void TextField::onDraw(sf::RenderTarget &target) const {
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setPosition(xPos, yPos);
    background.setFillColor(sf::Color(0, 0, 0, 128));
    background.setOutlineThickness(2);
    if (active) background.setOutlineColor(sf::Color(0, 0, 255, 255));
    else background.setOutlineColor(sf::Color(0, 0, 255, 128));
    target.draw(background);

    target.draw(title);

    if (active) {
        sf::RectangleShape caret(sf::Vector2f(2, title.getCharacterSize()));
        caret.setPosition(title.findCharacterPos(caretPos));
        caret.setFillColor(sf::Color(255, 255, 255));
        target.draw(caret);
    }
}

std::string TextField::getContent() const {
    return title.getString();
}

void TextField::setContent(std::string newString) {
    title.setString(newString);
    if (caretPos > newString.size()) caretPos = newString.size();
}

void TextField::init(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight) {
    xPos = newXPos;
    yPos = newYPos;
    width = newWidth;
    height = newHeight;

    title.setFont(newMainClass->getFont());
    title.setCharacterSize(15);
    title.setPosition(xPos + title.getCharacterSize() / 2.0, yPos + height / 2.0 - title.getCharacterSize() / 2.0);

    active = false;
    caretPos = 0;
}
