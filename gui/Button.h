#ifndef BUTTON_H
#define BUTTON_H

#include <MainClass.h>

#include <SFML/Window.hpp>

class Button {
    public:
        Button(MainClass *newMainClass, std::string newTitle, int newXPos, int newYPos);
        Button(MainClass *newMainClass, std::string newTitle, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight);
        ~Button();

        bool onEvent(sf::Event &event); // returns true if clicked
        void onDraw(sf::RenderTarget &target) const;

    private:
        int xPos, yPos;
        unsigned int width, height;
        sf::Text title;
        bool hovering;
};

#endif // BUTTON_H
