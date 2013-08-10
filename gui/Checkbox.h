#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <MainClass.h>

#include <SFML/Window.hpp>

class Checkbox {
    public:
        Checkbox(MainClass *newMainClass, int newXPos, int newYPos);
        Checkbox(MainClass *newMainClass, int newXPos, int newYPos, bool newEnabled);
        Checkbox(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight);
        Checkbox(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight, bool newEnabled);
        ~Checkbox();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target) const;

        bool isEnabled() const;
        void setEnabled(bool value);

    private:
        int xPos, yPos;
        unsigned int width, height;
        bool enabled, hovering;

        void init(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight, bool newEnabled);
};

#endif // CHECKBOX_H
