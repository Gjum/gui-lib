#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <Game.h>

#include <SFML/Window.hpp>

class Checkbox {
    public:
        Checkbox(Game *newGame, int newXPos, int newYPos);
        Checkbox(Game *newGame, int newXPos, int newYPos, bool newEnabled);
        Checkbox(Game *newGame, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight);
        ~Checkbox();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target) const;

        bool isEnabled() const;

    private:
        int xPos, yPos;
        unsigned int width, height;
        bool enabled, hovering;
};

#endif // CHECKBOX_H
