#include "GuiSplash.h"

GuiSplash::GuiSplash(Game *newGame) {
    game = newGame;

    title.setString("gui-lib demo");
    title.setColor(sf::Color(255, 255, 255));
    title.move(sf::Vector2f(20, 20));

    newGameButton = new Button(newGame, "New game", 60, 60);
    exitButton = new Button(newGame, "Exit", 60, 100);
}
GuiSplash::~GuiSplash() {
    delete newGameButton;
    delete exitButton;
}

void GuiSplash::onEvent(sf::Event &event) {
    if (newGameButton->onEvent(event)) {
        game->changeGui(new GuiNewGame(game));
    }
    else if (exitButton->onEvent(event)) {
        game->exit();
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
