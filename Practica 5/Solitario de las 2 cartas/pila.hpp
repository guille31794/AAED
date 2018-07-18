//
//  pila.hpp
//  TAD Pila
//
//  Created by Guillermo Girón García on 23/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef pila_hpp
#define pila_hpp

#include <iostream>
#include <cassert>

template <typename tElemento>
class Pila
{
    tElemento *elementos;   //Vector de elementos
    int Lmax;   //Tamaño del vector
    int tope_;   //Posición del tope
    
public:
    explicit Pila(unsigned TamaMax); //Constructor, requiere constructor de tipo elemento "tElemento()" no implicito
    Pila(const Pila &P); //Constructor de copia
    Pila &operator = (const Pila &P); //Asignación entre pilas
    bool vacia() const;
    bool llena() const; //Requerida por la implementación
    const tElemento &tope() const;
    void pop();
    void push (const tElemento &x);
    ~Pila(); //Destructor
};

template < typename tElemento >
inline Pila< tElemento > :: Pila( unsigned TamaMax ) :
    elementos ( new tElemento[TamaMax] ),
    Lmax( TamaMax ),
    tope_( -1 )
{}

template < typename tElemento >
Pila < tElemento > :: Pila(const Pila < tElemento > &P) :
    elementos(new tElemento[P.Lmax]),
    Lmax(P.Lmax),
    tope_(P.tope_)
{
    int i;
    
    for (i = 0; i <= tope_; ++i)
    {
        elementos[i] = P.elementos[i];
    }
}

template < typename tElemento >
Pila < tElemento > &Pila < tElemento > :: operator = (const Pila < tElemento > &P)
{
    if (this != &P) //Evitar autoasignación
    {
        if ( Lmax != P.Lmax ) //Destruir el vector y crear uno nuevo si es necesario
        {
            delete [] elementos;
            Lmax = P.Lmax;
            elementos = new tElemento[Lmax];
        }
        
        //Copiar el vector
        
        int i;
        tope_ = P.tope_;
        
        for (i = 0; i <= tope_; ++i)
        {
            elementos[i] = P.elementos[i];
        }
        
    }
    
    return *this;
}
    

template < typename tElemento >
inline bool Pila <tElemento > :: vacia() const
{
    return (tope_ == -1);
}

template < typename tElemento >
inline bool Pila <tElemento >:: llena() const
{
    return (tope_ == Lmax - 1);
}

template < typename tElemento >
inline const tElemento &Pila <tElemento > :: tope() const
{
    assert(!vacia());
    return elementos[tope_];
}

template <typename tElemento >
inline void Pila < tElemento > :: pop()
{
    assert(!vacia());
    --tope_;
}

template <typename tElemento >
inline void Pila < tElemento > :: push(const tElemento &x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

template < typename tElemento >
inline Pila < tElemento >:: ~Pila()
{
    delete [] elementos;
}

#endif /* pila_hpp */
