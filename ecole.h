#include <iostream>
using namespace std;

class ecole{
    public:
        char *nom = NULL;
        char *adress = NULL;
        int ne = 0;
        int *eleve = NULL;
        bool check_eleve(int eleve){}
        ecole(char *_nom, char *_adress, int _ne, int *_eleve){};
        ecole(const ecole *e){};
        ~ecole(){};

        char get_nom(){}

        int get_eleve_niveau(int niveau){}

        ecole operator ++(){}

        ecole operator +(ecole e){}

        ecole operator *() {}

        void view(){}
    };

