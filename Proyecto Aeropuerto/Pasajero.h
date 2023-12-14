#ifndef PASAJERO_H_INCLUDED
#define PASAJERO_H_INCLUDED
#include"Fecha.h"
#include"Hora.h"
#include<string>
using namespace std;

class Pasajero{
    private:
        string nombre;
        string destino;
        int id;
        Fecha fecha;
        int boleto;
        string asiento;
        int equipaje;
        Hora horario;
    public:
        Pasajero(); //Constructor
        Pasajero(const Pasajero&);//Constructor copia

        //Setters
        void setNombre(const string&);
        void setDestino(const string&);
        void setId(const int&);
        void setFecha(const Fecha&);
        void setBoleto(const int&);
        void setAsiento(const string&);
        void setEquipaje(const int&);
        void setHorario(const Hora&);

        //Getters
        string getNombre();
        string getDestino();
        int getId();
        Fecha getFecha();
        int getBoleto();
        string getAsiento();
        int getEquipaje();
        Hora getHorario();

        string toString(); //Para imprimir todos los datos
        string toString2(); //Para imprimir solo nombre y maletas

        Pasajero& operator = (const Pasajero&);//Sobrecarga del operador =
};


#endif // PASAJERO_H_INCLUDED
