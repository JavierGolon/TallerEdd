#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <iostream>
#include <fstream>
using namespace  std;
class lista
{
public:
    lista();
    void insertar(estudiante*inf);
    void recorrer();
    string graficar();
    void reporte();
    void buscar(int id);
    void eliminar(int id);
    void ordenarASC();
    void ordenarDESC();
private:
    nodo * first;
    nodo * last;
    int size;
    void ordenarASC(nodo*head,int num);
    void ordenaDESC(nodo*head,int num);

};

#endif // LISTA_H
