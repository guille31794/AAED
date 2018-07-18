//
//  colaPseudo.h
//  Aerodromo en Linea
//
//  Created by Guillermo Girón García on 21/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#ifndef colaPseudo_h
#define colaPseudo_h

#include <cassert>

template <typename T> class Bicola
{
public:
    explicit Bicola(size_t TamaMax); // constructor, requiere ctor. T()
    Bicola(const Bicola<T>& C); // ctor. de copia, requiere ctor. T()
    Bicola<T>& operator =(const Bicola<T>& C); // asig. colas, req. T()
    bool vacia() const;
    bool llena() const; // Requerida por la implementación
    const T& frente() const;
    const T& tope() const;
    void pop();
    void push(const T& x);
    void popInv(); //Elimina por el final
    void pushInv(const T &x); //Inserta por el comienzo
    ~Bicola(); // destructor
    
private:
    T *elementos; // vector de elementos
    unsigned long Lmax; // tamaño del vector
    int fin; // posición del último
};

template <typename T>
inline Bicola<T>::Bicola(size_t TamaMax) :
    elementos(new T[TamaMax]),
    Lmax(TamaMax),
    fin(-1)
{}

template <typename T>
Bicola<T>::Bicola(const Bicola<T>& C) :
    elementos(new T[C.Lmax]),
    Lmax(C.Lmax),
    fin(C.fin)
{
    for (int i = 0; i <= fin; i++) // copiar el vector
        elementos[i] = C.elementos[i];
}

template <typename T>
Bicola<T>& Bicola<T>::operator =(const Bicola<T>& C)
{
    if (this != &C)
    {
        // evitar autoasignación
        // Destruir el vector y crear uno nuevo si es necesario
        
        if (Lmax != C.Lmax)
        {
            delete[] elementos;
            Lmax = C.Lmax;
            elementos = new T[Lmax];
        }
        
        // Copiar el vector
        
        fin = C.fin;
        
        for(int i = 0; i <= fin ; i++)
            elementos[i] = C.elementos[i];
    }
    
    return *this;
}

template <typename T>
inline bool Bicola<T>::vacia() const
{
    return (fin == -1);
}

template <typename T>
inline bool Bicola<T>::llena() const
{
    return (fin == Lmax - 1);
}

template <typename T>
inline const T& Bicola<T>::frente() const
{
    assert(!vacia());
    return elementos[0];
}

template <typename T>
inline const T& Bicola<T>::tope() const
{
    assert(!vacia());
    return elementos[fin];
}

template <typename T>
void Bicola<T>::pop()
{
    assert(!vacia());
    
    for (int i = 0; i < fin; i++)
        elementos[i] = elementos[i+1];
    
    fin--;
}

template <typename T>
void Bicola<T>::popInv()
{
    assert(!vacia());

    fin--;
}

template <typename T>
inline void Bicola<T>::push(const T& x)
{
    assert(!llena());
    fin++;
    elementos[fin] = x;
}

template <typename T>
inline void Bicola<T>::pushInv(const T &x)
{
    assert(!llena());
    
    fin++;
    
    for(int i = 0; i < fin; ++i)
    {
        elementos[i+1] = elementos[i];
    }
    
    elementos[0] = x;
    
}

template <typename T>
inline Bicola<T>::~Bicola()
{
    delete[] elementos;
}

#endif /* colaPseudo_h */
