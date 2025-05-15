#include "Leader.h"
#include "../Entraineur.h"

using namespace std;

vector<Leader*> Leader::allLeaders;

Leader::Leader(string name, string gymnase, string badge, Pokemon* listPokemons[6]) : Entraineur(name, listPokemons) {
    this->badge = badge;
    this->gymnase = gymnase;

    Leader::allLeaders.push_back(this);
}

void Leader::afficher() {
    Entraineur::afficher();
}


Leader::~Leader(){}

string Leader::getBadge() const {
    return badge;
}

string Leader::getGymnase() const {
    return gymnase;
}
