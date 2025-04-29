#pragma once

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

namespace Constant {
    // Window
    inline VideoMode desktop = VideoMode::getDesktopMode();
    inline float WIDTH = static_cast<float>(desktop.width);
    inline float HEIGHT = static_cast<float>(desktop.height);
    inline float FPS = 60;
    inline string TITLE = "TSP_ACO";
    inline Color BACKGROUND{30, 30, 47};

    // Town
    inline constexpr float t_radius = 10;
    inline Color t_color{255, 215, 0};

    // Text & Font
    inline constexpr int tf_size = 15;
    inline Color tf_color{Color::White};

    // Text render
    inline string txt_iteration = "Itération : "; 
    inline string txt_distance = "Distance minimal : "; 
    inline string txt_executionTime = "Temps d'execution : "; 

    // Lines Path
    inline Color l_color{210, 210, 210};
    inline Color l_Bestcolor{255, 215, 0};
}