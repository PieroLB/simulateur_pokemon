// Vérification que feu.h n'a pas déjà été défini
#ifndef FEU_H
#define FEU_H

#include "../../Pokemon/Pokemon.h"

using namespace std;

class Feu : public Pokemon {
public:
    Feu(string name, int hp);
    virtual ~Feu();

    void afficher() const override;
};

#endif
