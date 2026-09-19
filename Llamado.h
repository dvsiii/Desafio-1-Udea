#ifndef LLAMADO_H
#define LLAMADO_H
int relleno(int fila, int columnas, int columna, unsigned char *puntero);
int lectura_f(unsigned int fila,unsigned int columnas,unsigned int columna, unsigned char *puntero);
int escribir_f(unsigned int fila,unsigned int columnas,unsigned int columna, unsigned int ficha, unsigned char *puntero);
int lectura_t(int columnas, int filas, int cascadas, unsigned char *puntero);
int mover(int fila, int columnas, int columna, unsigned char *puntero);
int ag_fila(int filas, int columnas, int filas_agregadas, int apartir_de_fila, unsigned char *puntero, unsigned char *copia);
int ag_columna(int filas, int columnas, int apartir_de_columna, unsigned char *puntero, unsigned char *copia);
int del_fila(int filas, int columnas, int fila_eliminda, unsigned char *puntero, unsigned char *copia, bool limite);
int del_columna(int filas, int columnas, int columna_eliminda, unsigned char *puntero, unsigned char *copia, bool limite);
int del_elemento(int fila, int columnas, int columna, unsigned char *puntero);
#endif // LLAMADO_H
