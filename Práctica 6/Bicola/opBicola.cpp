//
//  opBicola.cpp
//  Bicola
//
//  Created by Guillermo Girón García on 4/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "opBicola.hpp"

void imprPila(Bicola<unsigned> const &B)
{
    Bicola<unsigned> impr;
    
    impr.operator = (B);
    
    while (!impr.vacia())
    {
        cout << impr.tope();
        impr.popInv();
    }
    
    cout << endl;
   
    impr.~Bicola();
}

void elemAPila(Bicola<unsigned> &B)
{
    unsigned i;
    
    for(i = 0; i < 5; ++i)
    {
        cout << i;
        B.push(i);
    }
    
    cout << endl;
}

void elemACola(Bicola<unsigned> &B)
{
    unsigned i;
    
    for(i = 0; i < 5; ++i)
    {
        cout << i;
        B.push(i);
    }
    
    cout << endl;
}

void imprCola(Bicola<unsigned> const &B)
{
    Bicola<unsigned> impr;
    
    impr.operator = (B);
    
    while (!impr.vacia())
    {
        cout << impr.frente();
        impr.pop();
        
    }
    
    cout << endl;
    
    impr.~Bicola();
}
