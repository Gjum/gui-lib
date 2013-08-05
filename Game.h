#ifndef GAME_H
#define GAME_H

#include <gui/GuiBase.h>

#include <SFML/Window.hpp>

class Game {
    public:
        Game(sf::RenderWindow *window);
        ~Game();

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

#endif // GAME_H
