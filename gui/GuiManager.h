#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <SFML/Graphics.hpp>

class GuiBase;

class GuiManager {
    public:
        GuiManager();
        ~GuiManager();

        void onEvent(sf::Event event);
        void draw(sf::RenderTarget& window) const;
        void changeGui(GuiBase* newGui);
        sf::Font& getFont();

    private:
        GuiBase* activeGui;
        GuiBase* prevGui;
        sf::Font font;
};

#endif // GUIMANAGER_H
