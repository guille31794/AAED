//
//  ABCD.hpp
//  A, B, C, D..
//
//  Created by Guillermo Girón García on 27/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef ABCD_hpp
#define ABCD_hpp

#include "pilaEnla.hpp"
#include <string>

using namespace std;

//Comprueba si la secuencia de caracteres es del tipo solicitado

bool comprobarAlmohadillas(string &c);

//Introduce la cadena en una pila

unsigned stringAPila(string &c, Pila<char> &P1, Pila<char> &P2);

//Comprueba y devuelve si la secuencia de caracteres cumple el modelo solicitado

bool comprobarSecuencia(Pila<char> &P1, Pila<char> &P2, unsigned c);

//Convierte una cadena a mayusculas

void stringToMayus(string &c);

#endif /* ABCD_hpp */
