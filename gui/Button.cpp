#include "Button.h"

Button::Button() {
    Button(-1, 0, 0, 100, 50, "Button");
}
Button::Button(int newID, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight, std::string newTitle) {
    id = newID;
    xPos = newXPos;
    yPos = newYPos;
    width = newWidth;
    height = newHeight;
    title.setString(newTitle);
    hovering = false;
}
Button::~Button() {
}

void Button::setGuiManager(GuiManager* guiManager) {
    title.setFont(guiManager->getFont());
    title.setCharacterSize(15);
    title.setOrigin(sf::Vector2f(title.findCharacterPos(title.getString().getSize()).x / 2.0, title.getCharacterSize() / 2.0));
    title.move(sf::Vector2f(xPos + width / 2.0, yPos + height / 2.0));
}

// returns true if clicked
bool Button::onEvent(sf::Event event) {
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
       )
        return true;

    return false;
}
void Button::draw(sf::RenderTarget& window) const {
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setOrigin(-xPos, -yPos);
    background.setOutlineColor(sf::Color(0, 0, 0));
    background.setOutlineThickness(2);

    if (hovering) background.setFillColor(sf::Color(0, 0, 255, 255));
    else background.setFillColor(sf::Color(0, 0, 255, 128));

    window.draw(background);

    window.draw(title);
}
int Button::getID() const {
    return id;
}
