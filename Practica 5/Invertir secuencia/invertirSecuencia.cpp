//
//  invertirSecuencia.cpp
//  Invertir secuencia
//
//  Created by Guillermo Girón García on 28/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "invertirSecuencia.hpp"

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

void elemAPila(int const &a, int const &b, Pila<unsigned> &P)
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
        
        P.push(aleat);
    }
}

void imprPila(Pila<unsigned> const &P)
{
    Pila<unsigned> impr;
    
    impr.operator = (P);
    
    while (!impr.vacia())
    {
        cout << impr.tope();
        impr.pop();
    }
    
    cout << endl;
    
    impr.~Pila();
}

void inverSec(int const &a, int const &b, Pila<unsigned> &P)
{
    Pila<unsigned> inv;
    unsigned *v;
    int i, j;
    
    i = 0;
    v = (unsigned*) malloc(20 * (sizeof(unsigned)));
    
    while (/*!P.vacia() &&*/ P.tope() != b)
    {
        inv.push(P.tope());
        P.pop();
    }
    
    while (/*!P.vacia() &&*/ P.tope() != a)
    {
        v[i] = P.tope();
        P.pop();
        ++i;
    }
    
    v[i] = P.tope();
    P.pop();
    
    j = 0;
    
    while (j <= i)
    {
        P.push(v[j]);
        ++j;
    }
    
    while (!inv.vacia())
    {
        P.push(inv.tope());
        inv.pop();
    }
    
    inv.~Pila();
    free(v);
}
