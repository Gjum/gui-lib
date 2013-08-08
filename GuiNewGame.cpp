#include "GuiNewGame.h"

GuiNewGame::GuiNewGame(MainClass *newMainClass) {
    mainClass = newMainClass;

    title.setString("Some inputs");
    title.setColor(sf::Color(255, 255, 255));
    title.move(sf::Vector2f(20, 20));
    title.setCharacterSize(20);
    title.setFont(newMainClass->getFont());

    playerName = new TextField(newMainClass, 60, 60);
    checkbox = new Checkbox(newMainClass, 60, 100);
    fader = new Fader(newMainClass, 100, 100, 160, 0, 255);
    startGameButton = new Button(newMainClass, "Start game", 60, 140);
    cancelButton = new Button(newMainClass, "Cancel", 60, 180);
}
GuiNewGame::~GuiNewGame() {
    delete playerName;
    delete checkbox;
    delete fader;
    delete startGameButton;
    delete cancelButton;
}

void GuiNewGame::onEvent(sf::Event &event) {
    playerName->onEvent(event);
    checkbox->onEvent(event);
    fader->onEvent(event);

    if (startGameButton->onEvent(event)) {
        // TODO add functionality
    }
    else if (cancelButton->onEvent(event)) {
        mainClass->changeGui(new GuiSplash(mainClass));
    }
    else {
        // no button pressed
    }
}

void GuiNewGame::onDraw(sf::RenderTarget &target) {
    sf::RectangleShape background(sf::Vector2f(target.getSize().x, target.getSize().y));
    if (checkbox->isEnabled()) background.setFillColor(sf::Color(0, fader->getValue(), 0));
    else background.setFillColor(sf::Color(fader->getValue(), 0, 0));
    target.draw(background);

    playerName->onDraw(target);
    checkbox->onDraw(target);
    fader->onDraw(target);
    startGameButton->onDraw(target);
    cancelButton->onDraw(target);

    target.draw(title);
}
