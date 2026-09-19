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
    unsigned int eliminacion_f=0;
    unsigned int eliminaciones_f=0;
    unsigned int user_el=0;
    bool salir=false;
    char fichas[9]="0ABCDEFQ";
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
        puntuacion=cascadas*10;
        limite_p=(bytes*8*65)/100;
        cout<<"La cantidad de filas y comunas es: "<<filas<<"x"<<columnas<<endl;
        cout<<"Tu puntuacion: "<<puntuacion<<endl;
        cout<<"Ested ha hecho "<<user_el<<" eliminaciones"<<endl;
        cout<<"Se ha eliminado un total de: "<<eliminaciones_f+eliminacion_f<<" fichas"<<endl;
        for(int i=0;i<filas;++i){
            for(int j=0;j<columnas;++j){
                for(int k=2;k>=0;--k){
                    cout<<((lectura_f(i,columnas,j,ptablero)>> k)&1);
                }
            }
            cout<<endl;
        }
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
            fila--;
            cout<<"ingrese la columna de la ficha que desea eliminar: ";
            cin>>columna;
            columna--;
            del_elemento(fila,columnas,columna,ptablero);
            cascadas=lectura_t(columnas,filas,cascadas,ptablero);
            user_el++;
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
            cascadas=lectura_t(columnas,filas,cascadas,ptablero);
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
            cascadas=lectura_t(columnas,filas,cascadas,ptablero);
            break;
        case 4: cout<<"Ingresa que fila deseas eliminar: ";
            cin>>fila;
            fila--;
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
            cascadas=lectura_t(columnas,filas,cascadas,ptablero);
            user_el=user_el+columnas;
            eliminaciones_f=eliminaciones_f+columnas;
            break;
        case 5: cout<<"Ingresa que columna deseas eliminar: ";
            cin>>columna;
            columna--;
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
            cascadas=lectura_t(columnas,filas,cascadas,ptablero);
            user_el=user_el+filas;
            eliminaciones_f=eliminaciones_f+filas;
            break;
        case 6: salir=true;
            break;
        default: cout<<"Usted ingreso un valor erroneo, intente denuevo"<<endl;
            break;
        }
        eliminacion_f=del_elemento(-1,-1,-1,NULL);
    }
    //Todo el desarrollo
    delete[]ptablero;
    ptablero=NULL;
    //Final
    return 0;
}