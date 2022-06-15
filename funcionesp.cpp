#include <iostream>
#include <cstdlib>
#include <clocale>
#include "funcionesp.h"
#include "rlutil.h"
#include <limits>
#include <time.h>



using namespace std;


void cuadro (int x1,int x2,int y1,int y2) {

    int x=y1, j=y1;
    rlutil::locate(x1, y1);

    cout << (char)201;

    for (int i=0; i<x2-x1-1; i++) {

        cout << (char)205;

    }



    rlutil::locate(x2, y1);
    cout << (char)187;


    for (int i=0; i<y2-y1-1; i++) {
        x++;
        rlutil::locate(x2, x);
        cout << (char)186 << endl;
    }


    cout << endl;

    for (int i=0; i<y2-y1-1; i++) {
        j++;
        rlutil::locate(x1, j);

        cout << (char)186 << endl;
    }


    rlutil::locate(x1, y2);
    cout << (char)200;



    for (int i=0; i<x2-x1-1; i++) {

        cout << (char)205;


    }

    rlutil::locate (x2, y2);
    cout << (char)188;



}


int opciones (int menu) {
    int menu2;
    cout << endl;
    rlutil::locate(51, 8);
    cout << "Mathrix" << endl;
    rlutil::locate(36, 9);
    cout << "----------------------------------------" << endl;
    rlutil::locate(49, 10);
    cout << "1. Jugar " << endl;
    rlutil::locate(49, 11);
    cout << "2. Instrucciones " << endl;
    rlutil::locate(49, 12);
    cout << "3. Estadisticas" << endl;
    rlutil::locate(49, 13);
    cout << "4. Creditos" << endl;
    rlutil::locate(36, 14);
    cout << "----------------------------------------" << endl;
    rlutil::locate(49, 15);
    cout << "0. Salir del juego" << endl;
    rlutil::locate(49, 16);
    cout << "Ingrese numero: ";

    while (!(cin>>menu)) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        rlutil::cls();
        cout << "Opcion incorrecta!!";
        cout << endl << "Presione cualquier tecla para volver al menu. ";
        rlutil::anykey();
        rlutil::cls();


        cuadro(35,76,7,18);
        cout << endl;
        rlutil::locate(51, 8);
        cout << "Mathrix" << endl;
        rlutil::locate(36, 9);
        cout << "----------------------------------------" << endl;
        rlutil::locate(49, 10);
        cout << "1. Jugar " << endl;
        rlutil::locate(49, 11);
        cout << "2. Instrucciones " << endl;
        rlutil::locate(49, 12);
        cout << "3. Estadisticas" << endl;
        rlutil::locate(49, 13);
        cout << "4. Creditos" << endl;
        rlutil::locate(36, 14);
        cout << "----------------------------------------" << endl;
        rlutil::locate(49, 15);
        cout << "0. Salir del juego" << endl;
        rlutil::locate(49, 16);
        cout << "Ingrese numero: ";
    }

    return menu;
}



void randomatriz (int m[][6], int tam1, int tam2) {
    for (int i=0; i<tam1; i++) {
        for (int x=0; x < tam2; x++) {

            m[i][x] = rand()%10;

        }

    }
}

void mostrarmatriz (int m[][6], bool mb[][8], int tam1, int tam2) {
    for (int i=0; i<tam1; i++) {
        cout << i+1 << " | ";
        for (int x=0; x < tam2; x++) {
            if (mb[i+1][x+1]==false) {

                cout << m[i][x] << " ";
            }

            else {
                cout << "X ";
            }

        }
        cout << endl;
    }
    cout << "  --------------" << endl;
    cout << "    ";
    for (int j=0; j<6; j++) {

        cout << j+1 << " ";
    }
}

void contornobool (bool mb[][8], int tam1, int tam2) {

    for (int k=0; k<tam1; k++) {

        for (int f=0; f<tam2; f++) {

            if (k==0 || f == 0 || k==7 || f==7  )  {
                mb[k][f]=true;
            }

        }

    }

}

int calculo (int m[][6],int tam1,int tam2,int x,int y,char op,int direc, bool mb[][8], int tamb1,int tamb2) {
    float r;
    int puntajer=0;

        switch (op) {
            case '+':
            if (direc==8) {

                r = m[x-1][y-1] + m[x-2][y-1];
                if (r==m[x-3][y-1]) {

                    puntajer =  m[x-1][y-1] + m[x-2][y-1] + m[x-3][y-1];



                    return puntajer;
                }

                else {
                    return 999;
                }


            }

            if (direc==2) {
                r = m[x-1][y-1] + m[x][y-1];
                if (r==m[x+1][y-1]) {

                    puntajer =  m[x-1][y-1] + m[x][y-1] + m[x+1][y-1];

                    return puntajer;
                }

                else {
                    return 999;
                }


            }

            if (direc==4) {
                r = m[x-1][y-1] + m[x-1][y-2];
                if (r==m[x-1][y-3]) {
                    puntajer =  m[x-1][y-1] + m[x][y-2] + m[x+1][y-3];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }

            if (direc==6) {
                r = m[x-1][y-1] + m[x-1][y];
                if (r==m[x-1][y+1]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y] + m[x-1][y+1];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }



            break;

        case '-':

            if (direc==8) {

                r = m[x-1][y-1] - m[x-2][y-1];
                if (r==m[x-3][y-1]) {
                    puntajer =  m[x-1][y-1] + m[x-2][y-1] + m[x-3][y-1];

                    return puntajer;
                }

                 else {
                    return 999;
                }

            }
            if (direc==2) {
                r = m[x-1][y-1] - m[x][y-1];
                if (r==m[x+1][y-1]) {
                    puntajer =  m[x-1][y-1] + m[x][y-1] + m[x+1][y-1];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }
            if (direc==4) {
                r = m[x-1][y-1] - m[x-1][y-2];
                if (r==m[x-1][y-3]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y-2] + m[x-1][y-3];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }
            if (direc==6) {
                r = m[x-1][y-1] - m[x-1][y];
                if (r==m[x-1][y+1]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y] + m[x-1][y+1];
                    return puntajer;
                }

                else {
                    return 999;
                }


            }

            break;

        case '*':
            if (direc==8) {
                r = m[x-1][y-1] * m[x-2][y-1];
                if (r==m[x-3][y-1]) {
                    puntajer =  m[x-1][y-1] + m[x-2][y-1] + m[x-3][y-1];

                    return puntajer ;
                }

                else {
                    return 999;
                }

            }
            if (direc==2) {
                r = m[x-1][y-1] * m[x][y-1];
                if (r==m[x+1][y-1]) {
                    puntajer =  m[x-1][y-1] + m[x][y-1] + m[x+1][y-1];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }
            if (direc==4) {
                r = m[x-1][y-1] * m[x-1][y-2];
                if (r==m[x-1][y-3]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y-2] + m[x-1][y-3];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }
            if (direc==6) {
                r = m[x-1][y-1] * m[x-1][y];
                if (r==m[x-1][y+1]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y] + m[x-1][y+1];
                    return puntajer;
                }

                else {
                    return 999;
                }


            }

            break;

        case '/':

            if (direc==8) {
                r = m[x-1][y-1] / m[x-2][y-1];
                if (r==m[x-3][y-1]) {
                    puntajer =  m[x-1][y-1] + m[x-2][y-1] + m[x-3][y-1];

                    return puntajer ;
                }

                else {
                    return 999;
                }
            }
            if (direc==2) {
                r = m[x-1][y-1] / m[x][y-1];
                if (r==m[x+1][y-1]) {
                    puntajer =  m[x-1][y-1] + m[x][y-1] + m[x+1][y-1];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }
            if (direc==4) {
                r = m[x-1][y-1] / m[x-1][y-2];
                if (r==m[x-1][y-3]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y-2] + m[x-1][y-3];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }
            if (direc==6) {
                r = m[x-1][y-1] / m[x-1][y];
                if (r==m[x-1][y+1]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y] + m[x-1][y+1];
                    return puntajer;
                }

                else {
                    return 999;
                }


            }

            break;

        case '%':

            if (direc==8) {
                r = m[x-1][y-1] % m[x-2][y-1];
                if (r==m[x-3][y-1]) {
                    puntajer =  m[x-1][y-1] + m[x-2][y-1] + m[x-3][y-1];

                    return puntajer ;
                }

                else {
                    return 999;
                }
            }
            if (direc==2) {
                r = m[x-1][y-1] % m[x][y-1];
                if (r==m[x+1][y-1]) {
                    puntajer =  m[x-1][y-1] + m[x][y-1] + m[x+1][y-1];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }
            if (direc==4) {
                r = m[x-1][y-1] % m[x-1][y-2];
                if (r==m[x-1][y-3]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y-2] + m[x-1][y-3];
                    return puntajer;
                }

                else {
                    return 999;
                }

            }
            if (direc==6) {
                r = m[x-1][y-1] % m[x-1][y];
                if (r==m[x-1][y+1]) {
                    puntajer =  m[x-1][y-1] + m[x-1][y] + m[x-1][y+1];
                    return puntajer;

                }

                else {
                    return 999;
                }


            }

            break;

        default:

            break;
        }

    }




int validarpos (bool mb[][8], int tam1, int tam2, int x, int y, int direc) {

    if ((x > 6 || x < 1) || (y>6 || y<1) == 1) {
        //Si la coordenada inicial esta mal
        return 1;
    }
    else {

        switch (direc) {
        case 8:
            if (mb[x][y] || mb[x-1][y] || mb[x-2][y] == 1) {

                return 2;
            }

            break;

        case 2:

            if (mb[x][y] || mb[x+1][y] || mb[x+2][y] == 1) {

                return 2;
            }

            break;

        case 4:

            if (mb[x][y] || mb[x][y-1] || mb[x][y-2] == 1) {

                return 2;
            }

            break;

        case 6:

            if (mb[x][y] || mb[x][y+1] || mb[x][y+2] == 1) {

                return 2;
            }

            break;


        default:
            break;
        }

    }
}

void poneren1 (bool mb[][8], int tam1, int tam2, int x, int y, int direc) {

    switch (direc) {
    case 8:

        mb[x][y]=true;
        mb[x-1][y]=true;
        mb[x-2][y]=true;


        break;

    case 2:
        mb[x][y]=true;
        mb[x+1][y]=true;
        mb[x+2][y]=true;

        break;

    case 4:
        mb[x][y]=true;
        mb[x][y-1]=true;
        mb[x][y-2]=true;

        break;

    case 6:
        mb[x][y]=true;
        mb[x][y+1]=true;
        mb[x][y+2]=true;

        break;


    default:

        break;
    }


}
int puntajemaximo (int pt,int pm,char nombre[],char calcu[],char nombreM[],char calcuM[]) {
    if (pt >= pm) {
        pm=pt;
        strcpy(nombreM, nombre);
        strcpy(calcuM,calcu);
    }

    return pm;

}

void cuadrito () {
    int j=25;
    rlutil::locate(24,1);
    cout << (char)186;
    rlutil::locate(24,2);
    cout << (char)200 << endl;

    for (int i=0; i<37; i++) {
        rlutil::locate(j,2);
        cout << (char)205;
        j++;
    }
    rlutil::locate(61,2);
    cout << (char)188;
    rlutil::locate(61,1);
    cout << (char)186;

    rlutil::locate(35,1);
    cout << (char)186;
    rlutil::locate(35,2);
    cout << (char)202;

    rlutil::locate(50,1);
    cout << (char)186;
    rlutil::locate(50,2);
    cout << (char)202;


}
void sonrisa(int x1,int x2,int y) {


    rlutil::locate(x1, y-1);
    cout << (char)186;
    rlutil::locate(x1, y-2);
    cout << (char)186;
    rlutil::locate(x2, y-1);
    cout << (char)186;
    rlutil::locate(x2, y-2);
    cout << (char)186;
    rlutil::locate(x1, y);
    cout << (char)200;

    for (int i=x1+1; i<x2+1; i++) {
        rlutil::locate(i, y);
        cout << (char)205;
    }

    rlutil::locate(x2, y);
    cout << (char) 188;
    cout << endl << endl;
}
void poneren0 (bool mb[][8], int tam1, int tam2){
    for (int i=0; i<tam1; i++){
        for (int x=0; x<tam2; x++){

            mb[i][x] = 0;
        }
    }
}

