//
//  main.cpp
//  Cola inversa
//
//  Created by Guillermo Girón García on 5/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "inversa.hpp"

int main(int argc, const char * argv[])
{
    Cola<unsigned> C;
    int a = -1, b = -1;
    
    inicializaElem(a , b);
    
    detectarMayor(a, b);
    
    elemACola(a, b, C);
    
    imprCola(C);
    
    C = inverSec(a, b, C);
    
    imprCola(C);
    
    C.~Cola();
    
    return 0;
}
