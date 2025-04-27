#include "Town.hpp"
#include "Constants.hpp"
using namespace sf;

Town::Town() :
        radius(Constant::t_radius)
{
    shape.setRadius(radius);
    shape.setFillColor(Constant::t_color);
    shape.setOrigin(radius, radius);
}

void Town::draw(RenderWindow& window) {
    window.draw(shape);
}

void Town::setPosition(float x, float y) {
    shape.setPosition(x, y);    
}

Vector2f Town::getPosition() const {
    return shape.getPosition();
}