//
//  carta.cpp
//  Solitario de las 2 cartas
//
//  Created by Guillermo Girón García on 9/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "carta.hpp"

const char* tCarta::nom_palo[] =
{"OROS   ", "COPAS  ", "ESPADAS", "BASTOS "};

const char* tCarta::nom_fig[] =
{"-------", "AS     ", "DOS    ", "TRES   ",
    "CUATRO ", "CINCO  ", "SEIS   ", "SIETE  ",
    "SOTA   ", "CABALLO", "REY    "};

std::ostream& operator <<(std::ostream& os, const tCarta& c)
{
    os << "(" << tCarta::nom_fig[c.fig()]
    << ",␣" << tCarta::nom_palo[c.palo()] << ")";
    return os;
}

