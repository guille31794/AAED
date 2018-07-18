//
//  main.cpp
//  TAD Pila con Bicola
//
//  Created by Guillermo Girón García on 11/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "opBicola.hpp"

int main(int argc, const char * argv[])
{
    Pila<unsigned> P;
    Cola<unsigned> C;
    
    elemAPila(P);
    imprPila(P);
    
    elemACola(C);
    imprCola(C);
    
    P.~Pila();
    C.~Cola();
    
    return 0;
}
