//
//  main.cpp
//  Suma desde fichero
//
//  Created by Guillermo Girón García on 29/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "suma.hpp"

int main(int argc, const char * argv[])
{
    fstream FILE;
    Pila<int> N1, N2, RES;

    genFich(FILE);

    fileToP(N1, N2, FILE);

    imprPila(N1);
    imprPila(N2);
    
    sumAc(N1, N2, RES);
    
    imprPila(RES);
     
    PtoFile(RES, FILE);
     
    N1.~Pila();
    N2.~Pila();
    RES.~Pila();

    return 0;
}
