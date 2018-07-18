//
//  pila.hpp
//  TAD Pila con Bicola
//
//  Created by Guillermo Girón García on 11/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef pila_hpp
#define pila_hpp

#include <iostream>
#include "bicola.hpp"

template <typename T>
class Pila
{
    Bicola<T> B;
    
    void copiar(const Pila <T> &P);
    
public:
    Pila(); //Constructor
    ~Pila();    //Destructor
    Pila(const Pila<T> &P); //Constructor de copia
    Pila <T> &operator = (const Pila <T> &P); //Asignacion
    bool vacia() const;
    const T &tope() const;
    void pop();
    void push(const T &x);
};

template <typename T>
inline Pila<T>::Pila() : B()
{}

template <typename T>
Pila<T> ::Pila(const Pila<T> &P) : B()
{
    copiar(B);
}

template <typename T>
Pila<T> &Pila<T>::operator=(const Pila<T> &P)
{
    if(this != &P)
    {
        //Evitar autoasignacion
        this -> ~Pila();
        copiar(P);
    }
    
    return *this;
}

template <typename  T>
inline bool Pila<T>::vacia() const
{
    return (B.vacia());
}

template <typename T>
inline const T &Pila<T>::tope()const
{
    assert(!vacia());
    return B.tope();
}

template <typename T>
inline void  Pila<T>::pop()
{
    B.popInv();
}

template <typename T>
inline void Pila<T>::push(const T &x)
{
    B.push(x);
}

//Destructor de pila vacia

template <typename T>
Pila<T> ::~Pila()
{
    B.~Bicola();
}

template <typename T>
void Pila<T>::copiar(const Pila<T> &P)
{
    if (!P.vacia())
    {
        B = P.B;
    }
}

#endif /* pila_hpp */
