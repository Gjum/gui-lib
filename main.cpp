#include <MainClass.h>
#include <GuiSplash.h>

#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(800, 450), "New SFML Project");

    MainClass *mainClass = new MainClass(&window);

    mainClass->changeGui(new GuiSplash(mainClass));

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            mainClass->onEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        mainClass->onDraw();

        window.display();
    }

    return EXIT_SUCCESS;
}
