#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include<string>

using namespace std;

class Hora{
    private:
        int hora;
        int minuto;
    public:
        Hora();

        void setHora(const int&);
        void setMinuto(const int&);

        int getHora();
        int getMinuto();

        string toString();

};



#endif // HORA_H_INCLUDED
