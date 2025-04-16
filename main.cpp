#include <iostream>
#include "import/import.h"
#include "types/Feu/Feu.h"
#include "types/Eau/Eau.h"
#include "types/Plante/Plante.h"
using namespace std;

int main() {
    // import();
    Feu salameche("Salamèche", 39);
    Eau carapuce("Carapuce", 44);
    Plante bulbizarre("Bulbizarre", 45);

    cout << "lol" << endl;
    

    salameche.afficher();
    carapuce.afficher();
    bulbizarre.afficher();
    return 0;
}
