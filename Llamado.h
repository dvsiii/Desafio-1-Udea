#ifndef LLAMADO_H
#define LLAMADO_H
int relleno(int fila, int columnas, int columna, unsigned char *puntero);
int lectura_f(int fila, int columnas, int columna, unsigned char *puntero);
int lectura_t(int columnas, int filas, unsigned char *puntero);
int mover(int fila, int columnas, int columna, unsigned char *puntero);
int ag_fila(int filas, int columnas, int filas_agregadas, int apartir_de_fila, unsigned char *puntero, unsigned char *copia);
int del_elemento(int fila, int columnas, int columna, unsigned char *puntero);
#endif // LLAMADO_H
