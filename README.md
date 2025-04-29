# TSP_ACO – Résolution du TSP avec ACO et Brute Force

## Description

Ce projet est une simulation du **problème du voyageur de commerce** (TSP) résolu à l'aide de l'**optimisation par colonies de fourmis** (**ACO**). Le but du projet est de simuler la recherche du chemin optimal entre un ensemble de villes, en utilisant des algorithmes inspirés des colonies de fourmis. Le projet utilise **SFML** pour l'affichage graphique des résultats.

Les fonctionnalités prévues comprennent l'affichage des villes, le calcul des distances, et la visualisation du chemin optimal trouvé par l'algorithme ACO. Le projet est encore en développement et certaines fonctionnalités doivent être ajoutées.

## 🗂️ Structure du projet

```
ACO-TSP-Solver/
├── inc/ # Dossiers contenant les fichiers d'en-tête (.hpp) 
│   ├── AI/
│   │   ├── BruteForce.hpp
│   │   └── ACO.hpp
│   ├── Texts/
│   │   └── TextRender.hpp
│   ├── Constants.hpp # Définit les constantes globales du projet 
│   ├── PathRender.hpp # Déclare la classe PathRenderer pour dessiner le chemin 
│   ├── Simulation.hpp # Déclare la classe Simulation pour gérer l'algorithme TSP et ACO 
│   └── Town.hpp # Déclare la classe Town représentant une ville avec des coordonnées 
│
├── src/ # Dossier contenant les fichiers sources (.cpp)
│   ├── AI/
│   │   ├── BruteForce.cpp
│   │   └── ACO.cpp
│   ├── Texts/
│   │   └── TextRender.cpp
│   ├── main.cpp # Point d'entrée du programme 
│   ├── PathRender.cpp # Implémentation de la classe PathRenderer 
│   ├── Simulation.cpp # Implémentation de la classe Simulation 
│   └── Town.cpp # Implémentation de la classe Town 
│ 
├── font/ # Dossier contenant la police de caractères utilisée pour l'affichage du texte 
│   └── OpenSans.ttf # Police de caractères utilisée dans l'application 
│ 
└── CMakeLists.txt # Fichier de configuration CMake pour la compilation du projet
```

---

## Compilation

Le projet utilise **CMake** pour la configuration et la compilation. Pour compiler le projet, suivez ces étapes :

1. Clonez ou téléchargez le projet sur votre machine:

   ```bash
      git clone https://github.com/TedAn-H0nzrA/ACO-TSP-Solver.git
      cd ACO-TSP-Solver

   ```

2. Créez un répertoire de construction et accédez à celui-ci :

   ```bash
   mkdir build
   cd build
   ```

3. Exécutez CMake pour générer les fichiers de construction :

   ```bash
   cmake ..
    ```

4. Compilez le projet :

   ```bash
   make
    ```

5. Exécutez l'application générée :

   ```bash
   cd out/
   ./TSP_ACO
    ```

---

## 🧩 Dépendances

- [SFML](https://www.sfml-dev.org/) ≥ 2.5  
Assurez-vous que SFML est installé et détecté par CMake.

---

## Contrubution
