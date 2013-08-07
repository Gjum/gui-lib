#include <Game.h>
#include <GuiSplash.h>

#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(800, 450), "New SFML Project");

    Game *game = new Game(&window);

    game->changeGui(new GuiSplash(game));

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            game->onEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        game->onDraw();

        window.display();
    }

    return EXIT_SUCCESS;
}
