//
//  main.cpp
//  Pilas y colas Isomorficas
//
//  Created by Guillermo Girón García on 2/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include <iostream>
#include "isomorfica.hpp"

int main(int argc, const char * argv[])
{
    Pila<char> P{};
    Cola<char> C{};
    
    elemAPila(P);
    elemACola(C);
    
    imprPila(P);
    imprCola(C);
    
    if(isomorfica(P, C))
        cout << "La pila y la cola son isomorficas" << endl;
    else
        cout << "La pila y la cola no son isomorficas" << endl;

    return 0;
}
