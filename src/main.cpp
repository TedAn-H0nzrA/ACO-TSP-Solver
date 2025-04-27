#include <iostream>
#include "Simulation.hpp"
using namespace std;

int main() {
    cout << "TSP && ACO\n";
    Simulation simulation;

    try{
        simulation.run();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}