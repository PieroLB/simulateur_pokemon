#ifndef MAITRE_H
#define MAITRE_H

#include "../entraineur.h"

using namespace std;

class Maitre : public Entraineur {
public:
    Maitre(string name);
    void boostTeam();
};

#endif
