#ifndef GAME_H
#define GAME_H

#include <gui/GuiBase.h>

#include <SFML/Window.hpp>

class Game {
    public:
        Game();
        ~Game();

        void onEvent(sf::Event &event);
        void onDraw(sf::RenderWindow &window);
        void changeGui(GuiBase *newGui);
        sf::Font &getFont();

    private:
        GuiBase *activeGui, *prevGui;
        sf::Font font;
};

#endif // GAME_H
