#include "Feu.h"
#include <iostream>

using namespace std;

Feu::Feu(string name, int hp)
    : Pokemon(name, {"Feu"}, hp, "Flammèche", 70) {
}

Feu::~Feu() {
}

void Feu::afficher() const {
    cout << name << " (Type : Feu, HP : " << hp << ", Attaque : " << attaque << ", Puissance : " << puissance << ")" << endl;
}
