#include "Maitre.h"
#include "../Entraineur.h"

using namespace std;

vector<Maitre*> Maitre::allMaitres; 

Maitre::Maitre(string name, Pokemon* listPokemons[6]) : Entraineur(name, listPokemons) {
    allMaitres.push_back(this);
}

void Maitre::afficher() {
    Entraineur::afficher();
}


Maitre::~Maitre(){}
