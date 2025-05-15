#include "Pokemon.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdlib>
#include "../import/import.h"

using namespace std;

vector<Pokemon*> Pokemon::allPokemons;

Pokemon::Pokemon(string name, string type1, string type2, int hp, string attaque, int puissance, string msgInteraction) {
    this->name = name;
    if (types.find(type1) == types.end()) {
        cout << "❌ Echec lors de la création d'un pokémon. Erreur : le type '" << type1 << "' n'existe pas ! " << endl;
        exit(1);
    }
    this->type1 = type1;
    if (type2 != "" && types.find(type2) == types.end()) {
        cout << "❌ Echec lors de la création d'un pokémon. Erreur : le type '" << type2 << "' n'existe pas ! " << endl;
        exit(1);
    }
    this->type2 = type2;
    this->maxHP = hp;
    this->hp = hp;
    this->attaque = attaque;
    this->puissance = puissance;
    this->messageInteraction=msgInteraction;
    if (this->messageInteraction == "...") {
        this->messageInteraction = this->name + " Coucou !";
    }

    Pokemon::allPokemons.push_back(this);
}
Pokemon::Pokemon(const Pokemon& p) {
    this->name = p.name;
    if (types.find(p.type1) == types.end()) {
        cout << "❌ Echec lors de la création d'un pokémon. Erreur : le type '" << p.type1 << "' n'existe pas ! " << endl;
        exit(1);
    }
    this->type1 = p.type1;
    if (p.type2 != "" && types.find(p.type2) == types.end()) {
        cout << "❌ Echec lors de la création d'un pokémon. Erreur : le type '" << p.type2 << "' n'existe pas ! " << endl;
        exit(1);
    }
    this->type2 = p.type2;
    this->hp = p.hp;
    this->maxHP = p.maxHP;
    this->attaque = p.attaque;
    this->puissance = p.puissance;
    this->messageInteraction=p.messageInteraction;
}

Pokemon::~Pokemon() {
}

string Pokemon::interagir() const{
    return this->messageInteraction;
}

string Pokemon::getName() const {
    return name;
}

int Pokemon::getHP() const {
    return hp;
}

string Pokemon::getAttaque() const {
    return attaque;
}
int Pokemon::getPuissance() const {
    return puissance;
}

void Pokemon::afficher() const {
    cout << "Name : " << this->name << " | Type n°1 : " << this->type1 << " | Type n°2 : " << (this->type2==""?"Aucun":this->type2) << " | HP : " << (this->hp < 0 ? 0 : this->hp) << " | Attaque : " << this->attaque << " | Puissance : " << this->puissance << endl;
}

float Pokemon::getCoefAttaque(Pokemon* opposant) const {
    auto indexFaiblesse = find(types[opposant->type1].faiblesse.begin(), types[opposant->type1].faiblesse.end(), this->type1);
    if (indexFaiblesse != types[opposant->type1].faiblesse.end()) {
        return 2.0;
    }
    else {
        auto indexResistance = find(types[opposant->type1].resistance.begin(), types[opposant->type1].resistance.end(), this->type1);
        if (indexResistance != types[opposant->type1].resistance.end()) {
            return 0.5;
        }
        else {
            return 1.0;
        }
    }
}

void Pokemon::damage(float degats) {
    this->hp -= degats;
}

void Pokemon::soigner() {
    this->hp = this->maxHP;
}


bool Pokemon::operator ==(int value) {
    return this->getHP() == value;
}
bool Pokemon::operator >(int value) {
    return this->getHP() > value;
}
bool Pokemon::operator <(int value) {
    return this->getHP() < value;
}
bool Pokemon::operator >=(int value) {
    return this->getHP() >= value;
}
bool Pokemon::operator <=(int value) {
    return this->getHP() <= value;
}