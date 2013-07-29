#ifndef GUITITLE_H
#define GUITITLE_H

#include <SFML/Graphics.hpp>

#include <gui/GuiBase.h>
#include <GuiIngame.h>

class GuiTitle : public GuiBase {
    public:
        GuiTitle();
        ~GuiTitle();

        void onEvent(sf::Event event);
        void draw(sf::RenderTarget &window);

    private:
        std::vector<Button *> buttons;
        sf::Text title;

        void onGuiManagerUpdate();
};

#endif // GUITITLE_H
