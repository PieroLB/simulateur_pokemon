#ifndef INTERAGIR_H
#define INTERAGIR_H

#include <string>
#include <iostream> 
using namespace std;

class Interagir {
public:
    virtual ~Interagir() = default;
    virtual string interagir() const = 0;
};

#endif 