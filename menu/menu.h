// import/import.h
#ifndef MENU_H
#define MENU_H

#include <string>  
#include <vector>
using namespace std;

void afficherMonJoueur();
void appuyez(string pour);
void clear();
string repeatChar(string c, int n);
int menu(string title, vector<string> options, int posLocked=-1);
void mainMenu();

#endif
