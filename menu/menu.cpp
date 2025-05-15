#include <iostream>
#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif
#include <cstdlib>
#include <map>
#include <string>
#include "../Entraineur/Joueur/Joueur.h"
#include "../Entraineur/Leader/Leader.h"
#include "../Entraineur/Maitre/Maitre.h"
#include "../Pokemon/Pokemon.h"

using namespace std;

Joueur* monJoueur;

void afficherMonJoueur(){
    if (monJoueur != nullptr) cout << "Mon joueur : " << monJoueur->getName() << endl;
}


string getKey(){
    #ifdef _WIN32
        int key =  _getch();
        map<int, string> keyNames = {
            {13, "Entrée"},
            {224 << 8 | 72, "Flèche haut"},
            {224 << 8 | 80, "Flèche bas"},
        };
        if (key == 0 || key == 224) {
            int special = _getch();
            return keyNames[(key << 8) | special];
        }
        else {
            return keyNames[key];
        }
    #else
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        
        int key = getchar();
        
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        
        map<int, string> keyNames = {
            {10, "Entrée"},
            {65, "Flèche haut"},
            {66, "Flèche bas"},
        };
    
        if (key == 27) {
            if (getchar() == 91) {
                key = getchar();
                return keyNames[key];
            }
        } else {
            return keyNames[key];
        }
    
        return "Autre";
    #endif   
}

void appuyez(string pour) {
    cout << "\nAppuyez sur [Entrée] pour " << pour;
    while (true) {
        string key = getKey();
        if (key == "Entrée") {
            break;
        }
    }

}

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string repeatChar(string c, int n) {
    string result = "";
    for (int i=0; i<=n; i++) result += c;
    return result;
}

int menu(string title, vector<string> options, int posLocked=-1) {
    int position = 0;
    while (true) {
        clear();
        afficherMonJoueur();
        cout << title << endl;
        int nTitle = 0;
        for (size_t i=0; i<options.size(); i++) {
            string str = options[i];
            if (str.length() > 6 && str.substr(0,7) == "[title]") {
                nTitle++;
                cout << str.substr(7,str.length()) << endl;
            }
            else {
                cout << (((i-nTitle) == position || (i-nTitle) == posLocked) ? " * " : "   ") << str << endl;
            }
        }
        string key = getKey();
        if (key == "Flèche haut") {
            position = position == 0 ? options.size()-nTitle-1 : position-1;
            if (position == posLocked) position = position == 0 ? options.size()-nTitle-1 : position-1;
        }
        else if (key == "Flèche bas") {
            position = position == options.size()-nTitle-1 ? 0 : position+1;
            if (position == posLocked) position = position == options.size()-nTitle-1 ? 0 : position+1;
        }
        else if (key == "Entrée") {
            return position;
        }
    }
}


void afficherPokemons() {
    afficherMonJoueur();
    cout << "Mes pokémons : " << endl;
    Pokemon** listePokemon = monJoueur->getListPokemon();
    for (int i=0; i<6; i++) {
        listePokemon[i]->afficher();
    }
}
void changerOrdre() {
    Pokemon** listePokemon = monJoueur->getListPokemon();
    vector<string> menuOptions;
    for (size_t i=0; i<6; i++) {
        menuOptions.push_back(listePokemon[i]->getName());
    }
    int pos1 = menu("Changer l'ordre de mes Pokémons dans l'équipe :\nChoisissez le Pokémon que vous voulez déplacer :", menuOptions);
    int pos2 = menu("Changer l'ordre de mes Pokémons dans l'équipe :\nQuel Pokémon voulez-vous échanger avec celui-ci ?", menuOptions, pos1);
    Pokemon* newListPokemon[6];
    for (int i = 0; i < 6; i++) {
        if (i == pos1) {
            newListPokemon[i] = listePokemon[pos2];
        }
        else if (i == pos2) {
            newListPokemon[i] = listePokemon[pos1];
        }
        else {
            newListPokemon[i] = listePokemon[i];
        }
    }
    monJoueur->setListPokemon(newListPokemon);
    clear();
    afficherMonJoueur();
    cout << "Changer l'ordre de mes Pokémons dans l'équipe :\nL’ordre de votre équipe a bien été mis à jour. Nouvel ordre : " << endl;
    for (int i=0; i<6; i++) {
        cout << "   " << newListPokemon[i]->getName() << endl;
    }
}
void afficherStats() {
    afficherMonJoueur();
    cout << "Statistiques de mon joueur : " << endl;
    monJoueur->afficher();
}
void affronterLeader() {
    vector<string> menuOptions;
    vector<Leader*> leaders;
    for (size_t i=0; i<Leader::allLeaders.size(); i++) {
        if (Leader::allLeaders[i]->areMyPokemonsAlive()) {
            menuOptions.push_back(Leader::allLeaders[i]->getName());
            leaders.push_back(Leader::allLeaders[i]);
        }
    }
    int choix = menu("Affrontement avec un leader de gymnase :\nChoisissez le leader à affronter :", menuOptions);
    Leader* opposant = leaders[choix];
    monJoueur->combattre(opposant);
}
void affronterMaitre() {
    if (monJoueur->hasAllBadges()) {
        Maitre* opposant = Maitre::allMaitres[0];
        monJoueur->combattre(opposant);
    }
    else {
        cout << "Vous n'avez pas obtenu tous les badges des leaders pour combattre un maître.";
    }
}
void interagir() {
    if (monJoueur == nullptr) {
        cout << "Aucun joueur sélectionné pour interagir." << endl;
        return;
    }
    vector<string> menuOptions;
    vector<Interagir*> cibles;
    menuOptions.push_back("[title]Vos Pokémons : ");
    if (monJoueur->areMyPokemonsAlive()) {
        Pokemon** listePokemon = monJoueur->getListPokemon();
        for (size_t i=0; i<6; i++) {
            if (listePokemon[i] != nullptr && listePokemon[i]->getHP() > 0) {
                menuOptions.push_back(listePokemon[i]->getName());
                cibles.push_back(listePokemon[i]);
            }
        }
    }
    else {
        menuOptions.push_back("[title]Aucun de vos Pokémon n'est actuellement disponible pour une interaction.");
    }
    menuOptions.push_back("[title]\nEntraîneurs Vaincus : ");
    if (monJoueur->getEntraineursVaincus().empty()) {
        menuOptions.push_back("[title]   Vous n'avez vaincu aucun entraîneur pour le moment.");
    } else {
        for (Entraineur* entraineurVaincu : monJoueur->getEntraineursVaincus()) {
            menuOptions.push_back(entraineurVaincu->getName());
                cibles.push_back(entraineurVaincu);
        }
    }
    menuOptions.push_back("[title]");
    menuOptions.push_back("Retour au menu principal");
    int pos = menu("Menu d'Interaction :\n", menuOptions);
    if (pos == cibles.size()) return;
    Interagir* cible = cibles[pos];
    clear();
    afficherMonJoueur();
    cout << "\nVous interagissez avec ";
    if (dynamic_cast<Pokemon*>(cible)) {
        cout << dynamic_cast<Pokemon*>(cible)->getName();
    }
    else {
        cout << dynamic_cast<Entraineur*>(cible)->getName();
    }
    cout << " : " << endl;
    cout << cible->interagir() << endl;
}

void soigner() {
    afficherMonJoueur();
    if (monJoueur != nullptr) monJoueur->soigner();
    cout << "\nTous vos pokémons ont été soignés" << endl;
}

void mainMenu(){
    appuyez("jouer");
    while (true) {
        vector<string> menu1Options;
        for (size_t i=0; i<Joueur::allJoueurs.size(); i++) {
            menu1Options.push_back(Joueur::allJoueurs[i]->getName());
        }
        menu1Options.push_back("Quitter le jeu");
        int choix1 = menu("Choisissez votre joueur pour la partie : ", menu1Options);
        cout << choix1 << endl;
        if (choix1 >= 0 && choix1 < Joueur::allJoueurs.size()) {
            monJoueur = Joueur::allJoueurs[choix1];
            while (true) {
                vector<string> menu2Options = {
                    "Afficher mes pokémons et leurs attributs",
                    "Soigner mes pokémons",
                    "Changer l'ordre de mes Pokémons dans l'équipe",
                    "Afficher mes statistiques",
                    "Affronter un leader de gymnase",
                    "Affronter un maître",
                    "Intéragir avec les pokémons et les entraineurs vaincus",
                    "Retour au choix du joueur",
                    "Quitter le jeu",
                };
                int choix2 = menu("Menu principal", menu2Options);
                if (choix2 >= 0 && choix2 < menu2Options.size()-2) {
                    clear();
                    switch (choix2)
                    {
                        case 0:
                            afficherPokemons();
                            break;
                        case 1:
                            soigner();
                            break;
                        case 2:
                            changerOrdre();
                            break;
                        case 3:
                            afficherStats();
                            break;
                        case 4:
                            affronterLeader();
                            break;
                        case 5:
                            affronterMaitre();
                            break;
                        case 6:
                            interagir();
                            break;
                    }
                    appuyez("retourner au menu principal");
                }
                else if (choix2 == menu2Options.size()-2) break;
                else if (choix2 == menu2Options.size()-1) return;
            }            
        }
        else if (choix1 == Joueur::allJoueurs.size()) return;
    }
}