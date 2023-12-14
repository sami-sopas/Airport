#include"Pila.h"
#include<iostream>
using namespace std;

///NODO
Pila::Nodo::Nodo(const Pasajero& p){
    datoPtr = new Pasajero(p);
    siguiente = nullptr;

    if(datoPtr == nullptr){
        cout<<"No es posible crear el nodo"<<endl;
        exit(1);
    }
}

Pila::Nodo::~Nodo(){
    delete datoPtr;
}

void Pila::Nodo::setSiguiente(Nodo* p){
    siguiente = p;
}

void Pila::Nodo::setDatoPtr(Pasajero* p){
    datoPtr = p;
}

void Pila::Nodo::setDato(const Pasajero& e){
    if(datoPtr == nullptr){
        cout<<"El dato no existe"<<endl;
        exit(1);
    }

    *datoPtr = e;
}

typename Pila::Nodo* Pila::Nodo::getSiguiente(){
    return siguiente;
}

Pasajero Pila::Nodo::getDato(){
    if(datoPtr == nullptr){
        cout<<"El dato no existe"<<endl;
        exit(1);
    }
    return *datoPtr;
}

///PILA

Pila::Pila(): ancla(nullptr){}

bool Pila::estaVacia(){
    return ancla == nullptr;
}

void Pila::push(const Pasajero& e){
    Nodo* aux(new Nodo(e));

    if(aux == nullptr){
        cout<<"No se puede apilar mas"<<endl;
        exit(1);
    }

    aux->setSiguiente(ancla);
    ancla = aux;
}

Pasajero Pila::pop(){
    if(estaVacia()){
        cout<<"No hay elementos apilados"<<endl;
        exit(1);
    }

    Pasajero resultado(ancla->getDato());
    Nodo* aux(ancla);

    ancla = ancla->getSiguiente();

    delete aux;

    return resultado;
}

Pasajero Pila::getTope(){
    if(estaVacia()){
        cout<<"No hay elementos apilados"<<endl;
        exit(1);
    }
    return ancla->getDato();
}

string Pila::toString(){
    string impresion;
    Nodo* aux(ancla);

    while(aux != nullptr){
        impresion += aux->getDato().toString()+ "\n";
        aux = aux->getSiguiente();
    }
    return impresion;
}
