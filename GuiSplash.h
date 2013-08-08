#ifndef GUISPLASH_H
#define GUISPLASH_H

#include <GuiNewGame.h>
#include <gui/GuiBase.h>
#include <gui/Label.h>
#include <gui/Button.h>

class GuiSplash: public GuiBase {
    public:
        GuiSplash(MainClass *newMainClass);
        ~GuiSplash();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target);

    private:
        Label *title;
        Button *newGameButton,
            *exitButton;
};

#endif // GUISPLASH_H
