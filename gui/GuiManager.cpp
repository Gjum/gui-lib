#include "GuiManager.h"

#include <gui/GuiBase.h>

GuiManager::GuiManager() {
    font.loadFromFile("font.ttf");
    prevGui = 0;
    activeGui = 0;
}
GuiManager::~GuiManager() {
    if (prevGui != 0) delete prevGui;
    if (activeGui != 0) delete activeGui;
}

void GuiManager::onEvent(sf::Event event) {
    if (activeGui != 0) activeGui->onEvent(event);
}
void GuiManager::draw(sf::RenderTarget& window) const {
    if (activeGui != 0) activeGui->draw(window);
}
void GuiManager::changeGui(GuiBase* newGui) {
    if (prevGui != 0) delete prevGui;
    prevGui = activeGui;
    activeGui = newGui;
    activeGui->setGuiManager(this);
}
sf::Font& GuiManager::getFont() {
    return font;
}
