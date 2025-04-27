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
    inline constexpr int tf_size = 20;
    inline Color tf_color{Color::White};

    // Lines Path
    inline Color l_color{254, 254, 226};
}