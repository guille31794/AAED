//
//  isomorfica.cpp
//  Pilas y colas Isomorficas
//
//  Created by Guillermo Girón García on 2/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "isomorfica.hpp"

void imprPila(Pila<char> const &P)
{
    Pila<char> impr{};
    
    impr.operator = (P);
    
    while (!impr.vacia())
    {
        cout << impr.tope();
        impr.pop();
        
    }
    
    cout << endl;
    
    impr.~Pila();
}

void elemAPila(Pila<char> &P)
{
    unsigned i;
    unsigned long tamMax;
    string secuencia;
    
    
    cout << "\rIntroduzca una secuencia: ";
    cin >> secuencia;
    cout << endl;
    
    tamMax = secuencia.length();
    
    for(i = 0; i < tamMax; ++i)
    {
        P.push(secuencia[i]);
    }
}

void elemACola(Cola<char> &C)
{
    unsigned i;
    unsigned long tamMax;
    string secuencia;
    
    
    cout << "\rIntroduzca una secuencia: ";
    cin >> secuencia;
    cout << endl;
    
    tamMax = secuencia.length();
    
    for(i = 0; i < tamMax; ++i)
    {
        C.push(secuencia[i]);
    }
}

void imprCola(Cola<char> const &C)
{
    Cola<char> impr{};
    
    impr.operator = (C);
    
    while (!impr.vacia())
    {
        cout << impr.frente();
        impr.pop();
        
    }
    
    cout << endl;
    
    impr.~Cola();
}

bool isomorfica(Pila<char> &P, Cola<char> &C)
{
    bool iso = true;
    
    P.pop();
    
    while(!P.vacia() && !C.vacia())
    {
        if(!(P.tope() == C.frente()))
        {
            iso = false;
            break;
        }
        
        if(!P.vacia() && !C.vacia())
        {
            P.pop();
            C.pop();
        }
        
        if(!P.vacia() && !C.vacia())
        {
            P.pop();
            C.pop();
        }
    }
           
    return iso;
}

