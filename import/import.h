// import/import.h
#ifndef IMPORT_H
#define IMPORT_H

#include <map>
#include <vector>
#include <string>

using namespace std;

// Déclaration de TypeInfo
struct TypeInfo {
    vector<string> faiblesse;
    vector<string> resistance;
};

// Déclaration de la variable globale types
extern map<string, TypeInfo> types;

void import();

#endif
