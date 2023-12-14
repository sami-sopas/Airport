//Ramirez Cuenca Samuel Osvaldo
#include <iostream>
#include"windows.h"
#include<ctime>
#include<cstdlib>
#include"stdlib.h"
#include"conio.h"
#include"Pasajero.h"
#include"Cola.h"
#include"Fecha.h"
#include"Pila.h"
#include"Hora.h"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
#define color SetConsoleTextAttribute
using namespace std;

//Generadores
int generarId();
Fecha generarFecha();
Fecha miFecha;
int generarMes();
int generarDia();
int generarBoleto();
string generarAsiento();
int generarEquipaje();
Hora miHorario;
Hora generarHorario();
int generarHora();
int generarMinuto();

//Para animaciones
HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); //Ponerle color a las letras
int menu(const char *titulo, const char *opciones[], int n);
void avionMenu();
void stopSign();
void imprimirTicket();
void avion();
void cabina();
void mostrarRecepcion();
void mostrarRevisionEquipaje();
void mostrarSitio();
void primeraCola(int npasajeros); //Cuando se registran
void segundaCola(int npasajeros); //Cuando revisan equipaje
void terceraCola(int npasajeros); //Cuando se forman para el sitio
void taxi(int npasajeros); //Cuando toman el taxi y fuga
void gotoxy(int x,int y); //x es 80 y es 25 lo que mide la pantalla
void HideCursor();
void despedida();

//Variables que usa el menu
Pasajero pasajero;
Cola cola; //Comprar ticket
Cola cola2; //Revision
Cola cola3; //Taxi
Pila pila;
string auxiliar;
int opc=0;
int npasajeros=0;

//Funciones generales
void pedirDatos();
void imprimirTicket();
/*
Querido viajero:

Si estas leyendo esto, eres de los afortunados en tener mi codigo.

Cuando escribi este codigo, solo Dios y yo sabiamos como funcionaba.
Ahora, solo Dios lo sabe!!

Asi que si estas tratando de entender este codigo y fracasas (seguramente)
No te preocupes! Es normal, te deseo suerte en esta pequeña travesia :)
*/

int main()
{
    system("Title Aeropuerto by sami");
    const char *titulo = "-------- AEROPUERTO --------";
    const char *opciones[] = {"Registrar / primera ", "Revision / segunda cola", "Abordar avion / apilar", "Desabordar avion / desapilar y tercera cola", "Tomar taxi / desencolar", "Salir" };
    int n = 6; //Numero de opciones

    do{
        opc = menu(titulo,opciones,n);

       /* system("cls");
        cout<<endl;

        cout<<"\tAEROPUERTO"<<endl<<endl;
        cout<<"\t1)Registrar / primera cola"<<endl;
        cout<<"\t2)Revision / segunda cola"<<endl;
        cout<<"\t3)Abordar avion / apilar"<<endl;
        cout<<"\t4)Desabordar avion / desapilar y tercera cola"<<endl;
        cout<<"\t5)Tomar taxi / desencolar"<<endl<<endl;

        cout<<"\tOpcion: "; cin>>opc;*/

    switch(opc){
        case 1:
       {
        cout << endl << endl;
        gotoxy(60,5);cout<<"\tCuantos pasajeros quiere registrar"<<endl;
        gotoxy(60,6);cout<<"\t"; cin>>npasajeros;
        primeraCola(npasajeros);
        Sleep(250);
       }
       break;

    case 2:
        {
            cout << endl << endl;
          if(cola.estaVacia(cola.getFrentePos())){
             cout<<"\tAun no hay pasajeros registrados"<<endl;
             Sleep(3000);
          }else{
              system("cls");
              cout << endl << endl;
             cout<<"\tLos pasajeros pasaran a revision"<<endl;
             cout<<"\t--------------------------------"<<endl;
                while(!cola.estaVacia(cola.getFrentePos())){
                        cola2.encolar(cola.desencolar());
                       }
                        Sleep(500);
                        segundaCola(npasajeros);
            cout << endl << endl;
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
            printf("%c",186); cout<<" Datos de los pasajeros: "; printf("%c",186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
            cout << endl << endl;
            cout<<cola2.toString2();
            cout << endl << endl;
            system("pause");
            }

        }
        break;

     case 3:
        {
            cout << endl << endl;
            if(cola2.estaVacia(cola2.getFrentePos()))  {
                cout<<"\tNo hay pasajeros para abordar"<<endl;
                Sleep(3000);
            }else{
            cout << endl << endl;
            cout<<"\tLos pasajeros estan subiendo al avion"<<endl;
            cout<<"\t-------------------------------------"<<endl;
           while(!cola2.estaVacia(cola2.getFrentePos())){
            pila.push(cola2.desencolar());
           }
           avion();
           system("pause");
          }
        }
        break;

    case 4:
        {
            cout << endl << endl;
            if(pila.estaVacia()) {
                cout<<"\tLos pasajeros aun no han abordado el avion"<<endl;
                Sleep(3000);
            }else{
                system("cls");
                Sleep(300);
                cout << endl << endl;
                cout<<"\tLos pasajeros estan bajando del avion y se forman para pedir un taxi"<<endl;
                cout<<"\t--------------------------------------------------------------------"<<endl;
                terceraCola(npasajeros);
                cout << endl;
                system("pause");
            }
        }
        break;
    case 5:
        {
            cout << endl << endl;
            if(pila.estaVacia()){
                cout<<"\tLos pasajeros aun no han bajado del avion"<<endl;
                Sleep(3000);
            }else{
                cout << endl << endl;
                cout<<"\tLos pasajeros se estan formando para tomar el taxi"<<endl;
                cout<<"\t--------------------------------------------------"<<endl;
                while(!pila.estaVacia()){
                    cola3.encolar(pila.pop());
                }
                system("cls");
                Sleep(300);
                cout << endl << endl;
                cout<<"\tLos pasajeros empiezan a tomar su taxi "<<endl;
                cout<<"\t---------------------------------------"<<endl;
                taxi(npasajeros);

                system("cls");
                despedida();
                cout << endl  << endl;
                system("pause");
                color(hConsole,7);
            }
        }
        break;

        case 6:{
        break;
        }
    }

    }while(opc!=6);

    /*monito();
    monito2();*/

    return 0;
}

int menu(const char *titulo, const char *opciones[],int n){

    int opcionSeleccionada = 1; //Apunta por defecto a la opcion 1
    int tecla; //Tecla persionada por el usuario
    bool repite = true;

    do
	{
		system("cls");

	    gotoxy(5, 3 + opcionSeleccionada); cout << "==>";

	    //Imprime el título
	    gotoxy(11,2); cout <<titulo;

	    //Imprime las opciones
	    int i;

	    for((i=0);(i<n);(i++))
	    {
	    	gotoxy(10, 4 + i); cout << i+1 << ") " << opciones[i];
		}
        avionMenu();
		do
		{
			tecla = getch();
		}
		while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

		switch(tecla)
		{
			case TECLA_ARRIBA:
				opcionSeleccionada --;

				if (opcionSeleccionada < 1)
				{
					opcionSeleccionada = n;
				}

				break;

			case TECLA_ABAJO:
				opcionSeleccionada ++;

				if (opcionSeleccionada > n)
				{
					opcionSeleccionada = 1;
				}

				break;

			case ENTER:
				repite = false;
				break;
		}
    }
    while(repite);
    return opcionSeleccionada;
}

int generarId(){
    srand((unsigned)time(0));
    return rand() % 9999 + 1;
}

Fecha generarFecha(){

    miFecha.setAnio(2022);
    miFecha.setMes(generarMes());
    miFecha.setDia(generarDia());

    return miFecha;
}

Hora generarHorario(){

    miHorario.setHora(generarHora());
    miHorario.setMinuto(generarMinuto());

    return miHorario;
}
int generarMes(){
    srand((unsigned)time(0));
    return rand()% 12 + 1;//Genera random entre 1 y 12
}

int generarDia(){
    srand((unsigned)time(0));
    return rand()%30 + 1;
}

int generarHora(){
    srand((unsigned)time(0));
    return rand()%24 + 1;
}

int generarMinuto(){
    srand((unsigned)time(0));
    return rand()%49 + 10;
}

int generarBoleto(){
    srand((unsigned)time(0));
    return rand()% 999 + 1;
}

string generarAsiento(){
    srand((unsigned)time(0));

    int numero(rand() % 99 + 1);
    char letra((rand() & 7) + 65);

    return string(1,letra) + to_string(numero);
}

int generarEquipaje(){
    srand((unsigned)time(0));
    return rand()% 5+1;
}

void pedirDatos(){
    cout << endl << endl << endl;
    cin.ignore();
    cout<<"\tIngrese el nombre: "<<endl;
    cout<<"\t"; getline(cin,auxiliar);
    pasajero.setNombre(auxiliar);

    cout << endl;

    cout<<"\tIngrese el destino: "<<endl;
    cout<<"\t"; getline(cin,auxiliar);
    pasajero.setDestino(auxiliar);

    pasajero.setId(generarId());//Setear ID con random
    pasajero.setFecha(generarFecha()); //Setear fechas random
    pasajero.setBoleto(generarBoleto()); //Setear boleto random
    pasajero.setAsiento(generarAsiento()); //Setear asiento random
    pasajero.setEquipaje(generarEquipaje()); //Setear equipaje random
    pasajero.setHorario(generarHorario()); //Setear hora random
    cola.encolar(pasajero);
    system("cls");



}
///ANIMACIONES PROTOTIPO
void imprimirTicket(){

    gotoxy(47,0);cout<<"AEROLINEAS CARRILLO";
    gotoxy(46,1);cout<<"---------------------";

   gotoxy(14,3); printf("%c",201); //Esquina superior izq
   gotoxy(105,3); printf("%c",187); //Esquina superior der
   gotoxy(15,3);for(int i=0;i<90;i++){
   printf("%c",205); //Imprime la linea horizontal de arriba
   }
       gotoxy(22,4); printf("%c",201); //Esquina superior izquierda marco
       gotoxy(41,4); printf("%c",187); //Esquina superior derecha marco
       gotoxy(23,4); for(int i=0;i<18;i++){
       printf("%c",205); //Imprime la linea horizontal superior del marco de la foto
       }
        ///MARCO
       //Imprimir linear verticales izquierdas         //Imprimir lineas verticales derechas
       gotoxy(22,5); printf("%c",186);                gotoxy(41,5); printf("%c",186);
       gotoxy(22,6); printf("%c",186);                gotoxy(41,6); printf("%c",186);
       gotoxy(22,7); printf("%c",186);                gotoxy(41,7); printf("%c",186);
       gotoxy(22,8); printf("%c",186);                gotoxy(41,8); printf("%c",186);
       gotoxy(22,9); printf("%c",186);                gotoxy(41,9); printf("%c",186);
       gotoxy(22,10); printf("%c",186);               gotoxy(41,10); printf("%c",186);
       gotoxy(22,11); printf("%c",186);               gotoxy(41,11); printf("%c",186);
       gotoxy(22,12); printf("%c",186);               gotoxy(41,12); printf("%c",186);
       gotoxy(22,13); printf("%c",186);               gotoxy(41,13); printf("%c",186);
       gotoxy(22,14); printf("%c",186);               gotoxy(41,14); printf("%c",186);

       ///CUADRO PRINCIPAL
       //Linea izquuierda                             //Linea derecha
       gotoxy(14,4); printf("%c",186);                gotoxy(105,4); printf("%c",186);
       gotoxy(14,5); printf("%c",186);                gotoxy(105,5); printf("%c",186);
       gotoxy(14,6); printf("%c",186);                gotoxy(105,6); printf("%c",186);
       gotoxy(14,7); printf("%c",186);                gotoxy(105,7); printf("%c",186);
       gotoxy(14,8); printf("%c",186);                gotoxy(105,8); printf("%c",186);
       gotoxy(14,9); printf("%c",186);                gotoxy(105,9); printf("%c",186);
       gotoxy(14,10); printf("%c",186);               gotoxy(105,10); printf("%c",186);
       gotoxy(14,11); printf("%c",186);               gotoxy(105,11); printf("%c",186);
       gotoxy(14,12); printf("%c",186);               gotoxy(105,12); printf("%c",186);
       gotoxy(14,13); printf("%c",186);               gotoxy(105,13); printf("%c",186);
       gotoxy(14,14); printf("%c",186);               gotoxy(105,14); printf("%c",186);
       gotoxy(14,15); printf("%c",186);               gotoxy(105,15); printf("%c",186);
       gotoxy(14,16); printf("%c",186);               gotoxy(105,16); printf("%c",186);
       gotoxy(14,17); printf("%c",186);               gotoxy(105,17); printf("%c",186);
       gotoxy(14,18); printf("%c",186);               gotoxy(105,18); printf("%c",186);
       gotoxy(14,19); printf("%c",186);               gotoxy(105,19); printf("%c",186);


       gotoxy(22,15); for(int i=0;i<19;i++){
       printf("%c",205); //Imprime la linea horizontal inferior del marco de la foto
       }
       gotoxy(41,15); printf("%c",188); //Esquina inferior derecha
       gotoxy(22,15); printf("%c",200); //Esquina inferior izquierda

       gotoxy(20,16); cout<<"Pase a la siguiente fila";
       gotoxy(22,17); cout<<"   para revision";

       ///LINEA ANTES DELIMITANTE CODIGO DE BARRAS
       gotoxy(91,4); printf("%c",124);
       gotoxy(91,5); printf("%c",124);
       gotoxy(91,6); printf("%c",124);
       gotoxy(91,7); printf("%c",124);
       gotoxy(91,8); printf("%c",124);
       gotoxy(91,9); printf("%c",124);
       gotoxy(91,10); printf("%c",124);
       gotoxy(91,11); printf("%c",124);
       gotoxy(91,12); printf("%c",124);
       gotoxy(91,13); printf("%c",124);
       gotoxy(91,14); printf("%c",124);
       gotoxy(91,15); printf("%c",124);
       gotoxy(91,16); printf("%c",124);
       gotoxy(91,17); printf("%c",124);
       gotoxy(91,18); printf("%c",124);
       gotoxy(91,19); printf("%c",124);

       ///CODIGO DE BARRAS
       gotoxy(94,5);printf("%c%c%c%c%c%c%c",205,205,205,205,205,205,205); //==
       gotoxy(94,6);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
       gotoxy(94,7);printf("%c%c%c%c%c%c%c",238,238,238,238,238,238,238);
       gotoxy(94,8);printf("%c%c%c%c%c%c%c",223,223,223,223,223,223,223);
       gotoxy(94,9);printf("%c%c%c%c%c%c%c",205,205,205,205,205,205,205);
       gotoxy(94,10);printf("%c%c%c%c%c%c%c",196,196,196,196,196,196,196);
       gotoxy(94,11);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
       gotoxy(94,12);printf("%c%c%c%c%c%c%c",240,240,240,240,240,240,240);
       gotoxy(94,13);printf("%c%c%c%c%c%c%c",220,220,220,220,220,220,220);
       gotoxy(94,14);printf("%c%c%c%c%c%c%c",205,205,205,205,205,205,205);
       gotoxy(94,15);printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
       gotoxy(94,16);printf("%c%c%c%c%c%c%c",196,196,196,196,196,196,196);
       gotoxy(94,17);printf("%c%c%c%c%c%c%c",238,238,238,238,238,238,238);
       gotoxy(94,18);printf("%c%c%c%c%c%c%c",223,223,223,223,223,223,223);

       ///MONITO DENTRO DE LA FOTO
       gotoxy(29,5);printf("%c%c%c%c%c%c",95,95,95,95,95,95);
       gotoxy(28,6);printf("%c",47);
       gotoxy(27,7);printf("%c",47);
       gotoxy(27,8);printf("%c",92);
       gotoxy(28,9);printf("%c",92);
       gotoxy(29,9);printf("%c%c%c%c%c%c",95,95,95,95,95,95);
       gotoxy(35,6);printf("%c",92);
       gotoxy(36,7);printf("%c",92);
       gotoxy(36,8);printf("%c",47);
       gotoxy(35,9);printf("%c",47);
       gotoxy(31,10);cout<<"|";
       gotoxy(31,11);cout<<"|";
       gotoxy(31,12);cout<<"|";
       gotoxy(31,13);cout<<"|";
       gotoxy(31,14);cout<<"|";
       gotoxy(30,11);cout<<"/";
       gotoxy(29,12);cout<<"/";
       gotoxy(28,13);cout<<"/";
       gotoxy(32,11);printf("%c",92);
       gotoxy(33,12);printf("%c",92);
       gotoxy(34,13);printf("%c",92);


          gotoxy(50,5);printf("Nombre: ");
   gotoxy(50,6);for(int i=0;i<30;i++){
   printf("-"); //Imprime la linea abajo de nombre
   }
   gotoxy(58,5);cout<<pasajero.getNombre();

           gotoxy(50,8);printf("Destino: ");
   gotoxy(50,9);for(int i=0;i<30;i++){
   printf("-"); //Imprime la linea abajo de nombre
   }
   gotoxy(59,8); cout<<pasajero.getDestino();

            gotoxy(50,11);printf("Fecha y hora: ");
   gotoxy(50,12);for(int i=0;i<30;i++){
   printf("-"); //Imprime la linea abajo de nombre
   }
   gotoxy(64,11); cout<<miFecha.toString() + ", ";
   gotoxy(75,11);cout<<miHorario.toString();

            gotoxy(50,14);printf("No.Boleto: ");
   gotoxy(50,15);for(int i=0;i<30;i++){
   printf("-"); //Imprime la linea abajo de nombre
   }
   gotoxy(61,14); cout<<pasajero.getBoleto();

            gotoxy(50,17);printf("Asiento: ");
   gotoxy(50,18);for(int i=0;i<30;i++){
   printf("-"); //Imprime la linea abajo de nombre
   }
   gotoxy(59,17); cout<<pasajero.getAsiento();


   gotoxy(15,20);for(int i=0;i<90;i++){
   printf("%c",205); //Imprime la linea horizontal de abajo
   }
   gotoxy(14,20); printf("%c",200); //Esquina inferior izq
   gotoxy(105,20); printf("%c",188); //Esquina inferior der

   gotoxy(20,21);
   system("pause");
   system("cls");


   /*cout<<"Destino: "<<pasajero.getDestino()<<endl;
   cout<<"ID: "<<pasajero.getBoleto()<<endl;
   cout<<"Fecha: "<<miFecha.toString()<<endl;
   cout<<"Boleto: "<<pasajero.getBoleto()<<endl;
    cout<<"Al pasajero "<<pasajero.getNombre()<<" se le asigno el asiento "<<pasajero.getAsiento()<<endl;
   cout<<"Pase a la siguiente fila para revisar su equipaje"<<endl;*/

}

void avion(){

    /*             ▄█
    ▄▄▄▄▄▄▄▄▄▄▄▄▄▄███▄
  ▄█▄██▄█▄█▄█▄█▄██▀▀
        ▀▀████▄
            ▀▀██▄

            */
    for(int i=0;i<17;i++){ ///SUBIDA
    gotoxy(2+(2*i),17-i);printf(" %c%c",219,220);
    gotoxy(2+(2*i),18-i);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(2+(2*i),19-i);printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,219,219,220,219,220,219,220,219,220,219,220,219,219,220,219,220);
    gotoxy(2+(2*i),20-i);printf("       %c%c%c%c%c%c%c",220,219,219,219,219,223,223);
    gotoxy(2+(2*i),21-i);printf("     %c%c%c%c%c",220,219,219,223,223);
    Sleep(90);
        system("cls");

    }

    for(int i=0;i<70;i++){ ///MEDIO

            system("cls");
        gotoxy(5+i,8);printf(" %c%c",219,220);
        gotoxy(5+i,9);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
        gotoxy(5+i,10);printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,219,219,220,219,220,219,220,219,220,219,220,219,219,220,219,220);
        gotoxy(5+i,11);printf("       %c%c%c%c%c%c%c",220,219,219,219,219,223,223);
        gotoxy(5+i,12);printf("     %c%c%c%c%c",220,219,219,223,223);

       //Nubes
       color(hConsole,3);
       gotoxy(80,23);cout<<"         ( `   )_";
       gotoxy(80,24);cout<<"      (    )    `)";
       gotoxy(80,25);cout<<"    (_   (_ .  _) _)";

       gotoxy(40,15);cout<<"        (  )";
       gotoxy(40,16);cout<<"     ( `  ) . )";
       gotoxy(40,17);cout<<"   (_, _(  ,_)_)";

       gotoxy(20,19);cout<<"  (  _ )_)";
       gotoxy(20,20);cout<<"(_  _(_ ,)";
       color(hConsole,7);//Para que lo demas salga bien

       }

    for(int i=20;i>0;i--){ ///BAJADA
                    system("cls");
    gotoxy(20-i,26-i);printf(" %c%c",219,220);
    gotoxy(20-i,27-i);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(20-i,28-i);printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,219,219,220,219,220,219,220,219,220,219,220,219,219,220,219,220);
    gotoxy(20-i,29-i);printf("       %c%c%c%c%c%c%c",220,219,219,219,219,223,223);
    gotoxy(20-i,30-i);printf("     %c%c%c%c%c",220,219,219,223,223);
    Sleep(100);


    }

    for(int i=0;i<60;i++){ ///ATERRIZAJE
    system("cls");
    cabina();
    gotoxy(20+i,26);printf(" %c%c",219,220);
    gotoxy(20+i,27);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
    gotoxy(20+i,28);printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,223,219,219,220,219,220,219,220,219,220,219,220,219,219,220,219,220);
    gotoxy(20+i,29);printf("       %c%c%c%c%c%c%c",220,219,219,219,219,223,223);
    gotoxy(20+i,30);printf("     %c%c%c%c%c",220,219,219,223,223);
    Sleep(100);
    }
    gotoxy(50,15);printf("Aterrizaje exitoso!!");
    gotoxy(50,16);printf("--------------------");
    cout << endl << endl;

}

void cabina(){
    gotoxy(100,25);cout<<"__|__";
    gotoxy(100,26);cout<<"\\___/";
    gotoxy(100,27);cout<<" | |";
    gotoxy(100,28);cout<<" | |";
    gotoxy(100,29);cout<<" | |";
    gotoxy(100,30);cout<<"_|_|______________";

}
void taxi(int cont){
     int ban=0;
     int i,j;
    int h=80,restar=0;

    gotoxy(1,21); for(int i=0;i<119;i++){
    color(hConsole,8); //Color del piso
    printf("%c",219);
    }
    stopSign();
    color(hConsole,7);
    for(j=0;j<cont;j++){

	for(i=0;i<80-(j*4);i++){
        gotoxy(i,17);cout<<"  "<<j+1<<" ";
        gotoxy(i,18);cout<< "  o";
		gotoxy(i,19); cout<< " /|\\";
		if(ban==0){
				gotoxy(i,20); cout<< "\ ";          //LLEGAN MONITOS
			ban=1;
		}else{
			gotoxy(i,20); cout<< " / \\";
			ban=0;
		}

		 Sleep(50);
	}
	Sleep(500);
    }
    for(j=0;j<cont;j++){

    for(int a=10;a<80;a++)
    {
        Sleep(100);

gotoxy(a-restar,22);cout<<"              __[]__           ";
gotoxy(a-restar,23);cout<<"           ,-`---.--`;.         ";
gotoxy(a-restar,24);cout<<"      .---' '---'.-.-- '----.  ";
gotoxy(a-restar,25);cout<<"     /   .-.   {TAXI}    .-. \\  ";
gotoxy(a-restar,26);cout<<"     '--(( ))-----------(( ))' ";
gotoxy(a-restar,27);cout<<"         `"               "`   ";
   }

    Sleep(600);

    gotoxy(h,17);cout<<"     ";
        gotoxy(h,18);cout<< "     ";
		gotoxy(h,19); cout<< "       ";
		if(ban==0){
				gotoxy(h,20); cout<< "     ";           //BORRAR MONITO
			ban=1;
		}else{
			gotoxy(h-1,20); cout<< "       ";
			ban=0;
		}
		h=h-4;
			Sleep(600);


    for(int a=80;a<100;a++)
    {
        Sleep(100);
      gotoxy(a-restar,22);cout<<"              __[]__             ";
      gotoxy(a-restar,23);cout<<"           ,-`---.--`;.         ";
      gotoxy(a-restar,24);cout<<"      .---' '---'.-.-- '----.  ";
      gotoxy(a-restar,25);cout<<"     /   .-.   {TAXI}    .-. \\  ";
      gotoxy(a-restar,26);cout<<"     '--(( ))-----------(( ))' ";
      gotoxy(a-restar,27);cout<<"         `"               "`   ";

    }

      gotoxy(100-restar,22);cout<<"                                     ";
      gotoxy(100-restar,23);cout<<"                                      ";
      gotoxy(100-restar,24);cout<<"                                     ";
      gotoxy(100-restar,25);cout<<"                                    ";   ///Borrar carro
      gotoxy(100-restar,26);cout<<"                                    ";
      gotoxy(100-restar,27);cout<<"                                     ";
        restar=restar+5;
    }
}

void mostrarRecepcion(){

    //Recepcion
    color(hConsole,14);
    gotoxy(90,11);printf("%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187);
    gotoxy(90,12);printf("%c",186); gotoxy(99,12);printf("%c",186); gotoxy(91,12);printf("%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176);
    gotoxy(90,13);printf("%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188);
    //Monito atras
    color(hConsole,7);
    gotoxy(91,6);cout<<"Venta de boletos";
    gotoxy(102,9);printf("%c",220);   gotoxy(101,9);printf("%c",95); //Gorra disque
    gotoxy(100,10);cout<< "  o";
    gotoxy(100,11); cout<< " /|\\";
    gotoxy(100,12); cout<< " / \\";
    //Cartel venta
    color(hConsole,3);
    gotoxy(90,5);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(90,6);printf("%c",186);  gotoxy(107,6);printf("%c",186);
    gotoxy(90,7);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}

void mostrarRevisionEquipaje(){

    //Recepcion
    color(hConsole,14);
    gotoxy(90,11);printf("%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187);
    gotoxy(90,12);printf("%c",186); gotoxy(99,12);printf("%c",186); gotoxy(91,12);printf("%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176);
    gotoxy(90,13);printf("%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188);
    //Monito atras
     color(hConsole,7);
     gotoxy(91,6);cout<<"    Equipaje";
    gotoxy(102,9);printf("%c",220);   gotoxy(101,9);printf("%c",95); //Gorra disque
    gotoxy(100,10);cout<< "  o";
    gotoxy(100,11); cout<< " /|\\";
    gotoxy(100,12); cout<< " / \\";
    //Cartel venta
     color(hConsole,12);
    gotoxy(90,5);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(90,6);printf("%c",186);  gotoxy(107,6);printf("%c",186);
    gotoxy(90,7);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    //Cinta maletas
     color(hConsole,8);
    gotoxy(106,10);printf("%c%c%c",201,205,187);
    gotoxy(106,11);printf("%c %c",186,186);
    gotoxy(106,12);printf("%c%c%c",200,205,188);
    gotoxy(109,12);cout<<"__________";
    gotoxy(104,13);cout<<" < o----o----o > ";

}

void mostrarSitio(){
    //Recepcion
    color(hConsole,8);
    gotoxy(90,11);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(90,12);printf("%c",186); gotoxy(91,12);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176); gotoxy(107,12);printf("%c",186);
    gotoxy(90,13);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    //Cartel venta
    color(hConsole,6);
    gotoxy(90,5);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(90,6);printf("%c",186);  gotoxy(107,6);printf("%c",186);
    gotoxy(90,7);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    //Monito
    color(hConsole,7);
    gotoxy(91,6);cout<<"    Sitio 84";
    gotoxy(96,9);cout<< "  o";
    gotoxy(96,10); cout<< " /|\\";

    //Taxi detras
gotoxy(110,8);cout<<"      __[]_";
gotoxy(110,9);cout<<"   ,-`---.-  ";
gotoxy(110,10);cout<<" .---' '---.";
gotoxy(110,11);cout<<"/   .-.   { ";
gotoxy(110,12);cout<<"'--(( ))-- ";



}
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}

void primeraCola(int pasajeros){
    system("cls");
     int ban=0;
     int i,j;
    for(j=0;j<pasajeros;j++){
    mostrarRecepcion(); //Display de la recepcion
    color(hConsole,7);
    gotoxy(1,2);cout <<"\t Pasajeros yendo a comprar su boleto"<<endl;
    gotoxy(1,3);cout <<"\t------------------------------------"<<endl;
    gotoxy(1,13); for(int i=0;i<89;i++){
        color(hConsole,15); //Color del piso
        printf("%c",219);
    }
    color(hConsole,7);
	for(i=0;i<80-(j*4);i++){

        gotoxy(i,9);cout<<"  "<<j+1<<" ";
        gotoxy(i,10);cout<< "  o";
		gotoxy(i,11); cout<< " /|\\";
		if(ban==0){
				gotoxy(i,12); cout<< "\ ";
			ban=1;
		}else{
			gotoxy(i,12); cout<< " / \\";
			ban=0;
		}

		 Sleep(50);
	}
	pedirDatos();
	     Sleep(100);
	    system("cls");
        gotoxy(45,10);printf("Imprimiendo pase de aboradar...");
        Sleep(1200);
      system("cls");
      imprimirTicket();
	Sleep(1000);
    }
}

void segundaCola(int pasajeros){
     int ban=0;
     int i,j;

    for(j=0;j<pasajeros;j++){
        mostrarRevisionEquipaje();
        gotoxy(1,13); for(int i=0;i<89;i++){
        color(hConsole,15); //Color del piso
        printf("%c",219);
    }
        color(hConsole,7);
	for(i=0;i<80-(j*4);i++){
        gotoxy(i,9);cout<<"  "<<j+1<<" ";
        gotoxy(i,10);cout<< "  o";
		gotoxy(i,11); cout<< " /|\\";
		if(ban==0){
				gotoxy(i,12); cout<< "\ ";
			ban=1;
		}else{
			gotoxy(i,12); cout<< " / \\";
			ban=0;
		}

		 Sleep(50);
	}
	Sleep(1000);
    }
    int h=80,g=2;
    for(int j=pasajeros;j>0;j--){
        gotoxy(h,9);cout<<"     ";
        gotoxy(h,10);cout<< "     ";
		gotoxy(h,11); cout<< "       ";
		if(ban==0){
				gotoxy(h,12); cout<< "     ";
			ban=1;
		}else{
			gotoxy(h-1,12); cout<< "       ";
			ban=0;
		}
		h=h-4;
			Sleep(g*1000);
	}


	        cout<<endl;
    }

void terceraCola(int pasajeros){
     int ban=0;
     int i,j;

    for(j=0;j<pasajeros;j++){
        mostrarSitio();
        gotoxy(1,13); for(int i=0;i<89;i++){
        color(hConsole,15); //Color del piso
        printf("%c",219);
       }
	for(i=0;i<80-(j*4);i++){
            color(hConsole,7);
        gotoxy(i,9);cout<<"  "<<j+1<<" ";
        gotoxy(i,10);cout<< "  o";
		gotoxy(i,11); cout<< " /|\\";
		if(ban==0){
				gotoxy(i,12); cout<< "\ ";
			ban=1;
		}else{
			gotoxy(i,12); cout<< " / \\";
			ban=0;
		}

		 Sleep(50);
	}
	Sleep(1000);
    }
    int h=80,g=2;
    for(int j=pasajeros;j>0;j--){
        gotoxy(h,9);cout<<"     ";
        gotoxy(h,10);cout<< "     ";
		gotoxy(h,11); cout<< "       ";
		if(ban==0){
				gotoxy(h,12); cout<< "     ";
			ban=1;
		}else{
			gotoxy(h-1,12); cout<< "       ";
			ban=0;
		}
		h=h-4;
			Sleep(g*1000);
	}


	        cout<<endl;
    }

void avionMenu(){
gotoxy(10,12);cout<<"  \\----------------------------------\\ ";
gotoxy(10,13);cout<<"   \\          Seminario de            \\        __";
gotoxy(10,14);cout<<"    \\     Estructura de datos |        \\       | \\ ";
gotoxy(10,15);cout<<"     >                                  >------|  \\       ______ ";
gotoxy(10,16);cout<<"    /     Proyecto Pilas y Colas       /       --- \\_____/**|_|_\\____  |";
gotoxy(10,17);cout<<"   /                                  /          \\_______ --------- __>-}";
gotoxy(10,18);cout<<"  /----------------------------------/              /  \\_____|_____/   |";
gotoxy(10,19);cout<<"                                                    *         |";
gotoxy(10,20);cout<<"                                                             {O}";
gotoxy(10,21);cout<<" ";
gotoxy(10,22);cout<<"       /*\\       /*\\       /*\\       /*\\       /*\\       /*\\       /*\\ ";
gotoxy(10,23);cout<<"      |***|     |***|     |***|     |***|     |***|     |***|     |***| ";
gotoxy(10,24);cout<<"       \\*/       \\*/ ____  \\*/       \\*/       \\*/       \\*/       \\*/ ";
gotoxy(10,25);cout<<"        |         |  |  |   |         |         |         |         | ";
gotoxy(10,26);cout<<"  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
}

void stopSign(){
color(hConsole,4);
gotoxy(86,15);cout<<"STOP";
color(hConsole,7);
gotoxy(84,13);cout<<"  ____ ";
gotoxy(84,14);cout<<" /    \\ ";
gotoxy(84,15);cout<<"|";
gotoxy(91,15);cout<<"| ";
gotoxy(84,16);cout<<" \\ __ / ";
gotoxy(84,17);cout<<"   || ";
gotoxy(84,18);cout<<"   || ";
gotoxy(84,19);cout<<"   || ";
gotoxy(84,20);cout<<"   || ";

}
void despedida(){
    //Osito
    color(hConsole,6);
    gotoxy(50,8);printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,223,223,223,220,220,220,220,220,220,220,223,223,223,220);
    gotoxy(50,9);printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,176,176,177,177,177,177,177,177,177,177,177,176,176,219);
    gotoxy(50,10);printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c",219,177,177,219,177,177,177,177,177,219,177,177,219);
    gotoxy(50,11);printf(" %c%c  %c%c%c%c%c%c%c%c%c%c%c  %c%c",220,220,219,177,177,177,223,219,223,177,177,177,219,220,220);
    gotoxy(50,12);printf("%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c",219,177,177,219,223,220,177,177,177,177,177,177,177,220,223,219,177,177,219);
    //Cartelito
    color(hConsole,7);
    gotoxy(55,14);cout<<"Gracias por";
    gotoxy(56,15);cout<<"visitarnos";
    color(hConsole,14);
    gotoxy(50,13);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,219);
    gotoxy(50,14);printf("%c",219); gotoxy(70,14);printf("%c",219);
    gotoxy(50,15);printf("%c",219); gotoxy(70,15);printf("%c",219);
    gotoxy(50,16);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,219);
    /*
───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───
───█▒▒░░░░░░░░░▒▒█───
────█░░█░░░░░█░░█────
─▄▄──█░░░▀█▀░░░█──▄▄─
█░░█─▀▄░░░░░░░▄▀─█░░█
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█    Gracias por     █
█viajar con nosotros █
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
*/
}

