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
#include "color.h"

using namespace std;

//Introduce la cadena en la pila

void stringAPila(string &c, Pila<char> &P);

//Introduce una pila en una cadena

void pilaAString(string &c, Pila<char> &P);

//Imprime una cadena extraida de una pilaAString

void imprString(string s);

//Imprime por pantalla una pila

void imprPila(Pila<char> const &P);

void imprPilaInv(Pila<char> const &P);

//Menu ayuda

void helpMenu();

//Limpiar pantalla

void ClearScreen();

//Crea un bucle continuo que impide que termine el programa hasta cumplir cierta condicion

void bucle(Pila<char> &P1, Pila<char> &P2);

//Avanza el cursor una posicion

void avanzaC(Pila<char> &P1, Pila<char> &P2);

//Retrocede el cursor una posicion

void retroC(Pila<char> &P1, Pila<char> &P2);

//Borra un caracter de la linea de texto

void del(Pila<char> &P);

//Borra el caracter sobre el que está el cursor

void supr(Pila<char> &P);

//Situa el cursor al principio de linea

void iniC(Pila<char> &P1, Pila<char> &P2);

//Situa el cursor al final de la linea

void finC(Pila<char> &P1, Pila<char> &P2);

//Inicia el modo lectura hasta que se salga del programa o se cambie de modo

void readMode(Pila<char> &P1, Pila<char> &P2);

//Inicia el modo escritura hasta qe se cambie de modo

void writeMode(Pila<char> &P1, Pila<char> &P2);

// Post condicion: Devuelve el codigo de la key arrow presionada o -100 si ha pulsado escape.

char kbhit();

#endif /* cursor_hpp */
