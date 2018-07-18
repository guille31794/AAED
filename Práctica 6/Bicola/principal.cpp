//
//  principal.cpp
//  Bicola
//
//  Created by Guillermo Girón García on 4/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "opBicola.hpp"

int main()
{
    Bicola<unsigned> B1, B2;
    
    elemAPila(B1);
    imprPila(B1);
    
    B1.~Bicola();
    
    elemACola(B2);
    imprCola(B2);
    
    B2.~Bicola();
    
    return 0;
}
