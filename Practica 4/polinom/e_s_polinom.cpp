#include <iostream>
#include "e_s_polinom.h"
//#include "polinom.h"
#include "polinomio.hpp"

int introducirGrado()
{
    int grado = 0;
    
    while(grado > gradoMax || grado < 1)
        {
            cout << "Introduzca el grado <= " << gradoMax << endl;
            cin >> grado;
        }
    
    return grado;
}

void introducirCoeficientes(polinomio &p, int g)
{
    double coeficiente;
    int i = 0;

    while (i <= g)
    {
        cout << "\rIntroduzca el coeficiente " << i << ": " << endl;
        cin >> coeficiente;
        p.coeficiente(i, coeficiente);
        ++i;
    }
}

void introducirPolinomio(polinomio &p1, polinomio &p2)
{
    // Una llamada a cada funcion pora cada polinomio en los parametros
    
    int grado = introducirGrado();
    
    introducirCoeficientes(p1, grado);
    
    grado = introducirGrado();
    
    introducirCoeficientes(p2, grado);
}

void suma(const polinomio &polinomio1, const polinomio &polinomio2)
{
    polinomio p(gradoMax);
    int i = 0;
    
    while(i <= gradoMax)
    {
        p.coeficiente(i, (polinomio1.coeficiente(i) + polinomio2.coeficiente(i)));
        cout << p.coeficiente(i) << " x^" << i;
        if(i < gradoMax)
            cout << " + " ;

        ++i;
    }
    
    cout << endl;
}

void resta(polinomio const &p1, polinomio const &p2)
{
    polinomio p(gradoMax);
    int i = 0;
    
    while(i <= gradoMax)
    {
        p.coeficiente(i, (p1.coeficiente(i) - p2.coeficiente(i)));
        cout << p.coeficiente(i) << " x^" << i;
        if(i < gradoMax)
            cout << " + " ;

        ++i;
    }
    
    cout << endl;
}

void producto(polinomio const &p1, polinomio const &p2)
{
    polinomio p(gradoMax + gradoMax);
    int i, j;
    double prodCoef, coef1, coef2;
    
    for (i = 0; i <= gradoMax; ++i)
    {
        for ( j = 0; j <= gradoMax; ++j)
        {
            coef1 = p1.coeficiente(i);
            coef2 = p2.coeficiente(j);
            prodCoef = coef1 * coef2;
            p.coeficiente(i+j, p.coeficiente(i+j) + prodCoef);
        }
    }
    
    i = 0;
    
    while (i <= gradoMax + gradoMax)
    {
        cout << p.coeficiente(i) << " x^" << i;
        if(i < gradoMax + gradoMax)
            cout << " + ";
        ++i;
    }
    cout << endl;
}

void derivada(polinomio const &p1, polinomio const &p2)
{
    polinomio p(gradoMax);
    int i;
    
    for( i = 0; i <= gradoMax; ++i)
    {
        p.coeficiente(i, p1.coeficiente(i) * i);
    }
    
    i = 0;
    
    while (i <= gradoMax)
    {
        if(i > 0)
        {
            cout << p.coeficiente(i) << " x^" << i-1;
            if(i < gradoMax)
            cout << " + ";
        }
        
        ++i;
    }
    cout << endl;
        
}
