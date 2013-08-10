#ifndef LABEL_H
#define LABEL_H

#include <MainClass.h>

#include <SFML/Window.hpp>
#include <string>

enum GuiLabelAlign {
    TOP_LEFT, TOP_CENTER, TOP_RIGHT,
    MIDDLE_LEFT, MIDDLE_CENTER, MIDDLE_RIGHT,
    BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT
};

class Label {
    public:
        Label(MainClass *newMainClass, std::string newTitle,
              int newXPos, int newYPos, unsigned int newSize);
        Label(MainClass *newMainClass, std::string newTitle,
              int newXPos, int newYPos,
              unsigned int newSize, GuiLabelAlign newAlign);
        ~Label();

        void onDraw(sf::RenderTarget &target) const;

        void setPosition(unsigned int x, unsigned int y);
        void setText(std::string text);

    private:
        sf::Text title;
        GuiLabelAlign align;

        void init(MainClass *newMainClass, std::string newTitle,
                  int newXPos, int newYPos,
                  unsigned int newSize, GuiLabelAlign newAlign);
        void realign();
};

#endif // LABEL_H
