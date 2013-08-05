#include "GuiSplash.h"

GuiSplash::GuiSplash(Game *newGame) {
    GuiBase::game = newGame;

    title.setString("Game menu");
    title.setColor(sf::Color(255, 255, 255));

    buttons.insert(buttons.end(), new Button(newGame, 0, "New game", 60, 60, 200, 30));
    buttons.insert(buttons.end(), new Button(newGame, 1, "Quit", 60, 100, 200, 30));
}
GuiSplash::~GuiSplash() {
    for (auto button : buttons) {
        delete button;
    }
}

void GuiSplash::onEvent(sf::Event &event) {
    int buttonID = -1;

    for (auto button : buttons) {
        if (button->onEvent(event)) {
            buttonID = button->getID();
            break;
        }
    }
    if (buttonID == 0) {
        // TODO add functionality
    }
    else if (buttonID == 1) {
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

    for (auto button : buttons) {
        button->onDraw(target);
    }

    target.draw(title);
}
