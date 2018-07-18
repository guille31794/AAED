//
//  isomorfica.hpp
//  Pilas y colas Isomorficas
//
//  Created by Guillermo Girón García on 2/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef isomorfica_hpp
#define isomorfica_hpp

#include <iostream>
#include <string>
#include "stdlib.h"
#include "colaEnla.hpp"
#include "pilaEnla.hpp"

using namespace std;

//Imprime el contenido de una pila

void imprPila(Pila<char> const &P);

//Inicializa una pila

void elemAPila(Pila<char> &P);

//Imprime el contenido de una cola

void imprCola(Cola<char> const &C);

//Inicializa una cola

void elemACola(Cola<char> &C);

//Devuelve verdadero si las estructuras son isomorficas

bool isomorfica(Pila<char> &P, Cola<char> &C);

#endif /* isomorfica_hpp */
