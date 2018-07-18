//
//  main.cpp
//  Solitario de las 2 cartas
//
//  Created by Guillermo Girón García on 9/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "carta.hpp"
#include "juego.h"
#include <algorithm>

int main(int argc, const char * argv[])
{
    tCarta baraja[40];
    tfig base[4];
    
    // Generar las 40 cartas de la baraja española.
    
    for (int i = 0, p = OROS; p <= BASTOS; p++)
        for (int f = AS; f <= REY; f++, i++)
            baraja[i] = tCarta(tpalo(p), tfig(f));
    
    //srand(time(0));
    
    bool victoria = false;
    int partidas = 0;
    do
    {
        random_shuffle(baraja, baraja+40); // Barajar las cartas
        victoria = solitario(baraja, base); // Jugar
        
        // Mostrar resultado
        
        cout << "Partidas␣jugadas␣=␣" << ++partidas << endl;
        cout << "Últimas␣cartas␣colocadas:\n"
        << "\t" << tCarta(OROS, base[OROS]) << endl
        << "\t" << tCarta(COPAS, base[COPAS]) << endl
        << "\t" << tCarta(ESPADAS, base[ESPADAS]) << endl
        << "\t" << tCarta(BASTOS, base[BASTOS]) << endl
        << endl;
    } while (!victoria); // Parar al ganar una partida.
    
    cout << "¡Conseguido!␣Bien␣hecho.\n" << endl;

    return 0;
}
