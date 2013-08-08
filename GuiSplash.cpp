#include "GuiSplash.h"

GuiSplash::GuiSplash(MainClass *newMainClass) {
    mainClass = newMainClass;

    title.setString("gui-lib demo");
    title.setCharacterSize(20);
    title.setColor(sf::Color(255, 255, 255));
    title.move(sf::Vector2f(20, 20));
    title.setFont(newMainClass->getFont());

    newGameButton = new Button(newMainClass, "New game", 60, 60);
    exitButton = new Button(newMainClass, "Exit", 60, 100);
}
GuiSplash::~GuiSplash() {
    delete newGameButton;
    delete exitButton;
}

void GuiSplash::onEvent(sf::Event &event) {
    if (newGameButton->onEvent(event)) {
        mainClass->changeGui(new GuiNewGame(mainClass));
    }
    else if (exitButton->onEvent(event)) {
        mainClass->exit();
    }
    else {
        // no button pressed
    }
}

void GuiSplash::onDraw(sf::RenderTarget &target) {
    sf::RectangleShape background(sf::Vector2f(target.getSize().x, target.getSize().y));
    background.setFillColor(sf::Color(0, 0, 0));
    target.draw(background);

    newGameButton->onDraw(target);
    exitButton->onDraw(target);

    target.draw(title);
}
