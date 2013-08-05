#ifndef GUINEWGAME_H
#define GUINEWGAME_H

#include <GuiSplash.h>

#include <gui/GuiBase.h>
#include <gui/Button.h>
#include <gui/TextField.h>

class GuiNewGame: public GuiBase {
    public:
        GuiNewGame(Game *newGame);
        ~GuiNewGame();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderTarget &target);

    private:
        sf::Text title;
        TextField *playerName;
        Button *startGameButton,
            *cancelButton;
};

#endif // GUINEWGAME_H
