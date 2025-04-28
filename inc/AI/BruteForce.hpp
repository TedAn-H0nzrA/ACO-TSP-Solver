#pragma once

#include <cmath>
#include <limits>
#include <vector>
#include "Town.hpp"
#include "PathRender.hpp"
using namespace std;

class BruteForce {
    private:
        double minPathLength; // La distance la plus court trouvé
        vector<int> bestPath; // Stock l'indice des villes menant à la meilleurs path trouvé

        size_t iteration; // Nombre d'itération lors du calcule
        double executionTime; // Temps d'execution

    public:
        // Constructor
        BruteForce();

        // Total distance d'un circuit
        double calculateDistance(const vector<Town>& town, const vector<int>& path) const;

        // Méthode pricipale d'exetion via BruteForce
        // Prend en entrée le vecteur des villes et retourn la meilleur chemin trouvée
        vector<int> solveBy_bruteForce(const vector<Town>& towns, PathRender& pathRender);

        // Méthode GETTERS resultat
        double getMinPathLength() const;
        vector<int> getBestPath() const;
        size_t getIteration() const;
        double getExecutionTime() const;

        // Affichage information pour débug;
};