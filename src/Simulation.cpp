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

    bestPath.setLineColor(Constant::l_Bestcolor);

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

    if (!bruteForce.isSolvingInProgress()) {
        txt_iteration.setString(Constant::txt_iteration + "Calcul en cours...");
        txt_distance.setString(Constant::txt_distance + "Calcul en cours...");
        txt_executionTime.setString(Constant::txt_executionTime + "Calcul en cours...");
        bruteForce.startSolving(towns, path);
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
    
    if (isRunning && BF_isSolving) {
        if (bruteForce.stepSolving(towns, path)) {
            // Mettre à jour les textes en temps réel
            txt_iteration.setString(Constant::txt_iteration + to_string(bruteForce.getIteration()));
            txt_distance.setString(Constant::txt_distance + to_string(bruteForce.getMinPathLength()));
            txt_executionTime.setString(Constant::txt_executionTime + to_string(bruteForce.getExecutionTime()) + " s");
            bestPath.clear();
            bestPath.setPath(towns, bruteForce.getBestPath());
        } else {
            // Calcul terminé
            BF_isSolving = false;
            BF_isSolve = true;
        }
    } 
    
}

void Simulation::manageEvent(Event& event) {
    if (event.type == Event::Closed) window.close();

    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::B) {
            isRunning = true;
            isAddTown = false;
            BF_isSolving = true;
            runBruteForce();

        } else if (event.key.code == Keyboard::A) {
            // Implementation pour ACO
        } else if (event.key.code == Keyboard::T) {
            isRunning = false;
            isAddTown = true;
        } else if (event.key.code == Keyboard::Space) {
            // Tout réinitialliser

            towns.clear();
            path.clear();
            bestPath.clear();
            bruteForce = BruteForce();
            BF_isSolving = false;
            BF_isSolve = false;
            BF_totalDist = 0;
            BF_timeExecution = 0;

            bestPath = PathRender();

            // Réinitialiser les textes
            txt_iteration.setString(Constant::txt_iteration);
            txt_distance.setString(Constant::txt_distance);
            txt_executionTime.setString(Constant::txt_executionTime);

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

    path.draw(window);
    bestPath.draw(window);
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
