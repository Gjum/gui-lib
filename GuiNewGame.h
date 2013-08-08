#ifndef GUINEWGAME_H
#define GUINEWGAME_H

#include <GuiSplash.h>
#include <gui/GuiBase.h>
#include <gui/Label.h>
#include <gui/TextField.h>
#include <gui/Checkbox.h>
#include <gui/Fader.h>
#include <gui/Button.h>

class GuiNewGame: public GuiBase {
    public:
        GuiNewGame(MainClass *newMainClass);
        ~GuiNewGame();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target);

    private:
        Label *title;
        TextField *playerName;
        Checkbox *checkbox;
        Fader *fader;
        Button *cancelButton;
};

#endif // GUINEWGAME_H
