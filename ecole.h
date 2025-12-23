#ifndef ECOLE_H
#define ECOLE_H

#include <iostream>
using namespace std;

class ecole {
protected:
    char* nom;
    char* adresse;
    int ne;
    int* eleve;

public:
    ecole(char* n = NULL, char* a = NULL, int ne = 0, int* e = NULL);
    ecole(const ecole& other);


    virtual ~ecole();


    char* get_nom() const;
    int get_eleve_niveau(int niveau) const;


    ecole& operator++();              // ++ecole
    ecole operator+(const ecole& e);  // fusion
    operator char*() const;           // conversion


    virtual void view() const;
};

#endif
