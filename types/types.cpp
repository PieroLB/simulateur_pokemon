#include <iostream>
#include <string>
using namespace std;

class Type {
protected:
    string nom;
    string* faiblesse;
    string* resistance;

public:
    Type(string nom, ){
        this->nom = nom;
        
    }
};

// class Pokemon : public Type {
// private:
//     string nom;
//     string type1;
//     string type2;
//     int hp;
//     int attaque;
//     int degats;

// public:
//     Pokemon(const string& n, const string& t1, const string& t2,
//             int h, int a, int d, const string& f, const string& r)
//         : Type(f, r), nom(n), type1(t1), type2(t2), hp(h), attaque(a), degats(d) {}

//     void afficher() const {
//         cout << "Nom : " << nom << "\nTypes : " << type1;
//         if (!type2.empty()) cout << " / " << type2;
//         cout << "\nHP : " << hp << ", Attaque : " << attaque << ", Degats : " << degats << endl;
//         afficherType();
//     }
// };
