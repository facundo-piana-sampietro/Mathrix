/* Al ingresar las coordenadas de matriz 0,0 se pierde una pila pero se aleatoriza nuevamente toda la matriz.
*/

#include <iostream>
#include "funcionesp.h"
#include <time.h>
#include "rlutil.h"
#include <stdlib.h>
#include <string.h>
#include <limits>


using namespace std;

int main() {
    //Personalizacion consola
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::setColor(rlutil::YELLOW);

    //Declaracion de variables del main
    int menu, matriz [6][6]= {};
    char nombre[50], calcu[50], nombreM[50], calcuM[50];
    char confir='N';
      int cs=0,cp=0, puntajemax=0;
    int puntajet=0;
    srand (time (NULL));



    while (confir!='Y' && confir!='y') {
        //Variables que se reinician por partida
        bool matrizbool[8][8] = {};
        int vidas=3, x, y, direc, crondas = 1;
        char op;

        rlutil::cls();

        cuadro(35,76,7,18);

        cout << endl;


        switch (opciones(menu)) {
        case 1:
            //Juego

            puntajet=0;
            rlutil::cls();
            cuadro(35,76,7,18);


            //Pedida de datos
            rlutil::locate(47, 10);
            cout << "Ingresar nombre: ";

            rlutil::locate(47, 11);
            cin.ignore();
            cin.getline(nombre, 50);


            rlutil::locate(47, 13);
            cout << "Ingresar modelo de " << endl;
            rlutil::locate(47, 14);
            cout << "calculadora favorita: ";

            rlutil::locate(47, 15);
            cin.getline(calcu, 50);


            cs++;
            rlutil::cls();

            cout << "Comienza el juego!" << endl;

            randomatriz (matriz, 6, 6);

            while (vidas!=0) {
                cuadrito ();

                //Informacion sobre la partida
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::locate(26, 1);
                cout << "Ronda: " << crondas;
                rlutil::locate(38, 1);
                cout << "Puntaje: " << puntajet;
                rlutil::locate(52, 1);
                cout << "Pilas: " << vidas;
                rlutil::setColor(rlutil::YELLOW);
                if (crondas == 1) {
                    cout << endl << endl;
                }

                else {
                    cout << endl;
                }

                mostrarmatriz (matriz, matrizbool, 6, 6);

                //Pedida de datos del juego
                cout << endl << endl << "Ingresar coordenada X (horizontal): ";

                while (!(cin>>x)) {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << endl;
                    cout << "Ingresar una coordenada correcta: ";
                }

                cout << endl << "Ingresar coordenada Y (vertical): ";
                while (!(cin>>y)) {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << endl;
                    cout << "Ingresar una coordenada correcta: ";
                }

                cout << endl << "Ingresar operador: ";
                cin >> op;

                while (op!='+' && op!='-' && op!='/' && op!='*' && op!='%' ) {
                    rlutil::setColor(rlutil::YELLOW);
                    cout << endl << "Ingrese un operador correcto: ";
                    cin >> op;
                }

                rlutil::setColor(rlutil::YELLOW);
                cout << endl << "Ingrese direccion: ";


                while  (!(cin>>direc) || direc != 8 && direc != 6 && direc != 4 && direc != 2) {
                    rlutil::setColor(rlutil::YELLOW);
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << endl << "Ingrese una direccion correcta: ";
                }


                rlutil::setColor(rlutil::YELLOW);

                contornobool(matrizbool, 8, 8);

                //Si ingresa las coordenadas 0 Y 0

                if (x==0 && y==0) {
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << endl << "Usted pierde una pila por ingresar las coordenadas 0 y 0." << endl << "Se cambiaran los valores del tablero." << endl;
                    vidas--;
                    randomatriz (matriz, 6, 6);
                    poneren0 (matrizbool, 8, 8);

                }

                //Si el usuario elige una coordenada inicial incorrecta
                else if (validarpos(matrizbool, 8, 8, x, y, direc) == 1) {
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << endl << "Usted eligio una coordenada inicial incorrecta. Pierde una pila :(" << endl;
                    vidas--;

                }



                //Si se pasa de la matriz o si pisa unas X´s
                else if (validarpos(matrizbool, 8, 8, x, y, direc)==2) {
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << endl << "Usted se movio incorrectamente dentro del tablero. Pierde una pila :( " << endl;
                    vidas--;

                }


                //Si realiza el calculo correctamente
                else if (calculo(matriz, 6, 6, x, y, op, direc, matrizbool, 8, 8) != 999) {
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    cout << endl << "El calculo fue correcto!!" << endl;
                    cout << "El puntaje de esta ronda fue " << calculo(matriz, 6, 6, x, y, op, direc, matrizbool, 8, 8) << "." << endl;
                    puntajet += calculo(matriz, 6, 6, x, y, op, direc, matrizbool, 8, 8);
                    poneren1(matrizbool,8,8,x,y,direc);

                }

                //Si realiza el calculo incorrectamente
                else if (calculo(matriz, 6, 6, x, y, op, direc, matrizbool, 8, 8) == 999) {
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << endl << "El calculo fue incorrecto. Pierde una pila :(" << endl;
                    vidas--;

                }

                rlutil::setColor(rlutil::YELLOW);
                cout << endl << "Presione cualquier tecla para pasar a la siguiente ronda.";
                rlutil::anykey();
                rlutil::cls();
                crondas++;
            }


            //Puntaje final
            cuadro(35,76,7,18);
            rlutil::locate(36, 10);
            cout << "Usted a perdido a las 3 pilas. Game over" << endl;
            rlutil::locate(46, 12);
            cout << "Su puntaje fue: " << puntajet << endl;



            rlutil::locate(44, 14);
            cout << "Presione cualquier tecla ";
            rlutil::locate(46, 15);
            cout << "para volver al menu.";
            rlutil::anykey();
            rlutil::cls();

            break;
        case 2:
            //Instrucciones

            rlutil::cls();
            cout << "Instrucciones: " << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "Mathrix es un juego individual donde pones a prueba tu destreza matematica." << endl << "Consiste en ";
            cout << "una matriz de 6x6 que se completa con numeros del 0 al 9 ubicados" << endl <<  "aleatoriamente.";
            cout << " El objetivo general del juego es sumar la mayor cantidad de " << endl <<  "puntos en el transcurso de las rondas hasta quedarse sin pilas." << endl << endl << "El juego comienza con un total de tres pilas." << endl;
            cout << "En el transcurso de una ronda, el jugador debe ingresar "<< endl <<"la coordenada del primer numero con el que desea elaborar una ecuacion." << endl << "Luego de este paso, debe elegir el operador matematico necesario" << endl;
            cout << "para la ecuacion (+, -, *, / o %).";
            cout <<  " Por ultimo, debe elegir la direccion" << endl << "hacia donde se resuelve la ecuacion. Los valores pueden ser: "<< endl << "-Arriba: 8 "<< endl << "-Abajo: 2" << endl << "-Izquierda: 4" << endl << "-Derecha: 6" << endl;
            cout << endl << "Si el calculo es correcto, se obtendra la suma de los 3 numeros." << endl <<"En dicho caso, se bloquearan los casilleros de la operacion." << endl;
            cout << "Se puede perder una pila en los siguientes casos: " << endl;
            cout << "-Si el calculo fue incorrecto" << endl << "-Si se elige una coordenada incorrecta" << endl << "-Si se mueve fuera del tablero" << endl << "-Si se realiza un calculo con un casillero bloqueado." << endl;
            cout << "Por ultimo, si se eligen las coordenadas 0 y 0, se perderá una pila, pero se" << endl << "cambiaran los numeros del tablero nuevamente." << endl;


            cout << endl << "Presione cualquier tecla para volver al menu. ";
            rlutil::anykey();
            rlutil::cls();
            break;
        case 3:

            // Estadisticas

            rlutil::cls();
            puntajemax = puntajemaximo (puntajet, puntajemax, nombre, calcu, nombreM, calcuM);
            if (cs==0) {
                cout << "No se ha jugado todavia!";
            } else {
                cout << "Jugador con mayor puntaje: " << endl << endl;
                cout << "Nombre: " << nombreM << endl << "Calculadora: " << calcuM << endl << "Puntaje: " << puntajemax;
            }


            cout << endl << endl << "Presione cualquier tecla para volver al menu. ";
            rlutil::anykey();
            rlutil::cls();
            break;

        case 4:
            //Creditos

            rlutil::cls();
            cout << "Desarrollado por: " << endl;
            cout << "Piana Sampietro Facundo (Legajo 25035)" << endl << "Rugolo Hernan Fabricio (Legajo 25049)" << endl << "Mendez Alberto Nicolas (Legajo 25010)" << endl << endl;
            cout << "- Iconos obtenidos de Freepik " << endl << "- Adaptacion del juego Mathrix " << endl << "- Piecepack game creado por Clarck D. Rodeffer." << endl;
            cout << endl << "Presione cualquier tecla para volver al menu. ";
            rlutil::anykey();
            rlutil::cls();
            break;

        case 0:
            //Salir

            rlutil::cls();
            cout << "Desea salir?" << endl << "-Ingrese 'Y' para salir." << endl << "-Ingrese cualquier tecla para volver al menu." << endl;
            cin >> confir;
            break;

        default:
            rlutil::cls();
            cout << "Opcion incorrecta..." << endl;
            cout << endl << "Presione cualquier tecla para volver al menu. ";
            rlutil::anykey();
            rlutil::cls();
            break;

        }

    }

    rlutil::cls();
    cuadro(35,76,7,18);
    rlutil::locate(47, 12);
    cout << "Gracias por jugar.";
    rlutil::locate(49, 13);
    cout << "Hasta luego!!" << endl;

    //Carita izquierda
    cuadro(10,15,9,12);
    cuadro(20,25,9,12);
    sonrisa(10, 25, 17);

    //Carita derecha
    cuadro(86,91,9,12);
    cuadro(96,101,9,12);
    sonrisa(86, 101, 17);
    cout << endl << endl << endl << endl << endl << endl << endl;
    return 0;
}
