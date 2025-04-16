// Vérification que feu.h n'a pas déjà été défini
#ifndef PLANTE_H
#define PLANTE_H

#include "../../Pokemon/Pokemon.h"

using namespace std;

class Plante : public Pokemon {
public:
    Plante(string name, int hp);
    virtual ~Plante();

    void afficher() const override;
};

#endif

