#ifndef FUNCIONESP_H_INCLUDED
#define FUNCIONESP_H_INCLUDED

void cuadro (int, int, int, int);
int opciones (int);
void randomatriz (int [][6], int, int);
void mostrarmatriz (int [][6], bool [][8], int, int);
void  contornobool(bool[][8], int, int);
int calculo (int[][6], int,int, int, int, char, int, bool[][8], int, int);
int validarpos(bool [] [8], int, int, int, int, int);
void  poneren1(bool[][8], int, int, int, int, int);
int puntajemaximo (int, int, char[], char[], char[],char[]);
void cuadrito ();
void sonrisa (int, int, int);
void  poneren0(bool[][8], int, int);


#endif // FUNCIONESP_H_INCLUDED
