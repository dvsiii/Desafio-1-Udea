#ifndef LLAMADO_H
#define LLAMADO_H
int relleno(int fila, int columnas, int columna, unsigned char *puntero);
int lectura_f(int fila, int columnas, int columna, unsigned char *puntero);
int lectura_t(int columnas, int filas, unsigned char *puntero);
int mover(int fila, int columna, unsigned char *puntero);
int del_elemento(int fila, int columna, unsigned char *puntero);
#endif // LLAMADO_H
