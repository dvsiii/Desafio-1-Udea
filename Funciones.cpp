#include "Llamado.h"
int relleno(int fila, int columnas, int columna, unsigned char *puntero)
{
    int k=0;
    for(int i=0; i<columna+1;++i){
        k++;
    }
    int bit_relleno=(fila*columnas+columna)*3;
    int desplazo=bit_relleno%8;
    int bit_inicio=bit_relleno/8;
    int valor=(fila+columna*k)%7;
    valor=valor<<desplazo;
    puntero[bit_inicio]=puntero[bit_inicio]|valor;
    if(valor>>8!=0){
        valor=valor>>8;
        puntero[bit_inicio+1]=puntero[bit_inicio+1]|valor;
    }
    return 0;
}
int lectura_f(int fila, int columnas, int columna, unsigned char *puntero)
{
    int bit_relleno=(fila*columnas+columna)*3;
    int bit_inicio=bit_relleno/8;
    int desplazo=bit_relleno%8;
    int f_leida=0;
    int desborde=puntero[bit_inicio+1]<<8;
    desborde=desborde|puntero[bit_inicio];
    f_leida=desborde>>desplazo;
    f_leida=f_leida&7;
    return f_leida;
}
int lectura_t(int columnas, int filas, unsigned char *puntero)
{
    int f_leida=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            f_leida=lectura_f(i,columnas,j,puntero);
            if(f_leida==0){
                mover(i,j,puntero);
            }
            if(f_leida==lectura_f(i+1,columnas,j,puntero)&&f_leida==lectura_f(i+2,columnas,j,puntero)&&f_leida!=0){
                //vacio por ahora hasta que se haga del_elemento()
            }
            if(f_leida==lectura_f(i,columnas,j+1,puntero)&&f_leida==lectura_f(i,columnas,j+2,puntero)&&f_leida!=0){
                //Vacio por ahora
            }
        }
    }
    return 0;
}
int mover(int fila, int columna, unsigned char *puntero)
{
    return 0;
}
int ag_fila()
{
    return 0;
}
int ag_columna()
{
    return 0;
}
int del_fila()
{
    return 0;
}
int del_columna()
{
    return 0;
}
int del_elemento()
{
    return 0;
}