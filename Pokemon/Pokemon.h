// Vérification que pokemon.h n'a pas déjà été défini
#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "../Interagir/Interagir.h"

using namespace std;


class Pokemon : public Interagir {
protected:
    string name;
    string type1;
    string type2;
    int maxHP;
    int hp;
    string attaque;
    int puissance;
    string messageInteraction;

public:
    Pokemon(string name, string type1, string type2, int hp, string attaque, int puissance, string msgInteraction = "...");
    Pokemon(const Pokemon& p); 
    virtual ~Pokemon();

    static vector<Pokemon*> allPokemons;

    string getName() const;
    int getHP() const;
    string getAttaque() const;
    int getPuissance() const;
    virtual void afficher() const;
    float getCoefAttaque(Pokemon* opposant) const; 
    void damage(float degat);
    void soigner();
    string interagir() const override;
    bool operator ==(int value);
    bool operator >(int value);
    bool operator <(int value);
    bool operator >=(int value);
    bool operator <=(int value);
};

#endif
