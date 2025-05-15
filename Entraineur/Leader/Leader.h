    #ifndef LEADER_H
#define LEADER_H

#include "../Entraineur.h"

using namespace std;

class Leader : public Entraineur {
private:
    string badge;
    string gymnase;

public:
    Leader(string name, string gymnase, string medaille, Pokemon* listPokemons[6]);
    ~Leader();
    void afficher() override;
    static vector<Leader*> allLeaders; 
    string getBadge() const;
    string getGymnase() const;
};

#endif
