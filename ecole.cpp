#include "ecole.h"
#include <cstring>

// Constructor
ecole::ecole(char* n, char* a, int ne, int* e) {
    if (ne < 0) throw "Nombre d'enseignants invalide";

    this->ne = ne;

    // nom
    if (n) {
        nom = new char[strlen(n) + 1];
        strcpy(nom, n);
    } else nom = NULL;

    // adresse
    if (a) {
        adresse = new char[strlen(a) + 1];
        strcpy(adresse, a);
    } else adresse = NULL;

    // eleve
    eleve = new int[6];
    for (int i = 0; i < 6; i++) {
        if (e && e[i] < 0) throw "Nombre d'élèves invalide";
        eleve[i] = (e ? e[i] : 0);
    }
}

// Copy constructor (VERY IMPORTANT)
ecole::ecole(const ecole& other) {
    ne = other.ne;

    nom = other.nom ? new char[strlen(other.nom) + 1] : NULL;
    if (nom) strcpy(nom, other.nom);

    adresse = other.adresse ? new char[strlen(other.adresse) + 1] : NULL;
    if (adresse) strcpy(adresse, other.adresse);

    eleve = new int[6];
    for (int i = 0; i < 6; i++)
        eleve[i] = other.eleve[i];
}

// Destructor
ecole::~ecole() {
    delete[] nom;
    delete[] adresse;
    delete[] eleve;
}

// Getters
char* ecole::get_nom() const {
    return nom;
}

int ecole::get_eleve_niveau(int niveau) const {
    if (niveau < 1 || niveau > 6) throw "Niveau invalide";
    return eleve[niveau - 1];
}

// ++ operator
ecole& ecole::operator++() {
    ne++;
    return *this;
}

// + operator (fusion)
ecole ecole::operator+(const ecole& e) {
    char nomTmp[100], adrTmp[100];
    cout << "Nom de la nouvelle école: ";
    cin >> nomTmp;
    cout << "Adresse de la nouvelle école: ";
    cin >> adrTmp;

    int tab[6];
    for (int i = 0; i < 6; i++)
        tab[i] = eleve[i] + e.eleve[i];

    return ecole(nomTmp, adrTmp, ne + e.ne, tab);
}

// char* conversion
ecole::operator char*() const {
    char buffer[300];
    sprintf(buffer, "Ecole %s, Adresse %s, Enseignants %d",
            nom, adresse, ne);

    char* res = new char[strlen(buffer) + 1];
    strcpy(res, buffer);
    return res;
}

// view()
void ecole::view() const {
    cout << "Nom: " << nom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Enseignants: " << ne << endl;
    for (int i = 0; i < 6; i++)
        cout << "Niveau " << i + 1 << ": " << eleve[i] << " élèves" << endl;
}
