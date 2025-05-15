#include "Entraineur.h"
#include "../Pokemon/Pokemon.h"
#include "../menu/menu.h"
#include <iostream>
#include <cmath>
#include <sstream>
// #include <iomanip>

using namespace std;

Entraineur::Entraineur(string name, Pokemon* listPokemons[6], string msgDefaite) {
    this->name = name;
    for (int i=0; i<6; i++){
        this->listPokemons[i] = listPokemons[i];
    }
    this->messageInteractionDefaite=msgDefaite;
    if (this->messageInteractionDefaite.empty()) {
        this->messageInteractionDefaite = this->name + " hoche la tête. 'Bien joué...'";
    }
}

Entraineur::~Entraineur() {
    for (auto p : listPokemons) {
        delete p;
    }
}

string Entraineur::interagir() const {
    if(messageInteractionDefaite.empty()){
        return name + " vous regarde sans rien dire.";
    }
    return name + " : \"" + messageInteractionDefaite + "\"";
}

void Entraineur::afficher() {
    cout << "Nom : " << this->name << " | Pokemon 1 : " << this->listPokemons[0]->getName() << " | Pokemon 2 : " << this->listPokemons[1]->getName() << " | Pokemon 3 : " << this->listPokemons[2]->getName() << " | Pokemon 4 : " << this->listPokemons[3]->getName() << " | Pokemon 5 : " << this->listPokemons[4]->getName() << " | Pokemon 6 : " << this->listPokemons[5]->getName() << endl;
}

string Entraineur::getName() {
    return this->name;
}

Pokemon** Entraineur::getListPokemon(){
    return this->listPokemons;
}

void Entraineur::setListPokemon(Pokemon* newListPokemon[6]) {
    for (int i = 0; i < 6; ++i) {
        this->listPokemons[i] = newListPokemon[i];
    }
}

void Entraineur::setMessageInteractionDefaite(const string& msg) {
    this->messageInteractionDefaite = msg;
}

bool Entraineur::areMyPokemonsAlive(){
    for (int i = 0; i < 6; ++i) {
        if (*this->listPokemons[i] > 0) return true;
    }
    return false;
}

Pokemon* Entraineur::currentPokemon() {
    for (int i = 0; i < 6; ++i) {
        Pokemon* pokemon = this->listPokemons[i];
        if (*pokemon > 0) {
            return pokemon;
        }
    }
    return nullptr;
}
int Entraineur::getNPokemonsDead() {
    int n = 0;
    for (int i = 0; i < 6; ++i) {
        Pokemon* pokemon = this->listPokemons[i];
        if (pokemon->getHP() <= 0) {
            n++;
        }
    }
    return n;
}

void Entraineur::damage(float degats) {
    
}

string to_string_float(float f) {
    ostringstream oss;
    oss << f;
    return oss.str();
}

void afficherAttaque(string cible, string nom, int puissance, float coef) {
    string attaque = "Attaque : " + nom;
    string degats = "Dégats : " + to_string(puissance) + " x " + to_string_float(coef) + " = " + to_string_float(puissance*coef);
    int m = max(attaque.length(), degats.length());
    int space1 = floor((48-m)/4);
    int space2 = floor((m-attaque.length())/2);
    int space3 = floor((m-degats.length())/2);
    cout << repeatChar(" ", space1) << " " << repeatChar("_", space1) << repeatChar(" ", space2) << attaque << repeatChar(" ", space2+1) << repeatChar("_", space1) << " " << repeatChar(" ", space1) << endl;
    cout << repeatChar(" ", space1) << "|" << repeatChar(" ", space1) << repeatChar(" ", space3) << degats << repeatChar(" ", space3) << repeatChar(" ", space1) << "|" << repeatChar(" ", space1) << endl;
    cout << repeatChar(" ", space1) << "|" << repeatChar(" ", space1) << repeatChar(" ", space3*2+degats.length()) << repeatChar(" ", space1) << "|" << repeatChar(" ", space1) << endl;
    cout << repeatChar(" ", cible=="moi"?space1-1:space1) << (cible=="moi"?"\\":"") << "|" << (cible=="moi"?"/":"") << repeatChar(" ", cible=="moi"?space1-1:space1) << repeatChar(" ", space3*2+degats.length()) << repeatChar(" ", cible=="opposant"?space1-1:space1) << (cible=="opposant"?"\\":"") << "|" << (cible=="opposant"?"/":"") << repeatChar(" ", cible=="opposant"?space1-1:space1) << endl;
}

void Entraineur::attaquer(Entraineur* entraineur, string cible) {
    Pokemon* myPokemon = this->currentPokemon();
    Pokemon* opposantPokemon = entraineur->currentPokemon();
    string attaque = myPokemon->getAttaque() ;
    int puissance = myPokemon->getPuissance() ;
    float coef = myPokemon->getCoefAttaque(opposantPokemon);
    float degats = puissance * coef;
    afficherAttaque(cible, attaque, puissance, coef);
    opposantPokemon->damage(degats);
}

void Entraineur::soigner() {
    for (int i = 0; i < 6; ++i) {
        Pokemon* pokemon = this->listPokemons[i];
        pokemon->soigner();
    }
}
