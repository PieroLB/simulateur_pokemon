#include "maitre.h"

using namespace std;

Maitre::Maitre(string name) : Entraineur(name) {}

void Maitre::boostTeam() {
    for (auto p : team) {
        int boostedPower = static_cast<int>(p->getAttackPower() * 1.25);
        p->setAttackPower(boostedPower);
    }
}
