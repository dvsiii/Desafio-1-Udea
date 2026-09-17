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
        int combinacion_h=0;
        int combinacion_v=0;
        for(int j=0;j<columnas;j++){
            f_leida=lectura_f(i,columnas,j,puntero);
            if(f_leida==0){
                if(i!=0){
                    mover(i,columnas,j,puntero);
                    continue;
                }
                else {
                    relleno(i,columnas,j,puntero);
                }
            }
            for(int t=i;t<filas;t++){
                int f_fila=lectura_f(t,columnas,j,puntero);
                if(f_fila==f_leida&&f_leida!=0){
                    combinacion_v++;
                }
                else{
                    break;
                }
            }
            for(int l=j;l<columnas;l++){
                int f_columna=lectura_f(i,columnas,l,puntero);
                if(f_columna==f_leida&&f_leida!=0){
                    combinacion_h++;
                }
                else{
                    break;
                }
            }
            if(combinacion_v>=3){
                for(int k=i;k<i+combinacion_v;k++){
                    del_elemento(k,columnas,j,puntero);
                }
            }
            combinacion_v=0;
            if(combinacion_h>=3){
                for(int u=j;u<j+combinacion_h;u++){
                    del_elemento(i,columnas,u,puntero);
                }
            }
            combinacion_h=0;
        }
    }
    return 0;
}
int mover(int fila, int columnas, int columna, unsigned char *puntero)
{
    for(int i=fila;i>=0;i--){
        if(i!=0){
            int f_leida=lectura_f(i-1,columnas,columna,puntero);
            int bit_relleno=(i*columnas+columna)*3;
            int bit_inicio=bit_relleno/8;
            int desplazo=bit_relleno%8;
            int desborde=puntero[bit_inicio+1]<<8;
            desborde=desborde|puntero[bit_inicio];
            desborde=desborde&~(7<<desplazo);
            desborde=desborde|f_leida<<desplazo;
            puntero[bit_inicio]=desborde;
            puntero[bit_inicio+1]=desborde>>8;
        }
        else{
            del_elemento(i,columnas,columna,puntero);
            relleno(i,columnas,columna,puntero);
        }
    }
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
int del_elemento(int fila, int columnas, int columna, unsigned char *puntero)
{
    int bit_relleno=(fila*columnas+columna)*3;
    int bit_inicio=bit_relleno/8;
    int desplazo=bit_relleno%8;
    int desborde=puntero[bit_inicio+1]<<8;
    desborde=desborde|puntero[bit_inicio];
    desborde=desborde&~(7<<desplazo);
    puntero[bit_inicio]=desborde;
    puntero[bit_inicio+1]=desborde>>8;
    return 0;
}