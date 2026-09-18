#include <iostream>
using namespace std;
#include "Llamado.h"
int main()
{
    cout << "Bienvenido a Sweet Crush" << endl;
    //Introduccion
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
    while(salir==false){
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
        case 2: cout<<"Ingrese la cantidad de filas que desea agregar: ";
            cin>>fila;
            cout<<"Ingrese despues de que fila desea agregar las filas nuevas: ";
            cin>>columna;
            filas=filas+fila;
            bits=columnas*3*filas;
            bytes=(bits+7)/8;
            pcopia= new unsigned char[bytes];
            ag_fila(filas,columnas,fila,columna,ptablero,pcopia);
            delete[]ptablero;
            ptablero=NULL;
        }
    }
    return 0;
}