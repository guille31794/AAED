//
//  main.cpp
//  Invertir secuencia
//
//  Created by Guillermo Girón García on 28/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

//#include <iostream>
#include "invertirSecuencia.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    Pila<unsigned> P;
    int a = -1, b = -1;
    
    inicializaElem(a , b);
    
    detectarMayor(a, b);
    
    elemAPila(a, b, P);
    
    imprPila(P);
    
    inverSec(a, b, P);
    
    imprPila(P);
    
    P.~Pila();
    
    return 0;
}
