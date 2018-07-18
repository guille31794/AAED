//
//  colaEnla.hpp
//  TAD Cola circular
//
//  Created by Guillermo Girón García on 1/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef colaEnla_hpp
#define colaEnla_hpp

#include <cassert>

template <typename T>
class Cola
{
    Bicola<T> B;
    
    void copiar(const Cola<T> &C);
    
public:
    Cola(); //Constructor
    Cola(const Cola<T> &C); //Constructor de copia
    Cola<T> &operator = (const Cola<T> &C); //Asignacion d colas
    bool vacia() const;
    const T &frente() const;
    void pop();
    void push(const T &x);
    ~Cola();    //destructor
};

//Metodo privado

template <typename T>
void Cola<T>::copiar(const Cola<T> &C)
{
    B = C.B;
}

template <typename T>
inline Cola<T>::Cola() : B()
{}

template <typename T>
inline Cola<T>::Cola(const Cola<T> &C) : B()
{
    copiar(B);
}

template <typename T>
inline Cola<T> &Cola<T>::operator = (const Cola<T> &C)
{
    //Evitar autoasignacion
    
    if (this != &C)
    {
        //Vaciar la cola actual
        
        this ->~Cola();
        copiar(C);
    }
    
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return (B.vacia());
}

template <typename T>
inline const T &Cola<T>::frente() const
{
    assert(!vacia());
    
    return B.frente();
}

template <typename T>
inline void Cola<T>::pop()
{
    B.pop();
}

template <typename T>
inline void Cola<T>::push(const T &x)
{
    B.push(x);
}

//Destructor: vacia la cola

template <typename T>
Cola<T>::~Cola()
{
    B.~Bicola();
}

#endif /* colaEnla_hpp */
