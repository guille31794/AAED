//
//  comprobarCadenaInversa.cpp
//  TAD Pila
//
//  Created by Guillermo Girón García on 24/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "comprobarCadenaInversa.hpp"
#include <iostream>

using namespace std;

bool comprobarAmpersand(string cadena )
{
    bool esValido;
    unsigned long l;
    
    esValido = true;
    l = cadena.length();
    
    if(l % 2 )
    {
        if(cadena[l/2] != '&')
            esValido = false;
    }
    else
    {
        if(cadena [(l/2) + 1 ] != '&' )
            esValido = false;
    }
    
    return esValido;
}

void stringAPila(string &c, Pila<char> &P1, Pila<char> &P2)
{
    unsigned long l, j;
    unsigned i;
    
    l = c.length();
    j = l-1;
    
    if( l % 2)
    {
        for (i = 0; i < l/2; ++i)
        {
            P1.push(c[i]);
            P2.push(c[j]);
            
            --j;
        }
    }
    else
    {
        for (i = 0; i < (l/2) + 1; ++i)
        {
            P1.push(c[i]);
            P2.push(c[j]);
            
            --j;
        }
    }
    
}

void comprobarInversa(Pila <char> &P1, Pila <char> &P2, string &c)
{
    unsigned long l;
    bool inversa;
    
    l = c.length();
    
    if(l % 2)
        l = l / 2;
    else
        l = (l / 2) + 1;
    
    while (!l && P1.tope() == P2.tope())
    {
        --l;
        P1.pop();
        P2.pop();
    }
    
    inversa = P1.tope() == P2.tope();
    
    if(inversa)
        cout << "La cadena tiene su inversa";
    else
        cout << "La cadena no tiene su inversa";
    
    cout << endl;
}

