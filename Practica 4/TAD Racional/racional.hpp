//
//  racional.hpp
//  TAD Racional
//
//  Created by Guillermo Girón García on 20/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef racional_hpp
#define racional_hpp

#include <iostream>
#include <cmath>

class racional
{
private:
    
    //Variables de clase
    
    long n, d;
    
    //Metodos de clase
    
    static long mcd(long, long);
    static long mcm(long, long);
    
public:
    
    //Constructor
    
    racional(long nu = 0, long de = 1);
    
    //Observadores / consultores
    
    long num() const { return n;};
    long den() const { return d;};
    
    //Sobrecarga de operadores externa
    
    friend racional operator +(const racional &r, const racional &s);
    friend racional operator -(const racional &r); //Opuesto
    friend racional operator *(const racional &r, const racional &s);
    friend racional inv(const racional &r);
    
    //Operadores sobrecargados del enunciado
    
    friend racional operator +(const racional &r); //Positivo
    friend racional operator -(const racional &r, const racional &s);
    friend racional operator /(const racional &r, const racional &s);
    friend racional operator +=(const racional &r, const racional &s);
    friend racional operator -=(const racional &r, const racional &s);
    friend racional operator *=(const racional &r, const racional &s);
    friend racional operator /=(const racional &r, const racional &s);
};

// Sobrecarga de operadores externa externa

inline bool operator ==(const racional &r, const racional &s)
{
    return (r.num() == s.num()) && (r.den() == s.den());
}

inline bool operator <(const racional &r, const racional &s)
{
    return racional(r + -s).num() < 0;
}

//TO DO: añadir operacione de comparación faltantes



#endif /* racional_hpp */
