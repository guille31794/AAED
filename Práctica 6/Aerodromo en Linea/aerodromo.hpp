//
//  aerodromo.hpp
//  Aerodromo en Linea
//
//  Created by Guillermo Girón García on 21/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#ifndef aerodromo_hpp
#define aerodromo_hpp

#include "BicolaPseudo.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

const unsigned long maxPlazas = 12;
const unsigned long espacioAereo = 15;

struct avioneta
{
    string matricula;
    char accion = 'N';  //Por defecto una avioneta no realiza ninguna acción
};

/*
 Cabecera: (Cola<avioneta> &Aerodromo, avioneta &a, const char &accion)
 Precondicion: aerodromo no completo, y accion == 'A'
 Postcondicion: devuelve verdadero y aterriza en la zona más cercana a la salida posible
 */

bool estacionamiento(Bicola<avioneta> &Aerodromo, avioneta a[], const char &accion, string &p);

/*
 Cabecera: (Cola<avioneta> &Aerodromo, avioneta &a, const char &accion)
 Precondicion: accion == 'D'
 Postcondicion: retira esa avioneta del aerodromo y devuelve verdadero
 */

bool despegue(Bicola<avioneta> &Aerodromo, avioneta a[], const char &accion, string &p);

#endif /* aerodromo_hpp */
