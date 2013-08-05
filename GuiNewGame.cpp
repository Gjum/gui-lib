#include "GuiNewGame.h"

GuiNewGame::GuiNewGame(Game *newGame) {
    game = newGame;

    title.setString("Game menu");
    title.setColor(sf::Color(255, 255, 255));

    playerName = new TextField(newGame, 60, 60, 200, 30);
    buttons.insert(buttons.end(), new Button(newGame, 0, "Start game", 60, 100, 200, 30));
    buttons.insert(buttons.end(), new Button(newGame, 1, "Cancel", 60, 140, 200, 30));
}
GuiNewGame::~GuiNewGame() {
    for (auto button : buttons) {
        delete button;
    }
    delete playerName;
}

void GuiNewGame::onEvent(sf::Event &event) {
    int buttonID = -1;

    for (auto button : buttons) {
        if (button->onEvent(event)) {
            buttonID = button->getID();
            break;
        }
    }
    playerName->onEvent(event);

    if (buttonID == 0) {
        // TODO add functionality
    }
    else if (buttonID == 1) {
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

    for (auto button : buttons) {
        button->onDraw(target);
    }

    playerName->onDraw(target);

    target.draw(title);
}
