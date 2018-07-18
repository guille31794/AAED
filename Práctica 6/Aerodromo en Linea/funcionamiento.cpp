//
//  funcionamiento.cpp
//  Aerodromo en Linea
//
//  Created by Guillermo Girón García on 22/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "funcionamiento.hpp"
#include "aerodromo.hpp"

void inicializaAvion(avioneta a[])
{
    a[0].matricula = "12345L";
    a[1].matricula = "12345A";
    a[2].matricula = "12345B";
    a[3].matricula = "12345C";
    a[4].matricula = "12345D";
    a[5].matricula = "12345E";
    a[6].matricula = "12345F";
    a[7].matricula = "12345G";
    a[8].matricula = "12345H";
    a[9].matricula = "12345I";
    a[10].matricula = "12345J";
    a[11].matricula = "12345K";
}

void muestraMatriculas(avioneta a[])
{
    unsigned i;
    
    cout << a[0].matricula;
    
    for(i = 1; i < maxPlazas-1; ++i)
        cout << " || " << a[i].matricula ;
    
    cout << endl;
}

void muestraMatriculas(Bicola<avioneta> &A)
{
    Bicola<avioneta> mostrar(maxPlazas);
    
    mostrar = A;
    
    while (!mostrar.vacia())
    {
        cout << " || " << mostrar.frente().matricula ;
        mostrar.pop();
    }
    
    cout << endl;
}

void inline modAccion(char &a, char b)
{
    a = b;
}

void modPiloto(string &p, Bicola<avioneta> &A)
{
    unsigned i;
    Bicola<avioneta> aux(maxPlazas);
    bool encontrado = false;
    
    while(!encontrado)
    {
        muestraMatriculas(A);
        
        cout << "\rIntroduzca nueva matricula: ";
        cin >> p;
        cout << endl;
        
        for( i = 0; i < 11; ++i)
        {
            if( p == A.frente().matricula)
                encontrado = true;
            else
            {
                aux.push(A.frente());
                A.pop();
            }
        }
        
        if(encontrado)
            cout << "Piloto listo para maniobra. Esperando permiso..." << endl;
        else
            cout << "Error, compruebe la matricula." << endl;
    }
    
    while (!aux.vacia())
    {
        A.pushInv(aux.tope());
        aux.popInv();
    }
}

void modPiloto(string &p, avioneta a[])
{
    unsigned i;
    bool encontrado = false;
    
    while(!encontrado)
    {
        muestraMatriculas(a);
        
        cout << "\rIntroduzca nueva matricula: ";
        cin >> p;
        cout << endl;
        
        for( i = 0; i < maxPlazas-1; ++i)
        {
            if( p == a[i].matricula)
            {
                encontrado = true;
                 cout << "Piloto listo para maniobra. Esperando permiso..." << endl;
            }
        }
        
        if(!encontrado)
            cout << "Error, compruebe la matricula." << endl;
    }
}

void delay(int secs)
{
    for(int long i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void menu()
{
    Bicola<avioneta> Aerodromo(maxPlazas), aterrizaje(espacioAereo);
    avioneta a[maxPlazas];
    char accion;
    int t;
    unsigned op;
    string piloto;  //En esta cadena se guadará la matricula del piloto que quiera despegar
    
    inicializaAvion(a);
    
    op = 0;
    t = 1;
    
    while (op != 3)
    {
        cout << "\rMenu aerodromo: " << endl;
        cout << "1.- Aterrizaje." << endl;
        cout << "2.- Despegue." << endl;
        cout << "3.- Salir." << endl;
        cout << "Introduzca opcion: ";
        cin >> op;
        cout << endl;
    
    
        switch (op)
        {
            case 1: modPiloto(piloto, a);
                    modAccion(accion, 'A');
                
                    if(estacionamiento(Aerodromo, a, accion, piloto))
                        cout << "Aterrizaje de " << Aerodromo.frente().matricula << " conseguido" << endl;
                    else
                    {
                        cout << "Imposible tomar tierra. Añadido a la cola de aterrizaje" << endl;
                        //aterrizaje.push(a[posicion]);
                    }
                
                    break;
                
            case 2: modPiloto(piloto, Aerodromo);
                    modAccion(accion, 'D');
                
                    if(despegue(Aerodromo, a, accion, piloto))
                        cout << "Feliz vuelo " << endl;
                    else
                        cout << "Estado de excepcion, imposible despegar" << endl;
            case 3: cout << "\rCerrando sesion..." << endl;
                    delay(t);
                    cout << "Hasta luego" << endl;
                    break;
            default:    cout << "Error, repita la operacion, por favor" << endl;
                    break;
        }
    }
}
