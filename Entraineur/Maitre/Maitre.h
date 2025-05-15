#ifndef MAITRE_H
#define MAITRE_H

#include "../Entraineur.h"

using namespace std;

class Maitre : public Entraineur {
private:
public:
    Maitre(string name, Pokemon* listPokemons[6]);
    ~Maitre();
    void afficher() override;
    static vector<Maitre*> allMaitres; 
};

#endif
