#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Town{
    private:
        CircleShape shape;
        float radius;

    public:
        Town();
        void draw(RenderWindow& window);

        void setPosition(float x, float y);
        Vector2f getPosition() const;
};