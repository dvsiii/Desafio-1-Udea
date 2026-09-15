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
    return 0;
}
int lectura(unsigned char *puntero)
{
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