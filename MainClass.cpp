#include "MainClass.h"

MainClass::MainClass(sf::RenderWindow *newWindow) {
    window = newWindow;
    font.loadFromFile("font.ttf");
    prevGui = 0;
    activeGui = 0;
}
MainClass::~MainClass() {
    if (prevGui != 0) delete prevGui;
    if (activeGui != 0) delete activeGui;
}

void MainClass::onEvent(sf::Event &event) {
    if (activeGui != 0) activeGui->onEvent(event);
}

void MainClass::onDraw() {
    if (activeGui != 0) activeGui->onDraw(*window);
}

void MainClass::changeGui(GuiBase *newGui) {
    if (prevGui != 0) delete prevGui;
    prevGui = activeGui;
    activeGui = newGui;
}

sf::Font &MainClass::getFont() {
    return font;
}

void MainClass::exit() {
    window->close();
}
