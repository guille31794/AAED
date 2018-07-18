//
//  inversa.hpp
//  Cola inversa
//
//  Created by Guillermo Girón García on 5/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef inversa_hpp
#define inversa_hpp

#include <iostream>
#include "colaEnla.hpp"
#include "pilaEnla.hpp"
#include <cstdlib>

using namespace std;

//Inicializa a y b

void inicializaElem(int &a, int &b);

//Detecta que elemento es el mayor de los dos

void detectarMayor(int &a, int &b);

//Crea una pila dinamicamente con un número máximo de hasta 20 elementos aleatorios

void elemACola(int const &a, int const &b, Cola<unsigned> &C);

//Invierte la secuencia de elementos entre las primeras apariciones de a y b

Cola<unsigned> inverSec(int const &a, int const &b, Cola<unsigned> &C);

//Imprime por pantalla el contenido de la pila

void imprCola(Cola<unsigned> const &C);


#endif /* inversa_hpp */
