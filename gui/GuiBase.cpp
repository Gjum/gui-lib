#include "GuiBase.h"

GuiBase::GuiBase() {
}
GuiBase::~GuiBase() {
}

void GuiBase::drawBackground(sf::RenderTarget &target, sf::Color color) const {
    sf::RectangleShape background(sf::Vector2f(target.getSize().x, target.getSize().y));
    background.setFillColor(color);
    target.draw(background);
}
