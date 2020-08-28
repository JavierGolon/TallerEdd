#include "lista.h"

lista::lista()
{
    this->first = NULL;
    this->last = NULL;
    this->size = 0;
}


void lista::insertar(estudiante *inf){
    if(first ==  NULL){
      nodo * nuevo = new nodo(NULL,NULL,inf);
      this->first = nuevo;
      this->last = nuevo;
      nuevo->setsiguiente(this->first);
      nuevo->setanterior(this->last);
      this->size++;
    }else{
        nodo * nuevo = new nodo(this->first,this->last,inf);
        this->last->setsiguiente(nuevo);
        this->last->setanterior(nuevo);
        this->last = nuevo;
        this->size++;
    }
}


void lista::recorrer(){
    nodo * temp = this->first;
    if(temp !=NULL){
        do{
            cout<<temp->Infoestudiante->getnombre()<<"----";
            temp = temp->getsiguiente();

        }while(temp!=this->first);
    }
}

void lista::eliminar(int id){
    nodo * temp = this->first;
    nodo * ant;
    if(temp !=NULL){
        do{
            if(temp->Infoestudiante->getid()==id){
                if(temp ==first && temp == last){
                 first = NULL;
                 last  = NULL;
                 break;
                }else if(temp ==first){
                    this->first = this->first->getsiguiente();
                    this->first->setanterior(this->last);
                    this->last->setsiguiente(this->first);
                    delete(temp);
                    break;
                }else if(temp == last){
                    this->last = last->getanterior();
                    this->first->setanterior(this->last);
                    this->last->setsiguiente(this->first);
                    delete(temp);
                    break;
                }else{
                    ant->setsiguiente(temp->getsiguiente());
                    temp->getsiguiente()->setanterior(ant);
                    delete(temp);
                    break;
                }

            }
            ant = temp;
            temp = temp->getsiguiente();

        }while(temp!=this->first);
    }
}

void lista::ordenarASC(){
    ordenarASC(this->first,1);
}

void lista::ordenarASC(nodo*aux,int num){
    if(num <=this->size){
        nodo * temp =  this->first;
        do{
            if(temp->Infoestudiante->getid() < aux->Infoestudiante->getid()){
                estudiante * info = temp->Infoestudiante;
                temp->Infoestudiante = aux->Infoestudiante;
                aux->Infoestudiante = info;
            }
            temp = temp->getsiguiente();
        }while(temp!=this->first);
        num++;
        ordenarASC(aux->getsiguiente(),num);
    }
}


void lista::ordenarDESC(){
    ordenaDESC(this->first,1);
}

void lista::ordenaDESC(nodo*aux,int num){
    if(num <=this->size){
        nodo * temp =  this->first;
        do{
            if(temp->Infoestudiante->getid() > aux->Infoestudiante->getid()){
                estudiante * info = temp->Infoestudiante;
                temp->Infoestudiante = aux->Infoestudiante;
                aux->Infoestudiante = info;
            }
            temp = temp->getsiguiente();
        }while(temp!=this->first);
        num++;
        ordenarASC(aux->getsiguiente(),num);
    }
}


string lista::graficar(){
    string dot = "digraph {\n"
                 "  rankdir=LR;\n"
                 "  node[shape=record];";
    nodo * temp = this->first;
    if(temp !=NULL){
        do{
            dot+="t"+to_string(temp->Infoestudiante->getid())+" ";
            dot+="[ label = \""+temp->Infoestudiante->getnombre()+"\"] \n";
            if (temp->getsiguiente()!=first){
                dot+="t"+to_string(temp->Infoestudiante->getid())+"->";
                dot+="t"+to_string(temp->getsiguiente()->Infoestudiante->getid())+"\n";
            }else{
                dot+="t"+to_string(temp->Infoestudiante->getid())+"->";
                dot+="t"+to_string(first->Infoestudiante->getid())+"[constraint = false]\n";
            }

            temp = temp->getsiguiente();

        }while(temp!=this->first);
    }
    return dot+="}";
}

void lista::reporte(){
    string dot = graficar();
    ofstream archivo;
    archivo.open("lista.dot",ios::out);
    archivo <<dot;
    archivo.close();
    system("dot lista.dot -Tpng -o listadoble.png");

}
