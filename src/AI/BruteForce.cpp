#include "AI/BruteForce.hpp"
#include <chrono>
#include <algorithm>
using namespace std;

BruteForce::BruteForce() :
    isSolving(false),
    minPathLength(numeric_limits<double>::max()),
    iteration(0),
    executionTime(0),
    maxIterationPerFrame(100)
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

void BruteForce::startSolving(const vector<Town>& towns, PathRender& pathRender) {
    // Avoir le nombre totale de ville et les indexer dans une nouvelle vecteur pour une manipulation flexible
    size_t n = towns.size();
    // Retourner vide si les villes ne sont pas implementées correctement
    if (n <= 1) {
        return ;
    }
    // Indexation
    currentPath.resize(n);
    for (int i = 0; i < n; i++) {
        currentPath[i] = i;
    }

     // Réinitialisaton des variables pour une nouvelle résolution
    minPathLength = numeric_limits<double>::max();
    iteration = 0;
    executionTime = 0;
    // Initialisation PAR DEFAUT du meilleur chemin comme la première
    bestPath = currentPath;

    // Distance du chemin initial
    double initialeDistance = calculateDistance(towns, currentPath);
    minPathLength = initialeDistance;
    pathRender.setPath(towns, currentPath);
    isSolving = true;
}

bool BruteForce::stepSolving(const vector<Town>& towns, PathRender& pathRender) {
    if (!isSolving) return false;

    // Mésurer le temps d'execution
    auto startChrono = chrono::high_resolution_clock::now();

    // Traiter un certain nombre d'itération par frame
    // Générer toutes les permutations possible
    // Commencer avec la seconde permutation (next_permutation modifie la vecteur)
    for (size_t i = 0; i < maxIterationPerFrame && isSolving; i++) {
        if (!next_permutation(currentPath.begin(), currentPath.end())) {
            isSolving = false; // Fin des permutation
            break;
        }
        iteration++;

        // Calculer la distance total pour la permutation actuelle
        double currentDistance = calculateDistance(towns, currentPath);
        pathRender.setPath(towns, currentPath);

        // Si le chemin actuelle est meilleurs alors mettre à jour bestPath
        if (currentDistance < minPathLength) {
            minPathLength = currentDistance;
            bestPath = currentPath;
        }
    }

    // Temps total d'execution
    auto endChrono = chrono::high_resolution_clock::now();
    chrono::duration<double> elapseTime = (endChrono - startChrono);
    executionTime = elapseTime.count();

    return isSolving;
}

bool BruteForce::isSolvingInProgress() const {
    return isSolving;
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