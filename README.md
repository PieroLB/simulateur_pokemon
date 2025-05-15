# 🐱‍👤 Simulateur de Combats Pokémon

Un projet en C++ simulant des combats Pokémon avec menus interactifs et système d'importation depuis des fichiers CSV.

## 📦 Téléchargement du Projet

### 🔁 Clone (recommandé)

```bash
git clone https://github.com/PieroLB/simulateur_pokemon.git
```

### 📁 ZIP

Télécharger le projet en `.zip` directement depuis le [repository GitHub](https://github.com/PieroLB/simulateur_pokemon).

---

## ⚙️ Compilation du Projet

### ✅ Avec Visual Studio Code (recommandé)

1. Ouvre le projet dans VS Code.
2. Appuie sur `Ctrl + Shift + P`.
3. Sélectionne `Run Build Task`.
4. Les commandes sont exécutées via `.vscode/tasks.json`.

### 💻 En ligne de commande

- **Linux :**

```bash
g++ -o main.out main.cpp import\import.cpp menu\menu.cpp Pokemon\Pokemon.cpp Entraineur\Entraineur.cpp Entraineur\Joueur\Joueur.cpp Entraineur\Leader\Leader.cpp Entraineur\Maitre\Maitre.cpp
```

- **Windows :**

```bash
g++ -o main.exe main.cpp import\import.cpp menu\menu.cpp Pokemon\Pokemon.cpp Entraineur\Entraineur.cpp Entraineur\Joueur\Joueur.cpp Entraineur\Leader\Leader.cpp Entraineur\Maitre\Maitre.cpp
```

---

## 🚀 Exécution du Projet

- **Linux :**

```bash
./main.out
```

- **Windows :**

```bash
./main.exe
```

---

## 🎮 Contrôles et Navigation

- `[Flèche Haut]` et `[Flèche Bas]` pour naviguer à travers les options.
- `[Entrée]` pour sélectionner une option.

---

## 🧠 Fonctionnalités

- 📥 Chargement des données depuis des fichiers CSV (`types.csv`, `pokemon.csv`, `joueurs.csv`, etc.).
- 🧾 Menus interactifs avec interface terminal.
- ⚔️ Système de combat entre le joueur, des leaders et des maîtres.
- 🧬 Interactions uniques avec Pokémon et entraîneurs vaincus.
- 💊 Système de soin, statistiques et gestion d'équipe.

---

## 📁 Structure du Projet

- `main.cpp` : point d’entrée du programme.
- `import/` : fonctions de chargement des données.
- `Pokemon/` : classe et logique des Pokémon.
- `Entraineur/` : logique commune des entraîneurs, leaders, maîtres, joueurs.
- `menu/` : gestion des menus et navigation utilisateur.
- `Interagir/` : interface pour les interactions avec les entités.

---

## 👨‍💻 Dépendances

- Aucune dépendance externe.
- Utilise `ncurses` pour Linux (nécessite `sudo apt install libncurses5-dev`).
- Compatible Windows avec `<conio.h>`.

---

## UML

![uml](https://github.com/user-attachments/assets/10d5412d-b3b6-4ade-b195-a531a8fb68a3)

---

## 📜 Licence

Projet éducatif développé dans le cadre d’un module C++ à l’ESILV. Libre d’utilisation pour tout usage pédagogique.
