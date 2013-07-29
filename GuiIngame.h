#ifndef GUIINGAME_H
#define GUIINGAME_H

#include <SFML/Graphics.hpp>

#include <gui/GuiBase.h>
#include <GuiTitle.h>

class GuiIngame : public GuiBase {
    public:
        GuiIngame();
        ~GuiIngame();

        void onEvent(sf::Event event);
        void draw(sf::RenderTarget &window);

    private:
        std::vector<Button *> buttons;
        sf::Text title;

        void onGuiManagerUpdate();
};

#endif // GUIINGAME_H
