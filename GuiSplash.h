#ifndef GUISPLASH_H
#define GUISPLASH_H

#include <GuiNewGame.h>
#include <gui/GuiBase.h>
#include <gui/Button.h>

class GuiSplash: public GuiBase {
    public:
        GuiSplash(Game *newGame);
        ~GuiSplash();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target);

    private:
        std::vector<Button *> buttons;
        sf::Text title;
};

#endif // GUISPLASH_H
