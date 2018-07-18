//
//  polinomio.cpp
//  TAD Polinomio
//
//  Created by Guillermo Girón García on 17/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "polinomio.hpp"

class polinomio
{
private:
    
    //Variables de clase
    
    int g;
    double v[];
    
public:
    
    //Constructor
    
    polinomio (int gradoMax);
    
    //Observador / Consultor
    
    void imprimir();
    void imprimirP();
    unsigned grado();
    double coeficiente(unsigned n);
    
    //Modificador
    
    void setC(double c, unsigned grado);
    void setG(unsigned grado);
    
    //Sobrecarga de operadores
    
    friend polinomio operator +(const polinomio &p1, const polinomio &p2);
    friend polinomio operator -(const polinomio &p1, const polinomio &p2);
    friend polinomio operator *(const polinomio &p1, const polinomio &p2);
    
};

polinomio::polinomio( int gradoMax) : g(gradoMax)
{
    int i;
    
    for( i = 0; i < g; ++i)
        v[i] = 0;
}

polinomio operator +(const polinomio &p1, const polinomio &p2)
{
    polinomio p(gradoM);
    int i = 0;
        
    while(i <= gradoM)
    {
        p.v[i] = p1.v[i] + p2.v[i];
            
        ++i;
    }
    
    return p;
}

polinomio operator -(const polinomio &p1, const polinomio &p2)
{
    polinomio p(gradoM);
    int i = 0;
    
    while(i <= gradoM)
    {
        p.v[i] = p1.v[i] - p2.v[i];
      
        ++i;
    }
    
    return p;
}

polinomio operator *(const polinomio &p1, const polinomio &p2)
{
    polinomio p(gradoM + gradoM);
    int i, j;
    double prodCoef, coef1, coef2;
    
    for (i = 0; i <= gradoM; ++i)
    {
        for ( j = 0; j <= gradoM; ++j)
        {
            coef1 = p1.v[i];
            coef2 = p2.v[j];
            prodCoef = coef1 * coef2;
            p.v[i+j] = p.v[i+j] + prodCoef;
        }
    }
   
    return p;
}

void polinomio::imprimir()
{
    int i;
    
    for(i = 0; i < g; ++i)
    {
        cout << v[i] << " x^" << i;
        if(i < gradoM)
        cout << " + " ;
    }
    
    cout << endl;
}

void polinomio::imprimirP()
{
    int i;
    
    for( i = 0; i < g; ++i)
    {
        cout << v[i] << " x^" << i;
        if(i < gradoM + gradoM)
            cout << " + ";
    }
    
    cout << endl;
}

unsigned polinomio::grado()
{
    return g;
}

void polinomio::setC(double c, unsigned int grado)
{
    v[grado] = c;
}

void polinomio::setG(unsigned int grado)
{
    g = grado;
}

double polinomio::coeficiente(unsigned n)
{
    return v[n];
}
