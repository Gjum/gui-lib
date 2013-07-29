#include "GuiTitle.h"

GuiTitle::GuiTitle() {
    title.setString("Game menu");
    title.setColor(sf::Color(255, 255, 255));
    buttons.insert(buttons.end(), new Button(0, 60, 60, 200, 30, "New game"));
    buttons.insert(buttons.end(), new Button(1, 60, 100, 200, 30, "Quit"));
}
GuiTitle::~GuiTitle() {
    for (auto button : buttons) {
        delete button;
    }
}

void GuiTitle::onEvent(sf::Event event) {
    int buttonID = -1;

    for (auto button : buttons) {
        if (button->onEvent(event)) {
            buttonID = button->getID();
            break;
        }
    }
    if (buttonID == 0) {
        GuiBase::guiManager->changeGui(new GuiIngame);
    }
    else if (buttonID == 1) {
    }
    else {
        // no button pressed
    }
}

void GuiTitle::draw(sf::RenderTarget &window) {
    sf::RectangleShape background(sf::Vector2f(window.getSize().x, window.getSize().y));
    background.setFillColor(sf::Color(0, 0, 0));
    window.draw(background);

    for (auto button : buttons) {
        button->draw(window);
    }

//    title.setOrigin(-sf::Vector2f(window.getSize().x / 2, 10));
    window.draw(title);
}

void GuiTitle::onGuiManagerUpdate() {
    title.setFont(guiManager->getFont());
    title.setCharacterSize(20);
//    title.move(-sf::Vector2f(title.findCharacterPos(title.getString().getSize()).x / 2.0, 0));
    title.move(sf::Vector2f(20, 20));

    for (auto button : buttons) {
        button->setGuiManager(guiManager);
    }
}
