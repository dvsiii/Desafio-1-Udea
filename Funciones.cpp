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
int lectura(int fila, int columnas, int filas, int columna, unsigned char *puntero)
{
    int bit_relleno=(fila*columnas+columna)*3;
    int bit_inicio=bit_relleno/8;
    int desplazo=bit_relleno%8;
    int f_leida=puntero[bit_inicio]>>5;
    f_leida=f_leida&7;
    return 0;
}
int mover(unsigned char *puntero)
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