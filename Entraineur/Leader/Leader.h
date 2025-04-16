#ifndef LEADER_H
#define LEADER_H

#include "../entraineur.h"

using namespace std;

class Leader : public Entraineur {
private:
    string badge;
    string gym;

public:
    Leader(string name, string badge, string gym);
    string getBadge() const;
    string getGym() const;
};

#endif
