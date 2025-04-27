#include "Simulation.hpp"
#include "Constants.hpp"
using namespace sf;

Simulation::Simulation() :
        isRunning(false),
        isAddTown(false)
{
    window.create(Constant::desktop, Constant::TITLE, Style::Default);
    window.setFramerateLimit(Constant::FPS);
}

void Simulation::todo() { 
    if (isAddTown) {
        if ((Mouse::isButtonPressed(Mouse::Left)) && timeAddTown.getElapsedTime().asSeconds() >= 0.2) {
            Vector2i mousePos = Mouse::getPosition(window);
            Town town;
            town.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            towns.push_back(town);
            timeAddTown.restart();
        }
    }
    
    if (isRunning) {
        // ACO implementation
    } 
    
}

void Simulation::manageEvent(Event& event) {
    if (event.type == Event::Closed) window.close();

    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::R) {
            isRunning = true;
            isAddTown = false;
        } else if (event.key.code == Keyboard::A) {
            isRunning = false;
            isAddTown = true;
        }
    }

    todo();
}

void Simulation::draw() {
    for (auto&& town : towns) {
        town.draw(window);
    }
}

void Simulation::run() {
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)){
            manageEvent(event);
        }

        // ===Render===
        window.clear(Constant::BACKGROUND);
        draw();
        window.display();
    }
}
