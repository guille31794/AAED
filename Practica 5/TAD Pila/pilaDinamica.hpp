//
//  pilaDinamica.hpp
//  TAD Pila
//
//  Created by Guillermo Girón García on 24/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef pilaDinamica_hpp
#define pilaDinamica_hpp

class Pila
{
public:
    typedef int tElemento;
    explicit Pila ( unsigned TamaMax); //Constructor
    Pila ( const Pila &P); //Constructor de copia
    Pila &operator = (const Pila &P); //Asignación entre pilas
    bool vacia() const;
    bool llena() const; //Requerida por la implementación
    const tElemento &tope() const;
    void pop();
    void push(const tElemento &x);
    ~Pila(); //Destructor
    
private:
    tElemento *elementos; // Vector de elementos
    int Lmax; //Tamaño del vector
    int tope_; //posición del tope
    
};

#endif /* pilaDinamica_hpp */
