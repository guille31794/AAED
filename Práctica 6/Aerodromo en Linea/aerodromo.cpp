//
//  aerodromo.cpp
//  Aerodromo en Linea
//
//  Created by Guillermo Girón García on 21/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "aerodromo.hpp"


bool estacionamiento(Bicola<avioneta> &Aerodromo, avioneta a[], const char &accion, string &p)
{
    unsigned i;
    bool aparcao;
    
    aparcao = true;
    i = 0;
    
    while (i < maxPlazas-1 && p != a[i].matricula )
    {

        if(accion == 'A' && !Aerodromo.llena())
        {
            a[i].accion = 'A';
            Aerodromo.push(a[i]);
        }
        else
        {
            aparcao = false;
            //cout << "Falsamente aparcao" << endl;
        }
        
        ++i;
    }
    
    a[i-1].matricula = "vacio";
    a[i-1].accion = 'v';
    
    return aparcao;
}

bool despegue(Bicola<avioneta> &Aerodromo, avioneta a[], const char &accion, string &p)
{
    Bicola<avioneta> aux(maxPlazas);
    bool d;
    unsigned i;
    
    d = false;
    i = 0;
    
    while (a[i].matricula != "vacio")
    {
        ++i;
    }
    
    if(
        && !Aerodromo.vacia())
    {
    
    if(accion == 'D' )
    {
        while (Aerodromo.frente().matricula != p && !Aerodromo.vacia())
        {
            aux.push(Aerodromo.frente());
            Aerodromo.pop();
        }
        
        if(Aerodromo.frente().matricula == p)
        {
            a[i] = Aerodromo.frente();
            a[i].accion = 'D';
        }
        
        while (!aux.vacia())
        {
            Aerodromo.pushInv(aux.frente());
            aux.popInv();
        }
        
        d = true;
    }}
    
    return d;
}
