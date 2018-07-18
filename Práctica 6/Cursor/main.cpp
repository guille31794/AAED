//
//  main.cpp
//  Cursor
//
//  Created by Guillermo Girón García on 11/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "cursor.hpp"

int main(int argc, const char * argv[])
{
    Pila<char> P1{}, P2{};
    string c;
    
    cout << "Introduzca una cadena: ";
    getline(cin, c);
    cout << endl;
    
    stringAPila(c, P1);
    
    bucle(P1, P2);
    
    //imprPila(P1);
    
    //helpMenu();
    
    return 0;
}
