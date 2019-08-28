//
//  opBicola.hpp
//  Bicola
//
//  Created by Guillermo Girón García on 4/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#ifndef opBicola_hpp
#define opBicola_hpp

#include "bicola.hpp"
#include <iostream>
#include <string>

using namespace std;

//Imprime los elementos de la bicola por pantalla tal como si de una pila se tratase

void imprPila(Bicola<unsigned> const &B);

//Imprime los elementos de la bicola por pantalla tal como si de una cola se tratase

void imprCola(Bicola<unsigned> const &B);

//Introduce elementos en la bicola tal como si de una pila se tratase

void elemAPila(Bicola<unsigned> &B);

//Introduce elementos en la bicola tal como si de una cola se tratase

void elemACola(Bicola<unsigned> &B);

#endif /* opBicola_hpp */
