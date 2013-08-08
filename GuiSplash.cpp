#include "GuiSplash.h"

GuiSplash::GuiSplash(MainClass *newMainClass) {
    mainClass = newMainClass;

    title = new Label(mainClass, "gui-lib demo", 100, 20, 20);
    newGameButton = new Button(newMainClass, "New game", 60, 60);
    exitButton = new Button(newMainClass, "Exit", 60, 100);
}
GuiSplash::~GuiSplash() {
    delete title;
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
}

void GuiSplash::onDraw(sf::RenderTarget &target) {
    sf::RectangleShape background(sf::Vector2f(target.getSize().x, target.getSize().y));
    background.setFillColor(sf::Color(0, 0, 0));
    target.draw(background);

    newGameButton->onDraw(target);
    exitButton->onDraw(target);

    title->onDraw(target);
}
