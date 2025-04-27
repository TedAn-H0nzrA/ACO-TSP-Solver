#pragma once

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class TextRender{
    private:
        Font font;
        Text text;

    public:
        TextRender();

        void setString(const string& some_text);
        void draw(RenderWindow& window);

        void setPosition(float x, float y);
};