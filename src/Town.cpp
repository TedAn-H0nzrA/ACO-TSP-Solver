#include "Town.hpp"
#include "Constants.hpp"
#include <cmath>
using namespace sf;
using namespace std;

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

double Town::distanceTo(const Town& other) const {
    auto thisPos = this->getPosition();
    auto otherPos = other.getPosition();

    double posX = pow((thisPos.x - otherPos.x), 2);
    double posY = pow((thisPos.y - otherPos.y), 2);

    double distance = sqrt(posX + posY);
    return distance;
}