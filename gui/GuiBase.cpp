#include "GuiBase.h"

GuiBase::GuiBase() {
    guiManager = 0;
}
GuiBase::~GuiBase() {
}

void GuiBase::setGuiManager(GuiManager *newGuiManager) {
    guiManager = newGuiManager;
    onGuiManagerUpdate();
}
