#include "GuiNewGame.h"

GuiNewGame::GuiNewGame(Game *newGame) {
    game = newGame;

    title.setString("New game");
    title.setColor(sf::Color(255, 255, 255));
    title.move(sf::Vector2f(20, 20));

    playerName = new TextField(newGame, 60, 60);
    checkbox = new Checkbox(newGame, 60, 100);
    startGameButton = new Button(newGame, "Start game", 60, 140);
    cancelButton = new Button(newGame, "Cancel", 60, 180);
}
GuiNewGame::~GuiNewGame() {
    delete playerName;
    delete checkbox;
    delete startGameButton;
    delete cancelButton;
}

void GuiNewGame::onEvent(sf::Event &event) {
    playerName->onEvent(event);
    checkbox->onEvent(event);

    if (startGameButton->onEvent(event)) {
        // TODO add functionality
    }
    else if (cancelButton->onEvent(event)) {
        game->changeGui(new GuiSplash(game));
    }
    else {
        // no button pressed
    }
}

void GuiNewGame::onDraw(sf::RenderTarget &target) {
    sf::RectangleShape background(sf::Vector2f(target.getSize().x, target.getSize().y));
    background.setFillColor(sf::Color(0, 0, 0));
    target.draw(background);

    playerName->onDraw(target);
    checkbox->onDraw(target);
    startGameButton->onDraw(target);
    cancelButton->onDraw(target);

    target.draw(title);
}
