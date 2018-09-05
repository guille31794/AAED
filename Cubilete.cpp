#include <iostream>
#include <pilaDinamica.hpp>

/*
  Un cubo es  cuerpo formado por seis caras que son cuadradas. La particularidad
  de estos cuerpos es que todas las caras son simetricas, están dispuestas de
  forma paralela y de a pares, y tienen cuatro lados. Una de las caras es hueca.
  Todo cubo cuenta con un tamaño invariable definido por el tamaño de una de sus
  aristas, y puede colocarse en 8 posiciones distintas, que pueden resumirse en
  cubo cuya cara opuesta se situe más arriba en la pila, es el que puede
  considerarse en el tope. Dicha relación será expresada en función del tamaño
  del cubo. Para realizar el juego utilizaré el tad Pila en su representación
  mediante celdas enlazadas, cuya especificación podreís encontrar en la teoría
  del tema 5 en el campus virtual.

  Operaciones:

  tCubo(entero, entero)
  Precondicion: recibe dos enteros como parametros o 1 en el caso por defecto.
  Postcondición: crea un cubo con un tamaño correspondiente al primer entero,
  siempre igual o mayor a 1, y otro entero que es la  posición, que si es 0 es
  boca abajo y si es mayor que 0, es bocarriba.

  entero tam()
  Postcondición: devuelve el tamaño del cubo.

  entero pos()
  Postcondición: devuelve la posición del cubo.

  procedimiento vuelta()
  Postcondición: cambia la posición del cubo. Si es 0 a 1. Si es mayor que 0, lo
  cambia a 0.
*/

class tCubo
{
  public:
    tCubo(const unsigned 1, const unsigned 1);
    unsigned tam();
    unsigned pos();
    void vuelta();

  private:
    unsigned tam, pos;
}

Pila<tCubo> juego(Pila<tCubo>& P1)
{
  Pila<tCubo> P2, P3;

  return P2;
}
