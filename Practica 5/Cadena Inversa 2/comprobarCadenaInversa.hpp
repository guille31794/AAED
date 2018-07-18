//
//  comprobarCadenaInversa.hpp
//  TAD Pila
//
//  Created by Guillermo Girón García on 24/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef comprobarCadenaInversa_hpp
#define comprobarCadenaInversa_hpp

#include <string>
#include "pilaEnla.hpp"

using namespace std;

//Comprueba si el formato de la cadena es el correcto

bool comprobarAmpersand(string cadena );

//Envía la cadena a la pila y la inicializa

void stringAPila(string &c, Pila<char> &P1, Pila<char> &P2);

//Comprueba si la cadena introducida tiene la invresa correctamente

void comprobarInversa(Pila<char> &P1, Pila<char> &P2, string &c);

#endif /* comprobarCadenaInversa_hpp */
