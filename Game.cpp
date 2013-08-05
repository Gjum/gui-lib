#include "Game.h"

Game::Game(sf::RenderWindow *newWindow) {
    window = newWindow;
    font.loadFromFile("font.ttf");
    prevGui = 0;
    activeGui = 0;
}
Game::~Game() {
    if (prevGui != 0) delete prevGui;
    if (activeGui != 0) delete activeGui;
}

void Game::onEvent(sf::Event &event) {
    if (activeGui != 0) activeGui->onEvent(event);
}

void Game::onDraw() {
    if (activeGui != 0) activeGui->onDraw(*window);
}

void Game::changeGui(GuiBase *newGui) {
    if (prevGui != 0) delete prevGui;
    prevGui = activeGui;
    activeGui = newGui;
}

sf::Font &Game::getFont() {
    return font;
}

void Game::exit() {
    window->close();
}
