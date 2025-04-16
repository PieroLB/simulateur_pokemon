#include "Eau.h"
#include <iostream>

using namespace std;

Eau::Eau(string name, int hp)
    : Pokemon(name, {"Eau"}, hp, "Pistolet à O", 65) {
}

Eau::~Eau() {
}

void Eau::afficher() const {
    cout << name << " (Type : Eau, HP : " << hp << ", Attaque : " << attaque << ", Puissance : " << puissance << ")" << endl;
}
