#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <gui/GuiBase.h>

class MainClass {
    public:
        MainClass(sf::RenderWindow *window);
        ~MainClass();

        void onEvent(sf::Event &event);
        void onDraw();
        void changeGui(GuiBase *newGui);
        sf::Font &getFont();

        void exit();

    private:
        GuiBase *activeGui, *prevGui;
        sf::Font font;
        sf::RenderWindow *window;
};

#endif // MAINCLASS_H
