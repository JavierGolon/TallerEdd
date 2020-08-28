#include "estudiante.h"

estudiante::estudiante(int id,string nombre,int edad)
{
    this->id =id;
    this->nombre = nombre;
    this->edad = edad;
}

int estudiante::getid(){
    return this->id;
}

string estudiante::getnombre(){
    return this->nombre;
}

int estudiante::getedad(){
    return this->edad;
}

void estudiante::setnombre(string nombre){
    this->nombre = nombre;
}

void estudiante::setedad(int edad){
    this->edad = edad;
}

void estudiante::setid(int id){
    this->id= id;
}
