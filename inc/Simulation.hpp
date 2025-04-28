#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Town.hpp"
#include "PathRender.hpp"
#include "TextRender.hpp"
#include "AI/BruteForce.hpp"
using namespace sf;
using namespace std;

class Simulation{
    private:
        RenderWindow window;
        bool isRunning;
        bool isAddTown;
        Clock timeAddTown;
        ContextSettings settings;

        vector<TextRender> texts;
        TextRender txt_iteration;
        TextRender txt_distance;
        TextRender txt_executionTime;
        
        vector<Town> towns;

        // AI BruteForce Parameter
        BruteForce bruteForce;
        vector<int> currentPath;
        double BF_timeExecution;
        double BF_totalDist;
        bool BF_isSolving;
        bool BF_isSolve;

        PathRender pathRender;

    public:
        Simulation();

        void manageEvent(Event& event);
        void todo();

        // AI Solve
        void runBruteForce();

        void draw();
        void run();
};