#include "GuiNewGame.h"

GuiNewGame::GuiNewGame(MainClass *newMainClass) {
    mainClass = newMainClass;

    title = new Label(mainClass, "Some inputs", 100, 20, 20);
    playerName = new TextField(newMainClass, 60, 60);
    checkbox = new Checkbox(newMainClass, 60, 100);
    fader = new Fader(newMainClass, 100, 100, 160, 0, 255);
    cancelButton = new Button(newMainClass, "Main menu", 60, 140);
}
GuiNewGame::~GuiNewGame() {
    delete title;
    delete playerName;
    delete checkbox;
    delete fader;
    delete cancelButton;
}

void GuiNewGame::onEvent(sf::Event &event) {
    playerName->onEvent(event);
    checkbox->onEvent(event);
    fader->onEvent(event);

    if (cancelButton->onEvent(event)) {
        mainClass->changeGui(new GuiSplash(mainClass));
    }
}

void GuiNewGame::onDraw(sf::RenderTarget &target) {
    sf::RectangleShape background(sf::Vector2f(target.getSize().x, target.getSize().y));
    if (checkbox->isEnabled()) background.setFillColor(sf::Color(0, fader->getValue(), 0));
    else background.setFillColor(sf::Color(fader->getValue(), 0, 0));
    target.draw(background);

    title->onDraw(target);
    playerName->onDraw(target);
    checkbox->onDraw(target);
    fader->onDraw(target);
    cancelButton->onDraw(target);
}
