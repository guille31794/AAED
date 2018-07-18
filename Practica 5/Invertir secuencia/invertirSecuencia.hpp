//
//  invertirSecuencia.hpp
//  Invertir secuencia
//
//  Created by Guillermo Girón García on 28/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef invertirSecuencia_hpp
#define invertirSecuencia_hpp

#include "pilaEnla.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

//Inicializa a y b

void inicializaElem(int &a, int &b);

//Detecta que elemento es el mayor de los dos

void detectarMayor(int &a, int &b);

//Crea una pila dinamicamente con un número máximo de hasta 20 elementos aleatorios

void elemAPila(int const &a, int const &b, Pila<unsigned> &P);

//Invierte la secuencia de elementos entre las primeras apariciones de a y b

void inverSec(int const &a, int const &b, Pila<unsigned> &P);

//Imprime por pantalla el contenido de la pila

void imprPila(Pila<unsigned> const &P);

#endif /* invertirSecuencia_hpp */
