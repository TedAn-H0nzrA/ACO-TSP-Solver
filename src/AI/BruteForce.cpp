#include "AI/BruteForce.hpp"
#include <chrono>
using namespace std;

BruteForce::BruteForce() :
    minPathLength(numeric_limits<double>::max()),
    iteration(0),
    executionTime(0)
{}

double BruteForce::calculateDistance(const vector<Town>& town, const vector<int>& path) const{
    double dist = 0;

    for (size_t i = 0; i < path.size() - 1; i++) {
        dist += town[path[i]].distanceTo(town[path[i + 1]]);
    }
    // Distance pour revenir au premier point
    dist += town[path.back()].distanceTo(town[path.front()]);

    return dist;
}

vector<int> BruteForce::solveBy_bruteForce(const vector<Town>& towns, PathRender& pathRender) {
    // Avoir le nombre totale de ville et les indexer dans une nouvelle vecteur pour une manipulation flexible
    size_t n = towns.size();
    vector<int> path(n);

    // Retourner vide si les villes ne sont pas implementées correctement
    if (n <= 1) {
        return vector<int>();
    }
    // Indexation
    for (int i = 0; i < n; i++) {
        path[i] = i;
    }

    // Réinitialisaton des variables pour une nouvelle résolution
    minPathLength = numeric_limits<double>::max();
    iteration = 0;
    executionTime = 0;

    // Initialisation PAR DEFAUT du meilleur chemin comme la première
    bestPath = path;

    // Distance du chemin initial
    double initialeDistance = calculateDistance(towns, path);
    minPathLength = initialeDistance;

    // Mésurer le temps d'execution
    auto startChrono = chrono::high_resolution_clock::now();

    // Générer toutes les permutations possible
    // Commencer avec la seconde permutation (next_permutation modifie la vecteur)
    while (next_permutation(path.begin(), path.end())) {
        iteration++;

        // Calculer la distance total pour la permutation actuelle
        double currentDistance = calculateDistance(towns, path);

        // Si le chemin actuelle est meilleurs alors mettre à jour bestPath
        if (currentDistance < minPathLength) {
            minPathLength = currentDistance;
            bestPath = path;
        }
    }

    // Temps total d'execution
    auto endChrono = chrono::high_resolution_clock::now();
    chrono::duration<double> elapseTime = (endChrono - startChrono);
    executionTime = elapseTime.count();

    return bestPath;
}

// Méthode GETTERS resultat
double BruteForce::getMinPathLength() const {
    return minPathLength;
}
vector<int> BruteForce::getBestPath() const {
    return bestPath;
}
size_t BruteForce::getIteration() const {
    return iteration;
}
double BruteForce::getExecutionTime() const {
    return executionTime;
}