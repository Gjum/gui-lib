#ifndef LABEL_H
#define LABEL_H

#include <MainClass.h>

#include <SFML/Window.hpp>
#include <string>

class Label {
    public:
        Label(MainClass *newMainClass, std::string newTitle,
              int newXPos, int newYPos, unsigned int newSize);
        ~Label();

        void onDraw(sf::RenderTarget &target) const;

        void setPosition(unsigned int x, unsigned int y);
        void setText(std::string text);

    private:
        sf::Text title;
};

#endif // LABEL_H
