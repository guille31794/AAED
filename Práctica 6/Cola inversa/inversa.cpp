//
//  inversa.cpp
//  Cola inversa
//
//  Created by Guillermo Girón García on 5/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "inversa.hpp"

void inicializaElem(int &a, int &b)
{
    while(a > 9 || b > 9 || a < 0 || b < 0)
    {
        cout << "\rAmbos elementos menores que 10 y mayores o iguales a 0.";
        cout << "\nIntroduzca a: ";
        cin >> a;
        cout << "\nIntroduzca b: ";
        cin >> b;
        cout << endl;
    }
}


void detectarMayor(int &a, int &b)
{
    unsigned aux;
    
    if( b > a)
    {
        aux = a;
        a = b;
        b = aux;
    }
    
}

void elemACola(int const &a, int const &b, Cola<unsigned> &C)
{
    unsigned aleat, i, tamMax = 0;
    
    cout << "\rIntroduzca el tamaño máximo de la secuencia: ";
    
    while (tamMax > 20 || tamMax < 13)
    {
        cin >> tamMax;
    }
    
    cout << endl;
    
    for(i = 0; i < tamMax; ++i)
    {
        aleat = rand() % 10;
        
        C.push(aleat);
    }
}

void imprCola(Cola<unsigned> const &C)
{
    Cola<unsigned> impr;
    
    impr.operator = (C);
    
    while (!impr.vacia())
    {
        cout << impr.frente();
        impr.pop();
    }
    
    cout << endl;
    
    impr.~Cola();
}

Cola<unsigned> inverSec(int const &a, int const &b, Cola<unsigned> &C)
{
    Pila<unsigned> inv;
    Cola <unsigned> cNueva;
    
    while (/*!C.vacia() &&*/ C.frente() != a)
    {
        cNueva.push(C.frente());
        C.pop();
    }
    
    while (/*!C.vacia() &&*/ C.frente() != b)
    {
        inv.push(C.frente());
        C.pop();
    }
    
    inv.push(C.frente());
    C.pop();

    while (!inv.vacia())
    {
        cNueva.push(inv.tope());
        inv.pop();
    }
    
    while(!C.vacia())
    {
        cNueva.push(C.frente());
        C.pop();
    }
    
    inv.~Pila();
    
    return cNueva;
}
