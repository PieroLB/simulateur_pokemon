// Vérification que feu.h n'a pas déjà été défini
#ifndef EAU_H
#define EAU_H

#include "../../Pokemon/Pokemon.h"

using namespace std;


class Eau : public Pokemon {
public:
    Eau(string name, int hp);
    virtual ~Eau();

    void afficher() const override;
};

#endif

