#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include "import.h"
#include "../Pokemon/Pokemon.h"
#include "../Entraineur/Joueur/Joueur.h"
#include "../Entraineur/Leader/Leader.h"
#include "../Entraineur/Maitre/Maitre.h"
using namespace std;

vector<string> split(string str, char sep){
    vector<string> result;
    if (str.empty()) {
        return result;
    }
    stringstream ss(str);
    string value;
    while (getline(ss, value, sep)) {
        result.push_back(value);
    }
    return result;
}

map<string, TypeInfo> types;
void importTypes(){
    ifstream file("import/data/types.csv");

    if (!file.is_open()) {
        cout << "\t❌ Erreur lors de l'importation des types. Erreur : le fichier 'types.csv' n'a pas pu être ouvert" << endl;
        return;
    }

    string line;
    getline(file, line); // permet d'éviter de prendre la première ligne de définition des colonnes    

    while (getline(file, line)) {
        vector<string> row = split(line, ',');
        string name = row[0];
        vector<string> faiblesse = split(row[1], '/');
        vector<string> resistance = split(row[2], '/');
        types[name] = {faiblesse, resistance};
    }

    file.close(); 

    cout << "\t✅ Importation des types réussie ! " << endl;
}

void importPokemons(){
    ifstream file("import/data/pokemon.csv");

    if (!file.is_open()) {
        cout << "\t❌ Erreur lors de l'importation des pokemons. Erreur : le fichier 'pokemons.csv' n'a pas pu être ouvert" << endl;
        return;
    }

    string line;
    getline(file, line); // permet d'éviter de prendre la première ligne de définition des colonnes    

    while (getline(file, line)) {
        vector<string> row = split(line, ',');
        string name = row[0];
        string type1 = row[1];
        string type2 = row[2];
        int hp = stoi(row[3]);
        string attaque = row[4];
        int puissance = stoi(row[5]);
        string msgInteract = (row.size() > 6) ? row[6] : name + " fait un petit bruit.";
        Pokemon* pokemon = new Pokemon(name, type1, type2, hp, attaque, puissance, msgInteract);
    }

    file.close(); 

    cout << "\t✅ Importation des pokémons réussie ! " << endl;
}


void importJoueurs(){
    ifstream file("import/data/joueurs.csv");

    if (!file.is_open()) {
        cout << "\t❌ Erreur lors de l'importation des joueurs. Erreur : le fichier 'joueurs.csv' n'a pas pu être ouvert" << endl;
        return;
    }

    string line;
    getline(file, line); // permet d'éviter de prendre la première ligne de définition des colonnes    

    while (getline(file, line)) {
        vector<string> row = split(line, ',');
        string name = row[0];
        Pokemon* listPokemons[6];
        for (int i=0; i<6; i++){
            for (Pokemon* p : Pokemon::allPokemons) {
                if (p->getName() == row[i+1]) {
                    listPokemons[i] = new Pokemon(*p);
                    break;
                }
            }
        }
        Joueur* joueur = new Joueur(name, listPokemons);
    }

    file.close(); 

    cout << "\t✅ Importation des joueurs réussie ! " << endl;
}

void importLeaders(){
    ifstream file("import/data/leaders.csv");

    if (!file.is_open()) {
        cout << "\t❌ Erreur lors de l'importation des leaders. Erreur : le fichier 'leaders.csv' n'a pas pu être ouvert" << endl;
        return;
    }

    string line;
    getline(file, line); // permet d'éviter de prendre la première ligne de définition des colonnes    

    while (getline(file, line)) {
        vector<string> row = split(line, ',');
        string name = row[0];
        string gymnase = row[1];
        string medaille = row[2];
        Pokemon* listPokemons[6];
        for (int i=0; i<6; i++){
            for (Pokemon* p : Pokemon::allPokemons) {
                if (p->getName() == row[i+3]) {
                    listPokemons[i] = new Pokemon(*p);
                    break;
                }
            }
        }
        Leader* leader = new Leader(name, gymnase, medaille, listPokemons);
    }

    file.close(); 

    cout << "\t✅ Importation des leaders réussie ! " << endl;
}

void importMaitres(){
    ifstream file("import/data/maitres.csv");

    if (!file.is_open()) {
        cout << "\t❌ Erreur lors de l'importation des maitres. Erreur : le fichier 'maitres.csv' n'a pas pu être ouvert" << endl;
        return;
    }

    string line;
    getline(file, line); // permet d'éviter de prendre la première ligne de définition des colonnes    

    while (getline(file, line)) {
        vector<string> row = split(line, ',');
        string name = row[0];
        Pokemon* listPokemons[6];
        for (int i=0; i<6; i++){
            for (Pokemon* p : Pokemon::allPokemons) {
                if (p->getName() == row[i+1]) {
                    listPokemons[i] = new Pokemon(*p);
                    break;
                }
            }
        }
        Maitre* maitre = new Maitre(name, listPokemons);
    }

    file.close(); 

    cout << "\t✅ Importation des maitres réussie ! " << endl;
}


void import() {
    cout << "Importation des données : " << endl;
    importTypes();
    importPokemons();
    importJoueurs();
    importLeaders();
    importMaitres();
}
