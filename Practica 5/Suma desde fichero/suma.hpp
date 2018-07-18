//
//  suma.hpp
//  Suma desde fichero
//
//  Created by Guillermo Girón García on 29/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef suma_hpp
#define suma_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "pilaEnla.hpp"

using namespace std;

//Sobrecarga de operadores de flujo de datos de fstream

//Apila en P los valores numericos de los digitos extraidos del flujo de entrada de fe

fstream &operator >> (fstream &fe, Pila <int> &P);

//Inserta en el flujo de salida fs la pila P

fstream &operator << (fstream &fs, Pila<int> P);

//Fichero a pila

void fileToP(Pila <int> &P1, Pila <int> &P2, fstream &F);

//Genera un fichero con dos enteros aleatorios

void genFich(fstream &F);

//Suma con acarreos

void sumAc(Pila <int> &P1, Pila <int> &P2, Pila <int> &P3);

//Imprimir Pila

void imprPila(Pila<int> const &P);

//Pila a fichero

void PtoFile(Pila <int> &P3, fstream &F);

#endif /* suma_hpp */
