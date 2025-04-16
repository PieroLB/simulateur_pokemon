#include "Plante.h"
#include <iostream>

Plante::Plante(string name, int hp)
    : Pokemon(name, {"Plante"}, hp, "Fouet Lianes", 60) {
}

Plante::~Plante() {
}

void Plante::afficher() const {
    cout << name << " (Type : Plante, HP : " << hp << ", Attaque : " << attaque << ", Puissance : " << puissance << ")" << endl;
}
