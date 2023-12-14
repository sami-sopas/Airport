#include"Hora.h"

Hora::Hora(){}

void Hora::setHora(const int& h)
{
    hora = h;
}

void Hora::setMinuto(const int& m)
{
    minuto = m;
}

int Hora::getHora()
{
    return hora;
}

int Hora::getMinuto()
{
    return minuto;
}

string Hora::toString()
{
    string impresion;

    impresion = to_string(hora);
    impresion += ":";
    impresion += to_string(minuto);

    return impresion;
}
