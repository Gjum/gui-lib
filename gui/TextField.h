#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <Game.h>

#include <SFML/Window.hpp>

class TextField {
    public:
        TextField(Game *newGame, int newXPos, int newYPos);
        TextField(Game *newGame, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight);
        ~TextField();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target) const;

        std::string getContent() const;

    private:
        int xPos, yPos;
        unsigned int width, height;
        sf::Text title;
        bool active;
};

#endif // TEXTFIELD_H
