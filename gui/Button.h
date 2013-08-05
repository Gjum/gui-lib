#ifndef BUTTON_H
#define BUTTON_H

#include <Game.h>

#include <SFML/Window.hpp>

class Button {
    public:
        Button(Game *newGame, int newID, std::string newTitle, int newXPos, int newYPos);
        Button(Game *newGame, int newID, std::string newTitle, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight);
        ~Button();

        bool onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target) const;

        int getID() const;

    protected:
        int id, xPos, yPos;
        unsigned int width, height;
        sf::Text title;
        bool hovering;

        Button();
};

#endif // BUTTON_H
