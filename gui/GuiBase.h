#ifndef GUIBASE_H
#define GUIBASE_H

#include <gui/GuiManager.h>
#include <gui/Button.h>

#include <SFML/Graphics.hpp>

#include <vector>

class GuiBase {
    public:
        GuiBase();
        virtual ~GuiBase();

        void setGuiManager(GuiManager *newGuiManager);
        virtual void onEvent(sf::Event event) = 0;
        virtual void draw(sf::RenderTarget &window) = 0;

    protected:
        GuiManager *guiManager;

        virtual void onGuiManagerUpdate() = 0;
};

#endif // GUIBASE_H
