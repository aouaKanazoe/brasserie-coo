# brasserie-coo — Simulation d'une usine de brassage

Bienvenue dans le projet **Brasserie Coo**, une application Django couplée à un moteur de simulation C++ pour gérer et simuler la production d'une brasserie.

## 🚀 Fonctionnalités principales

- 🔧 Interface d’administration Django avec :
  - Départements
  - Machines
  - Ingrédients et quantités
  - Recettes
  - Actions de production
  - Usines et coûts associés

- 🧠 Moteur bas niveau en C++ (via CPR + JSON) pour :
  - Charger les données depuis Django via HTTP
  - Calculer les coûts, afficher les usines, etc.

- 🌐 Endpoints accessibles :
  - `/admin/` — gestion des entités
  - `/departement/<int:pk>` — détails JSON d’un département
  - (À venir) `/simulateur/` — exécution du simulateur bas niveau

## 🛠️ Technologies utilisées

| Front | Back | Simulation |
|-------|------|------------|
| HTML (admin Django) | Django 4.2.5 | C++17 |
| CSS (admin)         | SQLite       | CPR (lib HTTP) |

---

## 📦 Installation

### Prérequis

- Python 3.11+
- CMake
- g++ (recommandé : MinGW-w64 13.3)
- Git

### 🔹 Cloner le projet
