#include"Pasajero.h"
#include"Fecha.h"
#include"Hora.h"
using namespace std;

Pasajero::Pasajero(){}

Pasajero::Pasajero(const Pasajero& p): nombre(p.nombre), destino(p.destino), id(p.id), fecha(p.fecha), boleto(p.boleto), asiento(p.asiento), equipaje(p.equipaje), horario(p.horario) {}

void Pasajero::setNombre(const string& n)
{
    nombre = n;
}

void Pasajero::setDestino(const string& d)
{
    destino = d;
}

void Pasajero::setId(const int& i)
{
    id = i;
}

void Pasajero::setFecha(const Fecha& f)
{
    fecha = f;
}

void Pasajero::setBoleto(const int& b)
{
    boleto = b;
}

void Pasajero::setAsiento(const string& a)
{
    asiento = a;
}

void Pasajero::setEquipaje(const int& e)
{
    equipaje = e;
}

void Pasajero::setHorario(const Hora& h)
{
    horario = h;
}

string Pasajero::getNombre()
{
    return nombre;
}

string Pasajero::getDestino()
{
    return destino;
}

int Pasajero::getId()
{
    return id;
}

Fecha Pasajero::getFecha()
{
    return fecha;
}

int Pasajero::getBoleto()
{
    return boleto;
}

string Pasajero::getAsiento()
{
    return asiento;
}

int Pasajero::getEquipaje()
{
    return equipaje;
}

Hora Pasajero::getHorario()
{
    return horario;
}

string Pasajero::toString()
{
    string imprimir;
    char myId[10];
    char myBoleto[10];
    char myEquipaje[10];
    sprintf_s(myId,"%i",id);
    sprintf_s(myBoleto,"%i",boleto);
    sprintf_s(myEquipaje,"%i",equipaje);

    imprimir = "\nNombre: ";
    imprimir += nombre;
    imprimir += "\nDestino: ";
    imprimir += destino;
    imprimir += "\nID: ";
    imprimir += myId;
    imprimir += "\nFecha: ";
    imprimir += fecha.toString();
    imprimir += "\nBoleto: ";
    imprimir += myBoleto;
    imprimir += "\nAsiento: ";
    imprimir += asiento;
    imprimir += "\nEquipaje: ";
    imprimir += myEquipaje;
    imprimir += "\nHorario: ";
    imprimir += horario.toString();

    return imprimir;
}

string Pasajero::toString2()
{
    string imprimir;
    char myEquipaje[10];
    sprintf_s(myEquipaje,"%i",equipaje);

    imprimir = imprimir + "Pasajero " + nombre + " con destino a " + destino + " lleva " + myEquipaje + " maletas\n------------------------------------------------ ";

    return imprimir;
}


//Para copiar
Pasajero& Pasajero::operator=(const Pasajero& p)
{
    nombre = p.nombre;
    destino = p.destino;
    id = p.id;
    fecha = p.fecha;
    boleto = boleto;
    asiento = p.asiento;
    equipaje = p.equipaje;

    return *this;
}
