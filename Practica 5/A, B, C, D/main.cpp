//
//  main.cpp
//  A, B, C, D..
//
//  Created by Guillermo Girón García on 27/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include <iostream>
#include "ABCD.hpp"


using namespace std;

int main(int argc, const char * argv[])
{
    Pila<char> P1{}, P2{};
    string cadena;
    unsigned cont = 0;
    
    cout << "\rIntroduzca una cadena: " << endl;
    cin >> cadena;
    
    stringToMayus(cadena);
    
    if(comprobarAlmohadillas(cadena))
    {
        cont = stringAPila(cadena, P1, P2);
        
        if(comprobarSecuencia(P1, P2, cont))
            cout << "La cadena corresponde a la secuencia pedida";
        else
            cout << "La cadena no corresponde con la secuencia dada";
        
        cout << endl;
    }
    else
        cout << "Error, secuencia de datos inesperada" << endl;
    
    P1.~Pila();
    P2.~Pila();
    
    return 0;
}
