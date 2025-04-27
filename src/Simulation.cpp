#include "Simulation.hpp"
#include "Constants.hpp"
using namespace sf;

Simulation::Simulation() :
        isRunning(false),
        isAddTown(true)
{
    window.create(Constant::desktop, Constant::TITLE, Style::Default);
    window.setFramerateLimit(Constant::FPS);
}

void Simulation::manageEvent(Event& event) {
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) window.close();
    }

    if(!isRunning || Keyboard::isKeyPressed(Keyboard::R)) {
        isRunning = true;
        isAddTown = false;
    }

    if (isAddTown) {
        // Adding town implementation
    }

    if (isRunning) {
        // ACO implementation
    }
}

void Simulation::run() {
    while (window.isOpen()) {
        Event event;
        manageEvent(event);

        // ===Render===
        window.clear(Constant::BACKGROUNG);
        window.display();
    }
}
