//
//  pilaDinamica.cpp
//  TAD Pila
//
//  Created by Guillermo Girón García on 24/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "pilaDinamica.hpp"
#include <cassert>

//Constructor

Pila::Pila(unsigned TamaMax) :
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    tope_(-1)
{}

//Constructor de copia

Pila::Pila(const Pila &P) :
    elementos(new tElemento[P.Lmax]),
    Lmax(P.Lmax),
    tope_(P.tope_)
{
    int i;
    
    //Copiar el vector
    
    for (i = 0; i <= tope_; ++i)
    {
        elementos[i] = P.elementos[i];
    }
}

//Asignacion entre pilas

Pila &Pila::operator=(const Pila &P)
{
    //Evitar autoasignacion
    
    if(this != &P)
    {
        //Destruir el vector y crear uno nuevo si es necesario
        if(Lmax != P.Lmax)
        {
            delete [] elementos;
            Lmax = P.Lmax;
            elementos = new  tElemento[Lmax];
        }
        
        //Copiar el vector
        
        int i;
        tope_ = P.tope_;
        
        for (i = 0; i <= tope_; ++i)
        {
            elementos[i] = P.elementos[i];
        }
    }
        
        return  *this;
}

bool Pila::vacia() const
{
    return (tope_ == -1);
}

bool Pila::llena() const
{
    return (tope_ == Lmax - 1);
}

const Pila::tElemento &Pila::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}


void Pila::pop()
{
    assert(!vacia());
    --tope_;
}

void Pila::push(const tElemento &x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

//Destructor

Pila::~Pila()
{
    delete [] elementos;
}
