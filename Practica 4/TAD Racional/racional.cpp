//
//  racional.cpp
//  TAD Racional
//
//  Created by Guillermo Girón García on 20/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include <cassert>
#include <cstdlib>
#include <cmath>
#include "racional.hpp"


racional::racional(long nu, long de) : n(nu), d(de)
{
    assert(d != 0); //Interrumpe la ejecución si la sentencia no es veraz
    
    if( n == 0)
        d = 1;
    else
    {
        if(d < 0) //Pasa los signos negativos del denominador al numerador
        {
            n = -n;    //Oportunidad para aplicar la sobrecarga -=
            d = -d;
        }
        
        //Reduce fracción
        
        long m = mcd(abs(n), d);
        if (m != 1)
        {
            n /= m;
            d /= m;
        }
    }
}

//Sobrecarga de operadores externa

racional operator +(const racional &r, const racional &s)
{
    long m = racional::mcd(r.d, s.d);
    return racional(s.d / m * r.n + r.d / m * s.n, racional::mcm(r.d, s.d));
}

racional operator -(const racional &r)
{
    racional s; //Racional 0/1
    
    if (r.n != 0)
    {
        s.n = -r.n;
        s.d = r.d;
    }
    
    return s;
}

racional operator *(const racional &r, const racional &s)
{
    racional t; //Racional 0/1
    
    if(r.n && s.n)
    {
        long a = racional::mcd(abs(r.n), s.d);
        long b = racional::mcd(r.d, abs(s.n));
        t.n = (r.n / a) * (s.n / b);
        t.d = (r.d / b) * (s.d / a);
    }
    
    return t;
}

//TO DO: añadir el resto de operadores

racional operator +(const racional &r)
{
    racional s; //Racional 0/1
    
    if (r.n != 0)
    {
        s.n = abs(r.n);
        s.d = abs(r.d);
    }
    
    return s;
}

racional operator -(const racional &r, const racional &s)
{
    long m = racional::mcd(r.d, s.d);
    
    return racional(s.d / m * s.n - r.d / m * r.n, racional::mcm(s.d, r.d) ); // Posible fallo
}

racional operator /(const racional &r, const racional &s)
{
    racional t; //Racional 0/1
    racional i = inv(s);    //Posible equivocación
    
    if(r.n && i.n)
    {
        long a = racional::mcd(abs(r.n), i.d);
        long b = racional::mcd(r.d, abs(i.n));
        t.n = (r.n / a) * (i.n / b);
        t.d = (r.d / b) * (i.d / a);
    }
    
    return t;
}

racional operator +=(const racional &r, const racional &s)
{
    
}

//Metodos de clase

racional inv(const racional &r)
{
    racional s;
    
    assert(r.n != 0);   //Comprobación de la precondición
    
    if(r.n > 0)
    {
        s.n = r.d;
        s.d = r.n;
    }
    
    return s;
}

//Metodos privados

inline long racional::mcm(long x, long y)
{
    return x / (mcd(x,y) * y);
}

long racional::mcd(long x, long y)
{
    long a;
    
    //Algoritmo de Euclides
    
    if (x < y)
    {
        a = x;
        x = y;
        y = a;
    }
    
    while ((a = x % y))
    {
        x = y;
        y = a;
    }
    
    return y;
}
