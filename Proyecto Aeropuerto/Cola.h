#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include"Pasajero.h"

class Cola{
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

        Nodo* posFrente;
        Nodo* posFinal;
    public:
        Cola();
        Cola(const Cola&);

        bool estaVacia(Nodo*);
        void encolar(const Pasajero&);

        Pasajero desencolar();
        Pasajero getFrente();

        Nodo* getFrentePos();
        Pasajero getFinal();
        string toString();
        string toString2();

};


#endif // COLA_H_INCLUDED
