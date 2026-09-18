#include <iostream>
using namespace std;
#include "Llamado.h"
int main()
{
    cout << "Bienvenido a Sweet Crush" << endl;
    //Introduccion
    short unsigned int limite_p=0;
    short unsigned int desicion=0;
    short unsigned int filas=4;
    short unsigned int columnas=6;
    short unsigned int fila=0;
    short unsigned int columna=0;
    unsigned int puntuacion=0;
    unsigned int cascadas=0;
    bool salir=false;
    char fichas[8]="ABCDEFQ";
    unsigned char *ptablero=NULL;
    unsigned char *pcopia=NULL;
    int bits=columnas*3*filas;
    int bytes=(bits+7)/8;
    //Variables
    ptablero= new unsigned char[bytes];
    for(int i=0;i<filas;++i){
        for(int j=0;j<columnas;++j){
            relleno(i,columnas,j,ptablero);
        }
    }
    //Inicio del tablero
    while(salir==false){
        limite_p=(bytes*8*65)/100;
        cout<<filas<<"x"<<columnas;
        cout<<puntuacion;
        for(int i=0;i<filas;++i){
            for(int j=0;j<columnas;++j){
                cout<<fichas[lectura_f(i,columnas,j,ptablero)];
            }
            cout<<endl;
        }
        cout<<"Que desea hacer?"<<endl;
        cout<<"1. Eliminar Ficha"<<endl;
        cout<<"2. agregar una fila"<<endl;
        cout<<"3. agregar una columna"<<endl;
        cout<<"4. eliminar una fila"<<endl;
        cout<<"5. eliminar una columna"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Ingrese el numero de la accio que desea hacer: ";
        cin>>desicion;
        switch(desicion){
        case 1: cout<<"Ingrese la fila de la ficha que desea eliminar: ";
            cin>>fila;
            cout<<"ingrese la columna de la ficha que desea eliminar: ";
            cin>>columna;
                del_elemento(fila,columnas,columna,ptablero);
                relleno(fila,columnas,columna,ptablero);
                break;
        case 2: cout<<"Ingrese despues de que fila desea agregar las filas nuevas: ";
            cin>>fila;
            filas++;
            bits=columnas*3*filas;
            bytes=(bits+7)/8;
            pcopia= new unsigned char[bytes];
            ag_fila(filas,columnas,1,fila,ptablero,pcopia);
            delete[]ptablero;
            ptablero=pcopia;
            pcopia=NULL;
            break;
        case 3: cout<<"Ingresa despues de que columna desea agregar las columnas nuevas: ";
            cin>>columna;
            columnas++;
            bits=columnas*3*filas;
            bytes=(bits+7)/8;
            pcopia=new unsigned char[bytes];
            ag_columna(filas,columnas,columna,ptablero,pcopia);
            delete[]ptablero;
            ptablero=pcopia;
            pcopia=NULL;
            break;
        case 4: cout<<"Ingresa que fila deseas eliminar: ";
            cin>>fila;
            filas=filas-1;
            bits=columnas*3*filas;
            bytes=(bits+7)/8;
            if(bits<limite_p){
                pcopia=new unsigned char[bytes];
                del_fila(filas,columnas,fila,ptablero,pcopia,true);
                delete[]ptablero;
                ptablero=pcopia;
                pcopia=NULL;
            }
            else{
                del_fila(filas,columnas,fila,ptablero,pcopia,false);
            }
            break;
        case 5: cout<<"Ingresa que columna deseas eliminar: ";
            cin>>columna;
            columnas=columnas-1;
            bits=columnas*3*filas;
            bytes=(bits+7)/8;
            if(bits<limite_p){
                pcopia=new unsigned char[bytes];
                del_columna(filas,columnas,columna,ptablero,pcopia,true);
                delete[]ptablero;
                ptablero=pcopia;
                pcopia=NULL;
            }
            else{
                del_columna(filas,columnas,columna,ptablero,pcopia,false);
            }
            break;
        case 6: salir=true;
            break;
        }
    }
    delete[]ptablero;
    ptablero=NULL;
    return 0;
}