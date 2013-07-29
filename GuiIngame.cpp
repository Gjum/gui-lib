#include "GuiIngame.h"

GuiIngame::GuiIngame() {
    title.setString("Game paused");
    title.setColor(sf::Color(255, 255, 255));
    buttons.insert(buttons.end(), new Button(0, 60, 60, 200, 30, "Resume"));
    buttons.insert(buttons.end(), new Button(1, 60, 100, 200, 30, "Menu"));
}
GuiIngame::~GuiIngame() {
    for (auto button : buttons) {
        delete button;
    }
}

void GuiIngame::onEvent(sf::Event event) {
    int buttonID = -1;

    for (auto button : buttons) {
        if (button->onEvent(event)) {
            buttonID = button->getID();
            break;
        }
    }
    if (buttonID == 0) {
    }
    else if (buttonID == 1) {
        GuiBase::guiManager->changeGui(new GuiTitle);
    }
    else {
        // no button pressed
    }
}

void GuiIngame::draw(sf::RenderTarget &window) {
    sf::RectangleShape background(sf::Vector2f(window.getSize().x, window.getSize().y));
    background.setFillColor(sf::Color(0, 0, 0));
    window.draw(background);

    for (auto button : buttons) {
        button->draw(window);
    }

    window.draw(title);
}

void GuiIngame::onGuiManagerUpdate() {
    title.setFont(guiManager->getFont());
    title.setCharacterSize(20);
    title.move(sf::Vector2f(20, 20));

    for (auto button : buttons) {
        button->setGuiManager(guiManager);
    }
}
