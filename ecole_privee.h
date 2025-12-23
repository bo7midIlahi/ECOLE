#ifndef ECOLE_PRIVEE_H
#define ECOLE_PRIVEE_H

#include "ecole.h"

class ecole_privee : public ecole {
    char* gerant;
    float capital;

public:
    ecole_privee(char* n = NULL, char* a = NULL, int ne = 0, int* e = NULL,
                 char* g = NULL, float c = 0);

    ~ecole_privee();

    operator char*() const;
    void view() const override;
};

#endif
