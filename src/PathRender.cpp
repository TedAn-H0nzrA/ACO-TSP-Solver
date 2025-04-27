#include "PathRender.hpp"
#include "Constants.hpp"
using namespace sf;
using namespace std;

PathRender::PathRender() : 
        lines(LineStrip),
        lineColor(Constant::l_color)
{}

void PathRender::draw(RenderWindow& window) {
    window.draw(lines);
}

void PathRender::setPath(const vector<Town>& town, const vector<int>& path) {
    // Effacer les lignes précédents (anciennes)
    lines.clear();
    lines.setPrimitiveType(LineStrip);

    for (int idx : path) {
        lines.append(Vertex(town[idx].getPosition(), lineColor));
    }
    // Retourner au début du point pour terminer le chemin
    lines.append(Vertex(town[0].getPosition(), lineColor));
}