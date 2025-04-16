// Vérification que pokemon.h n'a pas déjà été défini
#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
using namespace std;

class Pokemon {
protected:
    string name;
    vector<string> types;
    int hp;
    string attaque;
    int puissance;

public:
    Pokemon(string name, vector<string> types, int hp, string attaque, int puissance);
    virtual ~Pokemon();

    string getName() const;
    int getHP() const;
    virtual void afficher() const;
    int calculerDegats(const string& typeAttaque, int puissanceAttaque) const;
};

#endif
