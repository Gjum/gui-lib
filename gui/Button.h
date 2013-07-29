#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include <gui/GuiManager.h>

class Button {
    public:
        Button();
        Button(int newID, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight, std::string);
        ~Button();

        void setGuiManager(GuiManager* guiManager);
        bool onEvent(sf::Event event);
        void draw(sf::RenderTarget& window) const;
        int getID() const;

    protected:
        int id, xPos, yPos;
        unsigned int width, height;
        sf::Text title;
        bool hovering;
};

#endif // BUTTON_H
