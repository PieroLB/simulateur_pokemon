#include "entraineur.h"

using namespace std;

Entraineur::Entraineur(string name) {
    this->name = name;
}

Entraineur::~Entraineur() {
    for (auto p : team) {
        delete p;
    }
}

void Entraineur::addPokemon(Pokemon* p) {
    if (team.size() < 6)
        team.push_back(p);
}

string Entraineur::getName() const {
    return name;
}

vector<Pokemon*> Entraineur::getTeam() const {
    return team;
}
