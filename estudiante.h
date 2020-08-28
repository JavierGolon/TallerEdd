#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
using namespace std;

class estudiante
{
public:
    estudiante(int id,string nombre,int edad);
    int getid();
    string getnombre();
    int getedad();
    void setnombre(string nombre);
    void setid(int id);
    void setedad(int edad);
private:
    int id;
    string nombre;
    int edad;
};

#endif // ESTUDIANTE_H
