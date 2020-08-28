#ifndef NODO_H
#define NODO_H
#include "estudiante.h"

class nodo
{
public:
    nodo* siguiente;
    nodo* anterior;
    estudiante* Infoestudiante;
    nodo(nodo*s,nodo*a,estudiante*stu);
    void setsiguiente(nodo* sig);
    void setanterior(nodo*ant);
    nodo* getsiguiente();
    nodo * getanterior();
};

#endif // NODO_H
