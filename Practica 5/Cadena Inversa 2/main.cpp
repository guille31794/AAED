//
//  main.cpp
//  Cadena Inversa 2
//
//  Created by Guillermo Girón García on 24/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include <iostream>
#include "comprobarCadenaInversa.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    Pila<char> P1{}, P2{};
    string cadena;
    
    cout << "\rIntroduzca su cadena: " << endl;
    cin >> cadena;
    
    if (comprobarAmpersand(cadena))
    {
        if (P1.vacia() && P2.vacia())
        {
            stringAPila(cadena, P1, P2);
        }
    }
    else
        cout << "Fallo en la localizacion de &" << endl;
    
    
    if(!P1.vacia() && !P2.vacia())
    {
        comprobarInversa(P1, P2, cadena);
    }
    else
        cout << "Error, saliendo del programa.." << endl;
    
    P1.~Pila();
    P2.~Pila();
    
    return 0;
}
