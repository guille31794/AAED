//
//  carta.hpp
//  Solitario de las 2 cartas
//
//  Created by Guillermo Girón García on 9/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#ifndef carta_hpp
#define carta_hpp

#include <iostream>

using namespace std;

enum tpalo {OROS, COPAS, ESPADAS, BASTOS};
enum tfig {VACIA, AS, DOS, TRES, CUATRO, CINCO,
    SEIS, SIETE, SOTA, CABALLO, REY};

class tCarta
{
public:
    tCarta(tpalo p = OROS, tfig f = AS) : palo_(p), fig_(f) {};
    
    tpalo palo() const
    {
        return palo_;
    };
    
    tfig fig() const
    {
        return fig_;
    };
    
    friend std::ostream& operator <<
    (std::ostream& os, const tCarta& c);
    
private:
    tpalo palo_;
    tfig fig_;
    static const char* nom_palo[], * nom_fig[];
};

#endif /* carta_hpp */
