#include "Llamado.h"
int relleno(int fila, int columnas, int columna, unsigned char *puntero)
{
    int k=0;
    for(int i=0; i<columna+1;++i){
        k++;
    }
    int valor=(fila+columna*k)%7;
    escribir_f(fila,columnas,columna,valor,puntero);
    return 0;
}
int lectura_f(unsigned int fila,unsigned int columnas,unsigned int columna, unsigned char *puntero)
{
    unsigned int bit_relleno=(fila*columnas+columna)*3;
    unsigned int bit_inicio=bit_relleno/8;
    unsigned int desplazo=bit_relleno%8;
    unsigned int f_leida=0;
    if(desplazo<0){
        desplazo=desplazo*-1;
    }
    if(desplazo>=6){
        int desborde=puntero[bit_inicio+1]<<8;
        desborde=desborde|puntero[bit_inicio];
        f_leida=desborde>>desplazo;
        f_leida=f_leida&7;
    }
    else {
        f_leida=puntero[bit_inicio]>>desplazo;
        f_leida=f_leida&7;
    }
    return f_leida;
}
int escribir_f(unsigned int fila,unsigned int columnas,unsigned int columna, unsigned int ficha, unsigned char *puntero)
{
    unsigned int bit_relleno=(fila*columnas+columna)*3;
    unsigned int bit_inicio=bit_relleno/8;
    int desplazo=bit_relleno%8;
    if(desplazo>=6){
        int desborde=puntero[bit_inicio+1]<<8;
        desborde=desborde|puntero[bit_inicio];
        desborde=desborde&~(7<<desplazo);
        desborde=desborde|(ficha<<desplazo);
        puntero[bit_inicio]=desborde;
        puntero[bit_inicio+1]=desborde>>8;
    }
    else {
        puntero[bit_inicio]=puntero[bit_inicio]&~(7<<desplazo);
        puntero[bit_inicio]=puntero[bit_inicio]|(ficha<<desplazo);
    }
    return 0;
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
            escribir_f(i,columnas,columna,f_leida,puntero);
        }
        else{
            del_elemento(i,columnas,columna,puntero);
            relleno(i,columnas,columna,puntero);
        }
    }
    return 0;
}
int ag_fila(int filas, int columnas, int filas_agregadas, int apartir_de_fila, unsigned char *puntero, unsigned char *copia)
{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(i<apartir_de_fila){
                int f_leida=lectura_f(i,columnas,j,puntero);
                escribir_f(i,columnas,j,f_leida,copia);
            }
            else{
                if(i<apartir_de_fila+filas_agregadas){
                    relleno(i,columnas,j,copia);
                }
                else{
                    int f_leida=lectura_f(i-filas_agregadas,columnas,j,puntero);
                    escribir_f(i,columnas,j,f_leida,copia);
                }
            }
        }
    }
    return 0;
}
int ag_columna(int filas, int columnas, int apartir_de_columna, unsigned char *puntero, unsigned char *copia)
{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(j<apartir_de_columna){
                int f_leida=lectura_f(i,(columnas-1),j,puntero);
                escribir_f(i,columnas,j,f_leida,copia);
            }
            else{
                if(j<apartir_de_columna+1){
                    relleno(i,columnas,j,copia);
                }
                else{
                    int f_leida=lectura_f(i,columnas,j-1,puntero);
                    escribir_f(i,columnas,j,f_leida,copia);
                }
            }
        }
    }
    return 0;
}
int del_fila(int filas, int columnas, int fila_eliminda, unsigned char *puntero, unsigned char *copia, bool limite)
{
    if(limite==true){
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(i<fila_eliminda){
                    int f_leida=lectura_f(i,columnas,j,puntero);
                    escribir_f(i,columnas,j,f_leida,copia);
                }
                else{
                    int fila_del=i+1;
                    int f_leida=lectura_f(fila_del,columnas,j,puntero);
                    escribir_f(i,columnas,j,f_leida,copia);
                }
            }
        }
    }
    else{
        for(int i=fila_eliminda;i<filas;i++){
            for(int j=0;j<columnas;j++){
                int f_leida=lectura_f(i+1,columnas,j,puntero);
                escribir_f(i,columnas,j,f_leida,puntero);
            }
        }
    }
    return 0;
}
int del_columna(int filas, int columnas, int columna_eliminda, unsigned char *puntero, unsigned char *copia, bool limite)
{
    if(limite==true){
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(j<columna_eliminda){
                    int f_leida=lectura_f(i,(columnas+1),j,puntero);
                    escribir_f(i,columnas,j,f_leida,copia);
                }
                else{
                    int columna_del=j+1;
                    int f_leida=lectura_f(i,(columnas+1),columna_del,puntero);
                    escribir_f(i,columnas,j,f_leida,copia);
                }
            }
        }
    }
    else{
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(j<columna_eliminda){
                    int f_leida=lectura_f(i,(columnas+1),j,puntero);
                    escribir_f(i,columnas,j,f_leida,puntero);
                }
                else{
                    int columna_del=j+1;
                    int f_leida=lectura_f(i,(columnas+1),columna_del,puntero);
                    escribir_f(i,columnas,j,f_leida,puntero);
                }
            }
        }
    }
    return 0;
}
int del_elemento(int fila, int columnas, int columna, unsigned char *puntero)
{
    escribir_f(fila,columnas,columna,0,puntero);
    return 0;
}