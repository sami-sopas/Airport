#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include"Pasajero.h"

using namespace std;

class Pila{
    private:
        class Nodo{
            private:
                Nodo* siguiente;
                Pasajero* datoPtr;
            public:
                Nodo(const Pasajero&);
                ~Nodo();

                void setSiguiente(Nodo*);
                void setDatoPtr(Pasajero*);
                void setDato(const Pasajero&);

                Nodo* getSiguiente();
                Pasajero* getDatoPtr();
                Pasajero getDato();
        };

        Nodo* ancla;
    public:
        Pila();

        bool estaVacia();

        void push(const Pasajero&);
        Pasajero pop();
        Pasajero getTope();
        string toString();
};


#endif // PILA_H_INCLUDED
