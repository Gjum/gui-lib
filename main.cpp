#include <GuiTitle.h>

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 450), "Gui");

    GuiManager guiManager;
    guiManager.changeGui(new GuiTitle);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed
                    || event.type == sf::Event::MouseButtonReleased
                    || event.type == sf::Event::MouseMoved
               ) {
                guiManager.onEvent(event);
            }
        }

        window.clear();

        guiManager.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}
