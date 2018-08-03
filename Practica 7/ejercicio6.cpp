#include <iostream>
#include <ctime>
#include <cstdlib>
#include "listaEnla.hpp"

using namespace std;

/*
  Consideramos conjunto a una agrupacion de elementos del mismo tipo
  considerada como un objeto. Dichos elementos han de ser disntintos entre switch
  y no se pueden repetir. Lo almacenamos en celdas enlazadas de manera que
  el primer un elemento de un conjunto siempre apunta a un siguiente o fin, y a
  un anterior o inicio.

  C1 = {x, y, z, r} o C2 = {1, 2, 3, 4}

  Para su construccion mediante celdas enlazadas, utilizare la
  implementacion del tad lista mediante celdas enlazadas.

  Operaciones utilizadas del tad lista:

  Operaciones del tad Conjunto:

  void()
    Postcondiciones: devuelve si un conjunto contiene algun elemento.
    devuelve verdadero si esta vacio y falso si contiene al menos un elemento.

  insertElement(const T&)
    Postcondiciones: inserta un elemento e en la posicion anterior a la ultima
    del conjunto en caso de que este no este vacio, o en la primera posicion si
    esta vacio. Si el elemento a insertar ya existe en el conjunto, no se hace
    nada.

  eraseElement(const T&)
    Precondiciones: conjunto no vacio.
    Postcondiciones: quita el elemento del conjunto en caso de que este
    pertenezca al mismo. Si no pertece, no hace nada.

  union()
    Postcondiciones: Dados dos conjuntos A y B, devuelve un nuevo conjunto con
    los elementos pertenecientes a A, a B o ambos. En el caso de que ninguno de
    los conjuntos tenga elementos, devuelve el vacio.

  intersect()
    Postcondiciones: dados dos conjuntos A y B, devuelve un nuevo conjunto
    unicamente con los elementos que pertenecen a ambos conjuntos. En el caso de
    que no existan elementos comunes en ambos conjuntos, devuelve el vacio.

  difference()
    Postcondiciones: dados dos conjuntos A y B, devuelve un nuevo conjunto con
    los elementos pertenecientes a A, y que ademas no se encuentran en B. En el
    caso de que no existan elementos que cumplan dicha condicion, devuelve el
    conjunto vacio.
*/


template<typename T>
class Conjunto
{
  public:
    bool cVoid();
    void insertElement(const T&);
    void eraseElement(const T&);
    Conjunto cUnion(const Conjunto<T>&);
    Conjunto intersect(const Conjunto<T>&);
    Conjunto difference(const Conjunto<T>&);

  private:
    Lista<T> L;
};


template<typename T>
bool Conjunto<T>::cVoid()
{
  bool cVoid;

  if(L.primera() -> elemento())
    cVoid = false;
  else
    cVoid = true;

  return cVoid;
}

template<typename T>
void Conjunto<T>::insertElement(const T& e)
{
    typename Lista<T>::posicion p = L.buscar(e);

    if(p != L.fin())
    {
      p = L.anterior(L.fin());

      L.insertar(e, p);
    }
}

template<typename T>
void Conjunto<T>::eraseElement(const T& e)
{
  typename Lista<T>::posicion p = L.buscar(e);

  if(p != L.fin())
    L.eliminar(p);
}

template<typename T>
Conjunto<T> Conjunto<T>::cUnion(const Conjunto<T>& B)
{
  Conjunto<T> C;

  typename Lista<T>::posicion p = L.primera();

  while(p != L.fin())
  {
    C.insertElement(L.elemento(p));
    p = L.siguiente(p);
  }

  p = B.L.primera();

  while(p != B.L.fin())
  {
    C.insertElement(B.L.elemento(p));
    p = B.L.siguiente(p);
  }

  return C;
}

template<typename T>
Conjunto<T> Conjunto<T>::intersect(const Conjunto<T>& B)
{
  Conjunto<T> C;

  typename Lista<T>::posicion p = L.primera();

  while(p != L.fin())
  {
    if(B.L.buscar(L.elemento(p)) != B.L.fin())
      C.insertElement(L.elemento(p));

    p = L.siguiente(p);
  }

  return C;
}

template<typename T>
Conjunto<T> Conjunto<T>::difference(const Conjunto<T>& B)
{
  Conjunto<T> C;

  typename Lista<T>::posicion p = L.primera();

  while(p != L.fin())
  {
    if(B.L.buscar(L.elemento(p)) == B.L.fin())
      C.insertElement(L.elemento(p));

    p = L.siguiente(p);
  }

  return C;
}

int main()
{
  Conjunto<unsigned> A, B, C;

  srand(time(NULL));

  for (int c = 0; c < 5; ++c)
  {
    A.insertElement(rand() % 20 + 1);
    B.insertElement(rand() % 20 + 1);
  }

  C = A.cUnion(B);

  return 0;
}
