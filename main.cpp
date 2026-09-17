#include <iostream>
using namespace std;
#include "Llamado.h"
int main()
{
    cout << "Bienvenido a Sweet Crush" << endl;
    //Introduccion
    short unsigned int filas=4;
    short unsigned int columna=6;
    unsigned int puntuacion=0;
    unsigned int cascadas=0;
    bool salir=false;
    char fichas[8]="ABCDEFQ";
    unsigned char *ptablero=NULL;
    unsigned char *pcopia=NULL;
    int bits=columna*3*filas;
    int bytes=(bits+7)/8;
    //Variables
    ptablero= new unsigned char[bytes];
    for(int i=0;i<filas;++i){
        for(int j=0;j<columna;++j){
            relleno(i,columna,j,ptablero);
            //Aqui va la funcion relleno
        }
    }
    while(salir==false){
        cout<<filas<<"x"<<columna;
        cout<<puntuacion;
    }
    return 0;
}