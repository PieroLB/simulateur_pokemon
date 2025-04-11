#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "import.h"
using namespace std;

vector<string> split(string str, char sep){
    stringstream ss(str);
    string value;
    vector<string> result;
    while (getline(ss, value, sep)) {
        result.push_back(value);
    }
    return result;
}

void import() {
    ifstream file("data/types.csv");
    string line;

    while (getline(file, line)) {
        vector<string> row = split(line, ',');
        // Print the row
        for (const auto& item : row) {
            cout << item << " ";
        }
        cout << endl;
    }

    file.close();
}
