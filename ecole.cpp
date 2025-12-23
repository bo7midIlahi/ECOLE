#include <iostream>
#include "ecole.h"
using namespace std;

class ecole{
    public:
        char *nom = NULL;
        char *adress = NULL;
        int ne = 0;
        int *eleve = NULL;
        bool check_eleve(int eleve){
            for (int i = 0; i < 5; i++)
            {
                if ((eleve+i)<0)
                {
                    return false;
                }
            }
            return true;
            
        }
        ecole(char *_nom, char *_adress, int _ne, int *_eleve){
            this->nom = _nom;
            this->adress = _adress;
            if (_ne<0 || !check_eleve(*eleve))
            {
                cout <<"NE<0 || ELEVE<0" << endl;
            }
            
            this->ne = _ne;
            this->eleve = _eleve;
        };
        ecole(const ecole *e){
            this->nom = e->nom;
            this->adress = e->adress;
            this->ne = e->ne;
            this->eleve = e->eleve;
        };
        ~ecole(){
            delete [] eleve;
        };

        char get_nom(){
            char full_name[15];
            int c = 0;
            while ((nom+c)!=NULL)
            {
                full_name[c] = *(nom+c);
                c++;
            }

            return full_name[15];
        }

        int get_eleve_niveau(int niveau){
            return (eleve[niveau]);
        }

        ecole operator ++(){
            this->ne += 1;
        }

        ecole operator +(ecole e){
            char new_name[15];
            char new_adr[15];

            cout << "enter new_name : ";
            cin >> new_name;

            cout << "enter new_adr : ";
            cin >> new_adr;

            this->nom = new_name;
            this->adress = new_adr;
            this->ne += e.ne;
            for (int i = 0; i < 5; i++)
            {
                this->eleve[i] += e.eleve[i];
            }
        }

        ecole operator *() {
            char str[100];
            sprintf(str,"nom:%s adr:%s ne:%d, ",get_nom(),this->adress,this->ne);
            for (int i = 0; i < 5; i++)
            {
                sprintf(str,"eleve[%d]:%d",i,eleve[i]);
            }
        }

        void view(){
            printf(ecole::operator*);
        }
    };

