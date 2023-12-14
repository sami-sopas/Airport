#include"Fecha.h"
#include"Pasajero.h"
#include<string>

Fecha::Fecha(){}

void Fecha::setAnio(const int& a)
{
    anio = a;
}

void Fecha::setMes(const int& m)
{
    mes = m;
}

void Fecha::setDia(const int& d)
{
    dia = d;
}

int Fecha::getAnio()
{
    return anio;
}

int Fecha::getMes()
{
    return mes;
}

int Fecha::getDia()
{
    return dia;
}

string Fecha::toString()
{
    string impresion;

    impresion = to_string(dia);
    impresion += "/";
    impresion += to_string(mes);
    impresion += "/";
    impresion += to_string(anio);

    return impresion;

}

