#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Town.hpp"
using namespace sf;
using namespace std;

class Simulation{
    private:
        RenderWindow window;
        bool isRunning;
        bool isAddTown;
        Clock timeAddTown;

        vector<Town> towns;


    public:
        Simulation();

        void manageEvent(Event& event);
        void todo();

        void draw();
        void run();
};