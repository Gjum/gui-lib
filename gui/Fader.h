#ifndef FADER_H
#define FADER_H

#include <MainClass.h>

#include <SFML/Window.hpp>

class Fader {
    public:
        Fader(MainClass *newMainClass,
              int newXPos, int newYPos, unsigned int newWidth,
              int newRangeStart, int newRangeEnd);
        ~Fader();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target) const;

        int getValue() const;
        void setValue(int newValue);

    private:
        int xPos, yPos;
        unsigned int width, height;
        int range, rangeStart, rangeEnd, value;
        bool dragging;
};

#endif // FADER_H
