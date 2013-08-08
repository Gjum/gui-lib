#ifndef GUIBASE_H
#define GUIBASE_H

#include <SFML/Graphics.hpp>

class MainClass;

class GuiBase {
    public:
        GuiBase();
        virtual ~GuiBase();

        virtual void onEvent(sf::Event &event) = 0;
        virtual void onDraw(sf::RenderTarget &target) = 0;

    protected:
        MainClass *mainClass;
};

// forward declared
#include <MainClass.h>

#endif // GUIBASE_H
