//
//  polinomio.hpp
//  TAD Polinomio
//
//  Created by Guillermo Girón García on 17/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef polinomio_hpp
#define polinomio_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

const int gradoM = 3;
class polinomio;

//Sobrecarga del operador suma

polinomio operator *(const polinomio &p1, const polinomio &p2);

//Sobrecarga del operador resta

polinomio operator -(const polinomio &p1, const polinomio &p2);

//Sobrecarga del operador producto

polinomio operator *(const polinomio &p1, const polinomio &p2);

//Metodo que efectua la derivada



#endif /* polinomio_hpp */
