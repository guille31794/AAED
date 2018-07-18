//
//  funcionamiento.hpp
//  Aerodromo en Linea
//
//  Created by Guillermo Girón García on 22/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#ifndef funcionamiento_hpp
#define funcionamiento_hpp

#include "aerodromo.hpp"
#include <ctime>

/*
 Cabecera: (avioneta a[])
 Precondicion: vector avioneta declarada
 Postcondicion: crea una matricula a cada avioneta
 */

void inicializaAvion(avioneta a[]);

/*
 Cabecera: (char &a)
 Precondicion:
 Postcondicion: devuelve la accion a ejecutar por las avionetas
 */

void inline modAccion(char &a, char b);

/*
 Cabecera: (string &p, avioneta a[])
 Precondicion: piloto declarado
 Postcondicion: asigna una matricula a un piloto
 */

void modPiloto(string &p, Bicola<avioneta> &A);

/*
 Cabecera: (unsigned &op)
 Precondicion:
 Postcondicion: realiza la accion solicitada por teclado
 */

void menu();

/*
 Cabecera: (Bicola<avioneta> &A) o (avioneta a[])
 Precondicion:
 Postcondicion: muestra por pantalla todas las avionetas disponibles para el despegue
 */

void muestraMatriculas(Bicola<avioneta> &A);

void muestraMatriculas(avioneta a[]);

/*
 Cabecera: (clock_t sec)
 Precondicion:
 Postcondicion: produce un retardo especificado por el usuario en tiempo de implementacion
 */

void delay(int secs);

#endif /* funcionamiento_hpp */
