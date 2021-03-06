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

    startText = new Label(newMainClass, std::to_string(rangeStart), xPos, yPos + height / 2, 15, TOP_LEFT);
    markerText = new Label(newMainClass, std::to_string(value), xPos + width / 2, yPos + height / 2, 15, TOP_CENTER);
    endText = new Label(newMainClass, std::to_string(rangeEnd), xPos + width, yPos + height / 2, 15, TOP_RIGHT);
}
Fader::~Fader() {
    delete startText;
    delete endText;
    delete markerText;
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
void Fader::onDraw(sf::RenderTarget &target) {
    target.draw(line);
    marker.setPosition(xPos + value * width / range - 1, yPos);
    target.draw(marker);

    markerText->setPosition(xPos + width / 2, yPos + height / 2);
    markerText->setText(std::to_string(value));

    startText->onDraw(target);
    endText->onDraw(target);
    markerText->onDraw(target);
}

int Fader::getValue() const {
    return value;
}
void Fader::setValue(int newValue) {
    value = newValue;
    if (value < rangeStart) value = rangeStart;
    else if (value > rangeEnd) value = rangeEnd;
}
