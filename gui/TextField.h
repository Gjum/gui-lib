#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <MainClass.h>

#include <SFML/Window.hpp>

class TextField {
    public:
        TextField(MainClass *newMainClass, int newXPos, int newYPos);
        TextField(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight);
        ~TextField();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target) const;

        std::string getContent() const;
        void setContent(std::string newString);

    private:
        int xPos, yPos;
        unsigned int width, height,
            caretPos;
        sf::Text title;
        bool active;

        void init(MainClass *newMainClass, int newXPos, int newYPos, unsigned int newWidth, unsigned int newHeight);
};

#endif // TEXTFIELD_H
