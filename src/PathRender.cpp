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

void PathRender::setLineColor(Color& newColor) {
    lineColor = newColor;
}

void PathRender::setPath(const vector<Town>& town, const vector<int>& path) {
    lines.setPrimitiveType(LineStrip);
    
    for (int idx : path) {
        lines.append(Vertex(town[idx].getPosition(), lineColor));
    }
    // Retourner au début du point pour terminer le chemin
    if (!path.empty()) {
        lines.append(Vertex(town[path[0]].getPosition(), lineColor));
    }
}

void PathRender::clear() {
    // Effacer les lignes précédents (anciennes)
    lines.clear();
}