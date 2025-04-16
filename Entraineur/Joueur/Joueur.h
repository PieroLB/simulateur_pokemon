#ifndef JOUEUR_H
#define JOUEUR_H

#include "../entraineur.h"

using namespace std;

class Joueur : public Entraineur {
private:
    int badges;
    int wins;
    int losses;

public:
    Joueur(string name);
    void winCombat();
    void loseCombat();
    void addBadge();
    int getBadges() const;
    int getWins() const;
    int getLosses() const;
};

#endif
