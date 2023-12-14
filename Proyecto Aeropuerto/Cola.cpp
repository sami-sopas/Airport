#include"Cola.h"
#include<iostream>
using namespace std;

///NODO
Cola::Nodo::Nodo(const Pasajero& p){
    datoPtr = new Pasajero(p);
    siguiente = nullptr;

    if(datoPtr == nullptr){
        cout<<"Error"<<endl;
        exit(1);
    }
}

Cola::Nodo::~Nodo(){
    delete datoPtr;
}

void Cola::Nodo::setSiguiente(Nodo* p){
    siguiente = p;
}

void Cola::Nodo::setDatoPtr(Pasajero* p){
    datoPtr = p;
}

void Cola::Nodo::setDato(const Pasajero& e){
    if(datoPtr == nullptr){
        cout<<"El dato no existe"<<endl;
        exit(1);
    }
    *datoPtr = e;
}

typename Cola::Nodo* Cola::Nodo::getSiguiente(){
    return siguiente;
}

Pasajero* Cola::Nodo::getDatoPtr(){
    return datoPtr;
}

Pasajero Cola::Nodo::getDato(){
    if(datoPtr == nullptr){
        cout<<"El dato no existe"<<endl;
        exit(1);
    }
    return *datoPtr;
}

///COLA
Cola::Cola(){
    posFrente = nullptr;
    posFinal = nullptr;
}

bool Cola::estaVacia(Nodo* p) {
    return p == nullptr;
}

void Cola::encolar(const Pasajero& e) {
    Nodo* aux(new Nodo(e));

    if(aux == nullptr){
        cout<<"No se puede encolar"<<endl;
        exit(1);
    }

    if(estaVacia(posFrente)){
        posFrente = aux;
    }else{
        posFinal->setSiguiente(aux);
    }
    posFinal = aux;
}

Pasajero Cola::desencolar(){
    if(estaVacia(posFrente)){
        cout<<"La cola esta vacia"<<endl;
        exit(1);
    }

    Nodo* aux(posFrente);

    Pasajero resultado(aux->getDato());

    if(posFrente == posFinal){
        posFrente = nullptr;
        posFinal = nullptr;
    }else{
        posFrente = posFrente->getSiguiente();
    }

    delete aux;

    return resultado;
}

Pasajero Cola::getFrente(){
    if(estaVacia(posFrente)){
        cout<<"Dato inexistente"<<endl;
        exit(1);
    }
    return posFrente->getDato();
}

typename Cola::Nodo* Cola::getFrentePos(){
    return posFrente;
}

Pasajero Cola::getFinal(){
    if(estaVacia(posFinal)){
        cout<<"Dato Inexistente"<<endl;
        exit(1);
    }
    return posFinal->getDato();
}

string Cola::toString(){
    Nodo* aux(posFrente);
    string impresion;

    while(aux != nullptr){
        impresion = impresion + aux->getDato().toString() + "\n";
        aux = aux->getSiguiente();
    }
    return impresion;
}

string Cola::toString2(){
    Nodo* aux(posFrente);
    string impresion;

    while(aux != nullptr){
        impresion = impresion + aux->getDato().toString2() + "\n";
        aux = aux->getSiguiente();
    }
    return impresion;
}

