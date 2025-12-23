#include "ecole_privee.h"
#include <cstring>

ecole_privee::ecole_privee(char* n, char* a, int ne, int* e,
                           char* g, float c)
    : ecole(n, a, ne, e) {

    capital = c;

    if (g) {
        gerant = new char[strlen(g) + 1];
        strcpy(gerant, g);
    } else gerant = NULL;
}

ecole_privee::~ecole_privee() {
    delete[] gerant;
}

ecole_privee::operator char*() const {
    char buffer[400];
    sprintf(buffer, "Ecole privée %s, Gérant %s, Capital %.2f",
            nom, gerant, capital);

    char* res = new char[strlen(buffer) + 1];
    strcpy(res, buffer);
    return res;
}

void ecole_privee::view() const {
    ecole::view();
    cout << "Gérant: " << gerant << endl;
    cout << "Capital: " << capital << endl;
}
