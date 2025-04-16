#include "Pokemon.h"
#include <iostream>

using namespace std;

Pokemon::Pokemon(string name, vector<string> types, int hp, string attaque, int puissance) {
    this->name = name;
    this->types = types;
    this->hp = hp;
    this->attaque = attaque;
    this->puissance = puissance;
}

Pokemon::~Pokemon() {
}

string Pokemon::getName() const {
    return name;
}

int Pokemon::getHP() const {
    return hp;
}

void Pokemon::afficher() const {
    cout << name << " (" << hp << " HP)" << endl;
}

int Pokemon::calculerDegats(const string& typeAttaque, int puissanceAttaque) const {
    // On pourrait utiliser le tableau de faiblesses ici
    // Pour l'instant renvoie les dégâts bruts
    return puissanceAttaque;
}
