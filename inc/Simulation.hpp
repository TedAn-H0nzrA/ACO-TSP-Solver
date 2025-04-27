#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Simulation{
    private:
        RenderWindow window;
        bool isRunning;
        bool isAddTown;


    public:
        Simulation();

        void manageEvent(Event& event);

        void run();
};