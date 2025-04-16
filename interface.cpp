#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Pokemon/pokemon.h"
#include "Pokemon/Feu/feu.h"
#include "Pokemon/Eau/eau.h"
#include "Pokemon/Plante/plante.h"
#include "Entraineur/entraineur.h"
#include "Entraineur/Joueur/joueur.h"
#include "Entraineur/Leader/leader.h"
#include "Entraineur/Maitre/maitre.h"

using namespace std;

void showPokemonStats(Entraineur* trainer);
void showPlayerStats(Joueur* player);
void changePokemonOrder(Entraineur* trainer);
void showLeadersToFight(vector<Leader*> leaders);
void fightMaster(Maitre* master, Joueur* player);

int main() {
    srand(time(0));

    // Créer un joueur et quelques Pokémon pour l'équipe
    Joueur* player = new Joueur("Ash");
    Pokemon* charmander = new Feu("Charmander");
    Pokemon* squirtle = new Eau("Squirtle");
    Pokemon* bulbasaur = new Plante("Bulbasaur");

    player->addPokemon(charmander);
    player->addPokemon(squirtle);
    player->addPokemon(bulbasaur);

    // Créer des leaders de gym
    vector<Leader*> leaders;
    leaders.push_back(new Leader("Brock", "Badge Roche", "Pewter Gym"));
    leaders.push_back(new Leader("Misty", "Badge Cascade", "Cerulean Gym"));
    leaders.push_back(new Leader("Erika", "Badge Verdure", "Celadon Gym"));
    leaders.push_back(new Leader("Giovanni", "Badge Terre", "Viridian Gym"));

    // Créer un Maître Pokémon
    Maitre* master = new Maitre("Red");

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Afficher les Pokémon et leurs attributs\n";
        cout << "2. Récupérer les points de vie des Pokémon\n";
        cout << "3. Changer l'ordre des Pokémon dans l'équipe\n";
        cout << "4. Afficher les statistiques du joueur\n";
        cout << "5. Affronter un gymnase\n";
        cout << "6. Affronter un Maître Pokémon\n";
        cout << "7. Quitter\n";
        cout << "Choix: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showPokemonStats(player);
                break;
            case 2:
                // Code pour récupérer les HP des Pokémon
                break;
            case 3:
                changePokemonOrder(player);
                break;
            case 4:
                showPlayerStats(player);
                break;
            case 5:
                showLeadersToFight(leaders);
                break;
            case 6:
                if (player->getBadges() == 8) {  // Assurez-vous que le joueur a tous les badges
                    fightMaster(master, player);
                } else {
                    cout << "Vous devez obtenir tous les badges avant d'affronter le Maître Pokémon!\n";
                }
                break;
            case 7:
                cout << "Merci d'avoir joué !\n";
                break;
            default:
                cout << "Choix invalide, veuillez réessayer.\n";
        }
    } while (choice != 7);

    // Libération de la mémoire
    delete player;
    delete charmander;
    delete squirtle;
    delete bulbasaur;
    for (auto leader : leaders) {
        delete leader;
    }
    delete master;

    return 0;
}

void showPokemonStats(Entraineur* trainer) {
    cout << "\n--- Pokémon et leurs attributs ---\n";
    for (auto p : trainer->getTeam()) {
        cout << p->getName() << " (" << p->getType() << ") - HP: " << p->getHP() << "\n";
    }
}

void showPlayerStats(Joueur* player) {
    cout << "\n--- Statistiques du joueur ---\n";
    cout << "Badges: " << player->getBadges() << "\n";
    cout << "Combats gagnés: " << player->getWins() << "\n";
    cout << "Combats perdus: " << player->getLosses() << "\n";
}

void changePokemonOrder(Entraineur* trainer) {
    int index1, index2;
    cout << "Entrez les indices des Pokémon à échanger (0-5): ";
    cin >> index1 >> index2;
    if (index1 >= 0 && index1 < trainer->getTeam().size() && index2 >= 0 && index2 < trainer->getTeam().size()) {
        swap(trainer->getTeam()[index1], trainer->getTeam()[index2]);
        cout << "Les Pokémon ont été échangés !\n";
    } else {
        cout << "Indices invalides.\n";
    }
}

void showLeadersToFight(vector<Leader*> leaders) {
    cout << "\n--- Leaders de gym disponibles ---\n";
    for (int i = 0; i < leaders.size(); i++) {
        cout << i + 1 << ". " << leaders[i]->getName() << " - " << leaders[i]->getGym() << "\n";
    }

    int choice;
    cout << "Choisissez un leader à affronter (1-" << leaders.size() << "): ";
    cin >> choice;
    if (choice >= 1 && choice <= leaders.size()) {
        cout << "Vous affrontez " << leaders[choice - 1]->getName() << " dans le " << leaders[choice - 1]->getGym() << " !\n";
    } else {
        cout << "Choix invalide.\n";
    }
}

void fightMaster(Maitre* master, Joueur* player) {
    cout << "\n--- Combat contre le Maître Pokémon ---\n";
    cout << "Vous affrontez " << master->getName() << " !\n";

    // Simule un combat avec boost des attaques du Maître
    master->boostTeam();

    // Implémentez le combat ici selon vos règles de simulation

    // Exemple de résultat
    cout << "Le Maître Pokémon a été vaincu !\n";
    player->winCombat();  // Le joueur gagne le combat
    cout << "Félicitations ! Vous avez gagné !\n";
}
