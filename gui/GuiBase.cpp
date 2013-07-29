#include "GuiBase.h"

#include <iostream>

GuiBase::GuiBase() {
    guiManager = 0;
}
GuiBase::~GuiBase() {
}

void GuiBase::setGuiManager(GuiManager *newGuiManager) {
    guiManager = newGuiManager;
    onGuiManagerUpdate();
}
