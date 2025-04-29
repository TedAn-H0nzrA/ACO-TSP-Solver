#pragma once

#include <SFML/Graphics.hpp>
#include "Town.hpp"
using namespace sf;
using namespace std;

class PathRender{
    private:
        VertexArray lines;
        Color lineColor;
        
    public:
        // Contructor
        PathRender();
        // Draw
        void draw(RenderWindow& window);

        void setLineColor(Color& newColor);
        void setPath(const vector<Town>& town, const vector<int>& path);

        void clear();
};