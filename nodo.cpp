#include "nodo.h"

nodo::nodo(nodo*s,nodo*a,estudiante*stu)
{
    this->siguiente= s;
    this->anterior = a;
    this->Infoestudiante = stu;
}

void nodo::setsiguiente(nodo *sig){
    this->siguiente=sig;
}

void nodo::setanterior(nodo *ant){
    this->anterior=ant;
}

nodo* nodo::getsiguiente(){
    return siguiente;
}

nodo* nodo::getanterior(){
    return anterior;
}
