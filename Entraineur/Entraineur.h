#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include <string>
#include <vector>
#include "../Pokemon/Pokemon.h"
#include "../Interagir/Interagir.h"

using namespace std;

class Entraineur : public Interagir  {
protected:
    string name;
    Pokemon* listPokemons[6];
    string messageInteractionDefaite;

public:
    Entraineur(string name, Pokemon* listPokemons[6],string msgDefaite = "");
    virtual ~Entraineur();

    virtual void afficher();  
    string getName();
    Pokemon** getListPokemon();
    void setListPokemon(Pokemon* newListPokemon[6]);
    bool areMyPokemonsAlive();
    void damage(float degats);
    void attaquer(Entraineur* entraineur, string cible);
    Pokemon* currentPokemon();
    int getNPokemonsDead();
    void soigner();

    virtual string interagir() const override;
    void setMessageInteractionDefaite(const string& msg);
};

#endif
