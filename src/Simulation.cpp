#include "Simulation.hpp"
#include "Constants.hpp"
using namespace sf;

Simulation::Simulation() :
        isRunning(false),
        isAddTown(false),
        // BruteForce
        BF_isSolving(false),
        BF_isSolve(false),
        BF_totalDist(0),
        BF_timeExecution(0)
{
    settings.antialiasingLevel = 8;
    window.create(Constant::desktop, Constant::TITLE, Style::Default, settings);
    window.setFramerateLimit(Constant::FPS);

    // Text render
    txt_iteration.setString(Constant::txt_iteration);
    txt_iteration.setPosition(0, 10);

    txt_distance.setString(Constant::txt_distance);
    txt_distance.setPosition(0, 30);

    txt_executionTime.setString(Constant::txt_executionTime);
    txt_executionTime.setPosition(0, 50);


    texts.push_back(txt_iteration);
    texts.push_back(txt_distance);
    texts.push_back(txt_executionTime);
}

void Simulation::runBruteForce() {
    if (towns.size() < 2) {
        return;
    }

    
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
        if (BF_isSolving && !BF_isSolve) {

        }
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

    for (auto&& text : texts) {
        text.draw(window);
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
