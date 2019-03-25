//
//  postfijo.cpp
//  test
//
//  Created by Guillermo Girón García on 04/02/2019.
//  Copyright © 2019 Guillermo Girón García. All rights reserved.
//

#include <iostream>
#include "../pilaEnla.hpp"
#include "../listaEnla.hpp"
#include <cstring>

using namespace std;

typedef struct variable
{
    explicit variable(int v = 0, char c = '\0'): value{v}, var{c} {}
    explicit variable(char c): value{0}, var{c} {}
    const int value;
    const char var;
} variable;

bool operator ==(const variable& v1, const variable& v2)
{
    return v1.var == v2.var;
}

int compute(const char* postfijo, const Lista<variable>& L)
{
    Pila<int> P;
    Lista<variable>::posicion p;
    
    for (int i = 0; i < strlen(postfijo); ++i)
    {
        if (isalpha(postfijo[i])) 
        {
            p = L.buscar(variable{postfijo[i]});
            P.push(L.elemento(p).value);    
        }
        else
        {
            int term2 = P.tope();
            P.pop();
            int term1 = P.tope();
            P.pop();
            switch (postfijo[i])
            {
                case '+': P.push(term1 + term2);
                        break;
                case '-': P.push(term1 - term2);
                    break;
                case '*': P.push(term1 * term2);
                    break;
                case '/': P.push(term1 / term2);
                    break;
            }   
        }    
    }
    
    return P.tope();
}

int main()
{
    Lista<variable> L;
    Lista<variable>::posicion p = L.primera();

    L.insertar(variable{3, 'A'}, p);
    p = L.siguiente(p);
    L.insertar(variable{2, 'B'}, p);
    p = L.siguiente(p);
    L.insertar(variable{4, 'C'}, p);

    cout << "ABC+* -> The result is: " << compute((char*)"ABC+*", L) << endl;
}
