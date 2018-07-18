//
//  ABCD.cpp
//  A, B, C, D..
//
//  Created by Guillermo Girón García on 27/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "ABCD.hpp"

unsigned stringAPila(string &c, Pila<char> &P1, Pila<char> &P2)
{
    unsigned i, cont;
    unsigned long l, j;
    
    l = c.length();
    j = l - 1;
    cont = 0;
    
    for(i = 0; i < l && c[i] != '&'; i += 2)
    {
        P1.push(c[i]);
        P2.push(c[j]);
        
        ++cont;
        j -= 2;
    }
    
    return cont;
}

bool comprobarAlmohadillas(string &c)
{
    bool esValido;
    unsigned i;
    unsigned long l;
    
    l = c.length();
    i = 1;
    
    while( i < l && c[i] == '#')
    {
        i += 2;
    }
    
    esValido = i >= l;
    
    return esValido;
}

void stringToMayus(string &c)
{
    unsigned i;
    
    for(i = 0; i < c.length(); i += 2)
        c[i] = toupper(c[i]);
}

bool comprobarSecuencia(Pila<char> &P1, Pila<char> &P2, unsigned c)
{
    unsigned i;
    bool esValido;
    
    i = 0;
    
    while (i < c && P1.tope() + (i+1) == P2.tope() - i )
    {
        ++i;
        P1.pop();
        P2.pop();
    }
    
    esValido = i >= c ;
    
    return esValido;
}
