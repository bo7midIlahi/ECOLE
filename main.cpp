#include "ecole_privee.h"

int main() {
    int e1[6] = {20, 22, 25, 24, 23, 21};

    ecole* tab[2];
    tab[0] = new ecole("Public", "Tunis", 15, e1);
    tab[1] = new ecole_privee("Elite", "Ariana", 18, e1, "Ahmed", 50000);

    for (int i = 0; i < 2; i++) {
        tab[i]->view();
        cout << "-------------------" << endl;
    }

    for (int i = 0; i < 2; i++)
        delete tab[i];

    return 0;
}
