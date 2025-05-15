#ifndef JOUEUR_H
#define JOUEUR_H

#include "../Entraineur.h"
#include <string>

using namespace std;

class Joueur : public Entraineur {
private:
    vector<string> badges;
    int nWins;
    int nLosses;
    vector<Entraineur*> entraineursVaincus;

public:
    Joueur(string name, Pokemon* listPokemons[6]);
    ~Joueur();
    static vector<Joueur*> allJoueurs;
    void afficher() override;
    void combattre(Entraineur* entraineur);
    bool hasAllBadges();
    vector<Entraineur*> getEntraineursVaincus();
};

#endif
