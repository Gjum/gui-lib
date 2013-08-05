#ifndef GUISPLASH_H
#define GUISPLASH_H

#include <gui/GuiBase.h>

class GuiSplash: public GuiBase {
    public:
        GuiSplash(Game *newGame);
        ~GuiSplash();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderWindow &window);

    private:
};

#endif // GUISPLASH_H
