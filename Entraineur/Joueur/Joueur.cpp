#include "joueur.h"

using namespace std;

Joueur::Joueur(string name) : Entraineur(name) {
    this->badges = 0;
    this->wins = 0;
    this->losses = 0;
}

void Joueur::winCombat() {
    wins++;
}

void Joueur::loseCombat() {
    losses++;
}

void Joueur::addBadge() {
    badges++;
}

int Joueur::getBadges() const { return badges; }
int Joueur::getWins() const { return wins; }
int Joueur::getLosses() const { return losses; }
