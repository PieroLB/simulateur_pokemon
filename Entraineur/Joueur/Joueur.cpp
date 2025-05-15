#include "Joueur.h"
#include "../../menu/menu.h"
#include "../Leader/Leader.h"
#include "../Maitre/Maitre.h"
#include "../../Pokemon/Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>


using namespace std;

vector<Joueur*> Joueur::allJoueurs;

Joueur::Joueur(string name, Pokemon* listPokemons[6]) : Entraineur(name, listPokemons) {
    this->nWins = 0;
    this->nLosses = 0;

    Joueur::allJoueurs.push_back(this);
}

Joueur::~Joueur(){}


void Joueur::afficher() {
    Entraineur::afficher();

    cout << "Badges : ";
    if (this->badges.empty()) {
        cout << "aucun";
    }
    else {
        for (string badge : this->badges) {
            cout << badge << ", ";
        }    
    }
    cout << " | Nombre de victoires : " << this->nWins << " | Nombre de défaites : " << this->nLosses << endl;
}

string align(string s, int n) {
    int spacing = n-s.length();
    return s+repeatChar(" ", spacing);
}
void afficherEtatsJoueurs(Entraineur* moi, Entraineur* leader) {
    Pokemon* currentPokemonMoi = moi->currentPokemon();
    string nomPokemonMoi = currentPokemonMoi != nullptr ? currentPokemonMoi->getName() : "aucun";
    string hpPokemonMoi = currentPokemonMoi != nullptr ? to_string(currentPokemonMoi->getHP()) : "0";
    Pokemon* currentPokemonLeader = leader->currentPokemon();
    string nomPokemonLeader = currentPokemonLeader != nullptr ? currentPokemonLeader->getName() : "aucun";
    string hpPokemonLeader = currentPokemonLeader != nullptr ? to_string(currentPokemonLeader->getHP()) : "0";

    cout << align("Moi : "+moi->getName(),36) << align("Opposant : "+leader->getName(),48) << endl;
    cout << align("Pokemon : "+nomPokemonMoi,36) << align("Pokemon : "+nomPokemonLeader,24) << endl;
    cout << align("HP : "+hpPokemonMoi,36) << align("HP : "+hpPokemonLeader,24) << endl;
    string pokemonsMoi;
    string pokemonsLeader;
    int nbMortsMoi = moi->getNPokemonsDead();
    int nbMortsLeader= leader->getNPokemonsDead();
    for (int i = 1; i <= 6; ++i) {
        pokemonsMoi += (i <= nbMortsMoi) ? "X " : to_string(i) + " ";
        pokemonsLeader += (i <= nbMortsLeader) ? "X " : to_string(i) + " ";
    }
    cout << align("Pokemons : "+pokemonsMoi,36) << align("Pokemons : "+pokemonsLeader,24) << endl;
}


void Joueur::combattre(Entraineur* entraineur) {
    clear();
    afficherMonJoueur();
    cout << "Affrontement avec un entraineur : " << endl;
    afficherEtatsJoueurs(this, entraineur);
    appuyez("commencer le combat");
    bool isMyTurn = true;
    while (this->areMyPokemonsAlive() && entraineur->areMyPokemonsAlive()) {
        clear();
        afficherMonJoueur();
        cout << "Affrontement avec un entraineur : " << endl;
        if (isMyTurn) {
            this->attaquer(entraineur, "opposant");
        }
        else {
            entraineur->attaquer(this, "moi");
        }
        isMyTurn = !isMyTurn;
        afficherEtatsJoueurs(this, entraineur);
        appuyez("passer à l'attaque suivante");
    }
    if (dynamic_cast<Maitre*>(entraineur)) entraineur->soigner();
    if (!this->areMyPokemonsAlive()) {
        cout << "\n\nVous avez perdu..." << endl;
        this->nLosses += 1;
    }
    else {
        cout << "\n\nVous avez gagné ! " << endl;
        this->nWins += 1;
        Leader* leader = dynamic_cast<Leader*>(entraineur);
        if (leader != nullptr) {
            cout << "Vous avez gagné ce badge : " << leader->getBadge() << endl;
            this->badges.push_back(leader->getBadge());
        }
        if (dynamic_cast<Joueur*>(entraineur) == nullptr) { 
            bool dejaVaincu = false;
            for (Entraineur* e : entraineursVaincus) {
                if (e == entraineur) {
                    dejaVaincu = true;
                    break;
                }
            } 
            if (!dejaVaincu) {
                this->entraineursVaincus.push_back(entraineur);
                cout << entraineur->getName() << " peut maintenant être interagi." << endl;
            }
        }

    }
}

bool Joueur::hasAllBadges() {
    for (size_t i=0; i<Leader::allLeaders.size(); i++) {
        string badge = Leader::allLeaders[i]->getBadge();
        auto j = find(this->badges.begin(), this->badges.end(), badge);
        if (j == this->badges.end()) return false;
    }
    return true;
}

vector<Entraineur*> Joueur::getEntraineursVaincus() {
    return this->entraineursVaincus;
}