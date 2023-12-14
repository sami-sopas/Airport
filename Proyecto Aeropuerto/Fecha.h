#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include<string>
using namespace std;

class Fecha{
    private:
        int anio;
        int mes;
        int dia;
    public:
        Fecha();

        void setAnio(const int&);
        void setMes(const int&);
        void setDia(const int&);

        int getAnio();
        int getMes();
        int getDia();

        string toString();
};


#endif // FECHA_H_INCLUDED
