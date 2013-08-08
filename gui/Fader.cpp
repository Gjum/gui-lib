#include "Fader.h"

Fader::Fader(MainClass *newMainClass,
             int newXPos, int newYPos, unsigned int newWidth,
             int newRangeStart, int newRangeEnd) {
    xPos = newXPos;
    yPos = newYPos;
    width = newWidth;
    height = 30;
    rangeStart = newRangeStart;
    rangeEnd = newRangeEnd;
    range = rangeEnd - rangeStart;
    value = rangeStart;
    dragging = false;

    line.setSize(sf::Vector2f(width, 5));
    line.setPosition(xPos, yPos + height / 3);
    line.setFillColor(sf::Color(0, 0, 255, 128));

    marker.setSize(sf::Vector2f(1, height / 2));
    marker.setPosition(xPos + value * width / range, yPos);
    marker.setFillColor(sf::Color(0, 0, 255, 255));
}
Fader::~Fader() {
}

void Fader::onEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed
            && event.mouseButton.button == sf::Mouse::Left
            && event.mouseButton.x > xPos
            && event.mouseButton.x < xPos + width
            && event.mouseButton.y > yPos
            && event.mouseButton.y < yPos + height) {
        dragging = true;
    }
    else if (dragging && event.type == sf::Event::MouseMoved) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            setValue((event.mouseMove.x - xPos) * range / (int) width + rangeStart);
        }
        else dragging = false;
    }
}
void Fader::onDraw(sf::RenderTarget &target) const {
    target.draw(line);
    target.draw(marker);
}

int Fader::getValue() const {
    return value;
}
void Fader::setValue(int newValue) {
    value = newValue;
    if (value < rangeStart) value = rangeStart;
    else if (value > rangeEnd) value = rangeEnd;
}
