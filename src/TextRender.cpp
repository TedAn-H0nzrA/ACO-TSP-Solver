#include "TextRender.hpp"
#include "Constants.hpp"
#include <iostream>
using namespace sf;
using namespace std;

TextRender::TextRender() {
    if (!font.loadFromFile(string(FONTS_DIR) + "/OpenSans.ttf")) {
        cerr << "Error: Failed to load font\n";
    }

    text.setFont(font);
    text.setFillColor(Constant::tf_color);
    text.setCharacterSize(Constant::tf_size);
    text.setStyle(Text::Regular);
}

void TextRender::setString(const string& some_text) {
    text.setString(some_text);
}

void TextRender::draw(RenderWindow& window) {
    window.draw(text);
}

void TextRender::setPosition(float x, float y) {
    text.setPosition(x, y);
}