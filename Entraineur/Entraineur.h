#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include <string>
#include <vector>
#include "../Pokemon/pokemon.h"

using namespace std;

class Entraineur {
protected:
    string name;
    vector<Pokemon*> team;

public:
    Entraineur(string name);
    virtual ~Entraineur();
    
    void addPokemon(Pokemon* p);
    string getName() const;
    vector<Pokemon*> getTeam() const;
};

#endif
