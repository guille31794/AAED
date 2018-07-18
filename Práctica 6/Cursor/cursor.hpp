//
//  cursor.hpp
//  Cursor
//
//  Created by Guillermo Girón García on 11/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef cursor_hpp
#define cursor_hpp

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "pilaEnla.hpp"

using namespace std;

//Introduce la cadena en la pila

void stringAPila(string &c, Pila<char> &P);

//Imprime por pantalla una pila

void imprPila(Pila<char> const &P);

//Menu ayuda

void helpMenu();

//Limpiar pantalla

void ClearScreen();

//Crea un bucle continuo que impide que termine el programa hasta cumplir cierta condicion

void bucle(Pila<char> &P1, Pila<char> &P2);

//Inicia el modo lectura hasta que se salga del programa o se cambie de modo

void readMode(Pila<char> &P1, Pila<char> &P2);

//Inicia el modo escritura hasta qe se cambie de modo

void writeMode(Pila<char> &P1, Pila<char> &P2);

// Post condicion: Devuelve el codigo de la key arrow presionada o -100 si ha pulsado escape.

char kbhit();

#endif /* cursor_hpp */
