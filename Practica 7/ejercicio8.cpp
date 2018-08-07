#include <iostream>
#include "listaDoble.hpp"
#include <cstdlib>

/*
  Un numero binario se define como una secuencia de unos y ceros de la forma:

  bn, bn-1, ..., b1, b0 donde cada b es un digito con n >= 0 y que representan
  en el conjunto de los decimales el sumatorio desde i = 0 hasta n de bi * 2^i

  Para representarlo se utilizan todas las operaciones del tad lista doblemente
  enlazada.

  Las operaciones del tad binario son:

  Contructor:

  Binario()
    Precondicion: recibe una cadena de caracteres como parametro.
    Postcondicion: genera un numero binario a partir de una cadena de caracteres
    con unos y ceros. En caso de que la cadena contenga caracteres
    distintos de 1 y 0 , estos serán desechados. En caso de no existir ningún 1
    o 0, el numero resultante será el 0 binario.

  Operaciones Lógicas:

  NOT()
    Postcondición: devuelve un numero Binario como resultado de comparar
    terminos de iguales posiciones en ambos numeros binarios mediante una
    negación Lógica.

  AND()
    Precondicion: recibe un numero binario como parametro.
    Postcondicion: devuelve un numero Binario, resultado de comparar terminos de
    iguales posiciones en ambos numers binarios mediante una conjunción Lógica.
    En caso de que uno de los números tenga menor longitud que el otro, se le
    insertarán tantos 0's partiendo desde su bit más significativo como sea
    necesario para igualar las longitudes de ambos números.

  OR()
    Precondicion: recibe un numero bonario como parametro.
    Postcondicion: devuelve un numero Binario, resultado de comparar terminos de
    iguales posiciones en ambos numers binarios mediante una disyunción Lógica.
    En caso de que uno de los números tenga menor longitud que el otro, se le
    insertarán tantos 0's partiendo desde su bit más significativo como sea
    necesario para igualar las longitudes de ambos números.

  ORExclusivo()
    Precondicion: recibe un numero bonario como parametro.
    Postcondicion: devuelve un numero Binario, resultado de comparar terminos
    de iguales posiciones en ambos numers binarios mediante una disyunción
    exlclusiva Lógica. En caso de que uno de los números tenga menor longitud
    que el otro, se le insertarán tantos 0's partiendo desde su bit más
    significativo como sea necesario para igualar las longitudes de ambos
    números.

  Desplazamientos:

  Izquierda()
    Precondicion: recibe un numero de desplazamientos a realizar (n).
    Postcondicion: desplaza el numero binario tantas posiciones a la izquierda
    como indique el numero introducido como parametro, n, partiendo desde la
    posición del parametro n y teniendo en cuenta que empezamos a contar desde
    el bit más significativo. Se introducen tantos 0's como desplazamientos
    realizados, empezando por el bit menos significativo. Si el desplazamiento
    es mayor a la longitud del binario, este queda convertido a 0.

  Derecha()
    Precondicion: recibe un numero de desplazamientos a realizar (n).
    Postcondición: desplaza el numero binario tantas posiciones a la derecha
    como indique el numero introducido como parametro, n, partiendo desde la
    posición del parametro n y teniendo en cuenta que empezamos a contar desde
    el bit menos significativo. Se introducen tantos 0's como desplazamientos
    realizados, empezando por el bit más significativo. Si el desplazamiento es
    mayor a la longitud del binario, este queda convertido a 0.
*/

class Binario
{
  public:
    Binario(const char*);
    Binario NOT();
    Binario AND(const Binario&);
    Binario OR(const Binario&);
    Binario ORExclusivo(const Binario&);
    void Izquierda(const unsigned);
    void Derecha(const unsigned);

  private:
    Lista<unsigned> B;
};

Binario Binario::Binario(const char* str)
{
  typename Lista<unsigned>::posicion p = B.primera();

  for (size_t i = 0; i < strlen(str); i++)
  {
    if(str[i] == '1' ¦¦ str[i] == '0')
    {
      B.insertar((unsigned)str[i], p);
      p = B.siguiente(p);
    }
  }
}

Binario Binario::NOT()
{
  Binario Bin(*this);
  typename Lista<unsigned>::posicion p = Bin.B.primera();

  while (p != Bin.B.fin())
  {
    if(Bin.B.elemento(p))
      Bin.B.elemento(p) = 0;
    else
      Bin.B.elemento(p) = 1;

    p = Bin.B.siguiente(p);
  }

  return Bin;
}

Binario Binario::AND(const Binario& B)
{
  Binario Bin(*this);
  typename Lista<unsigned>::posicion p1 = Bin.B.primera();
  typename Lista<unsigned>::posicion p2 = this -> B.anterior(this -> B.fin());
  typename Lista<unsigned>::posicion p3 = B.B.anterior(B.B.fin());

  while(p2 != this -> B.anterior(this -> B.primera()) &&
  p3 != B.B.anterior(B.B.primera()))
  {
    if(B.B.elemento(p3) == this -> B.elemento(p2) && B.B.elemento(p3) == 1)
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = this -> B.anterior(p2);
    p3 = B.B.anterior(p3);
  }

  while(p2 != this -> B.anterior(this -> B.primera()))
  {
    Bin.B.insertar(0, p1);
    p2 = this -> B.anterior(p2);
  }

  while(p3 != B.B.anterior(B.B.primera()))
  {
    Bin.B.insertar(0, p1);
    p3 = B.B.anterior(p3);
  }

  return Bin;
}

Binario Binario::OR(const Binario& B)
{
  Binario Bin(*this);
  typename Lista<unsigned>::posicion p1 = Bin.B.primera();
  typename Lista<unsigned>::posicion p2 = this -> B.anterior(this -> B.fin());
  typename Lista<unsigned>::posicion p3 = B.B.anterior(B.B.fin());

  while(p2 != this -> B.anterior(this -> B.primera()) &&
  p3 != B.B.anterior(B.B.primera()))
  {
    if(B.B.elemento(p3) ¦¦ this -> B.elemento(p2))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = this -> B.anterior(p2);
    p3 = B.B.anterior(p3);
  }

  while(p2 != this -> B.anterior(this -> B.primera()))
  {
    if(this -> B.elemento(p2))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = this -> B.anterior(p2);
  }

  while(p3 != B.B.anterior(B.B.primera()))
  {
    if(B.B.elemento(p3))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p3 = B.B.anterior(p3);
  }

  return Bin;
}

Binario Binario::ORExclusivo(const Binario& B)
{
  Binario Bin(*this);
  typename Lista<unsigned>::posicion p1 = Bin.B.primera();
  typename Lista<unsigned>::posicion p2 = this -> B.anterior(this -> B.fin());
  typename Lista<unsigned>::posicion p3 = B.B.anterior(B.B.fin());

  while(p2 != this -> B.anterior(this -> B.primera()) &&
  p3 != B.B.anterior(B.B.primera()))
  {
    if(B.B.elemento(p3) == this -> B.elemento(p2))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = this -> B.anterior(p2);
    p3 = B.B.anterior(p3);
  }

  while(p2 != this -> B.anterior(this -> B.primera()))
  {
    if(this -> B.elemento(p2))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = this -> B.anterior(p2);
  }

  while(p3 != B.B.anterior(B.B.primera()))
  {
    if(B.B.elemento(p3))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p3 = B.B.anterior(p3);
  }

  return Bin;
}

void Binario::Izquierda(const unsigned n)
{
  typename Lista<unsigned>::posicion p1 = B.primera();
  typename Lista<unsigned>::posicion p2 = B.siguiente(p1);

  for(unsigned i = 0; i < n; ++i)
  {
    while(p2 != B.fin())
    {
      B.elemento(p1) = B.elemento(p2);
      p1 = p2;
      p2 = B.siguiente(p2);
    }

    p1 = B.primera();
    p2 = B.siguiente(p1);
  }

  p1 = B.anterior(B.fin());

  for(unsigned i = 0; i < n && p1 != B.anterior(B.primera()); ++i)
  {
    B.elemento(p1) = 0;
    p1 = B.anterior(p1);
  }
}

void Binario::Derecha(const unsigned n)
{
  typename Lista<unsigned>::posicion p1 = B.anterior(B.fin());
  typename Lista<unsigned>::posicion p2 = B.anterior(p1);

  for(unsigned i = 0; i < n; ++i)
  {
    while(p2 != B.anterior(B.primera()))
    {
      B.elemento(p1) = B.elemento(p2);
      p1 = p2;
      p2 = B.anterior(p2);
    }

    p1 = B.anterior(B.fin());
    p2 = B.anterior(p1);
  }

  p1 = B.primera();

  for(unsigned i = 0; i < n && p1 != B.fin(); ++i)
  {
    B.elemento(p1) = 0;
    p1 = B.siguiente(p1);
  }
}
