#include <iostream>
#include "listaDoble.hpp"
#include <cstdlib>
#include <cstring>

using namespace std;

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

  Extras:

  printBinary()
    Postcondicion: muestra por pantalla el contenido del numero binario.
*/

class Binario
{
  public:
    Binario(const char*) noexcept;
    friend Binario NOT(const Binario&) noexcept;
    friend Binario AND(const Binario&, const Binario& ) noexcept;
    friend Binario OR(const Binario&, const Binario&) noexcept;
    friend Binario ORExclusivo(const Binario&, const Binario&) noexcept;
    friend void Izquierda(Binario&, const unsigned) noexcept;
    friend void Derecha(Binario&, const unsigned) noexcept;
    void printBinary() noexcept;

  private:
    Lista<unsigned> B;
};

Binario::Binario(const char* str) noexcept
{
  typename Lista<unsigned>::posicion p = B.primera();

  for (size_t i = 0; i < strlen(str); i++)
  {
    if(str[i] == '1')
    {
      B.insertar(1, p);
      p = B.siguiente(p);
    }
    if(str[i] == '0')
    {
      B.insertar(0, p);
      p = B.siguiente(p);
    }
  }
}

Binario NOT(const Binario& B) noexcept
{
  Binario Bin(B);
  typename Lista<unsigned>::posicion p = Bin.B.primera();

  while (p != Bin.B.fin())
  {
    if(Bin.B.elemento(p) == 1)
      Bin.B.elemento(p) = 0;
    else
      Bin.B.elemento(p) = 1;

    p = Bin.B.siguiente(p);
  }

  return Bin;
}

Binario AND(const Binario& B1, const Binario& B2) noexcept
{
  Binario Bin("");
  typename Lista<unsigned>::posicion p1 = Bin.B.primera();
  typename Lista<unsigned>::posicion p2 = B2.B.anterior(B2.B.fin());
  typename Lista<unsigned>::posicion p3 = B1.B.anterior(B1.B.fin());

  while(p2 != B2.B.primera() && p3 != B1.B.primera())
  {
    if(B1.B.elemento(p3) == B2.B.elemento(p2) && B1.B.elemento(p3) == 1)
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = B2.B.anterior(p2);
    p3 = B1.B.anterior(p3);

    if(p2 == B2.B.primera() || p3 == B1.B.primera())
      if(B2.B.elemento(p2) == B1.B.elemento(p3))
      {
        Bin.B.insertar(1, p1);
        if(p2 != B2.B.primera())
          p2 = B2.B.anterior(p2);
        else if(p3 != B1.B.primera())
          p3 = B1.B.anterior(p3);
      }
      else
      {
        Bin.B.insertar(0, p1);
        if(p2 != B2.B.primera())
          p2 = B2.B.anterior(p2);
        else if(p3 != B1.B.primera())
          p3 = B1.B.anterior(p3);
      }
  }

  while(p2 != B2.B.primera())
  {
    Bin.B.insertar(0, p1);
    p2 = B2.B.anterior(p2);
  }

  while(p3 != B1.B.primera())
  {
    Bin.B.insertar(0, p1);
    p3 = B1.B.anterior(p3);
  }

  return Bin;
}

Binario OR(const Binario& B1, const Binario& B2) noexcept
{
  Binario Bin("");
  typename Lista<unsigned>::posicion p1 = Bin.B.primera();
  typename Lista<unsigned>::posicion p2 = B2.B.anterior(B2.B.fin());
  typename Lista<unsigned>::posicion p3 = B1.B.anterior(B1.B.fin());

  while(p2 != B2.B.primera() && p3 != B1.B.primera())
  {
    if(B1.B.elemento(p3) || B2.B.elemento(p2))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = B2.B.anterior(p2);
    p3 = B1.B.anterior(p3);

    if(p2 == B2.B.primera() || p3 == B1.B.primera())
      if(B2.B.elemento(p2) || B1.B.elemento(p3))
      {
        Bin.B.insertar(1, p1);
        if(p2 != B2.B.primera())
          p2 = B1.B.anterior(p2);
        else if(p3 != B1.B.primera())
          p3 = B1.B.anterior(p3);
      }
      else
      {
        Bin.B.insertar(0, p1);
        if(p2 != B2.B.primera())
          p2 = B2.B.anterior(p2);
        else if(p3 != B1.B.primera())
          p3 = B1.B.anterior(p3);
      }
  }

  while(p2 != B2.B.primera())
  {
    if(B2.B.elemento(p2))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = B2.B.anterior(p2);

    if(p2 == B2.B.primera())
      if(B2.B.elemento(p2) == 1)
        Bin.B.insertar(1, p1);
      else
        Bin.B.insertar(0, p1);
  }

  while(p3 != B1.B.primera())
  {
    if(B1.B.elemento(p3))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p3 = B1.B.anterior(p3);

    if(p3 == B1.B.primera())
      if(B1.B.elemento(p3) == 1)
        Bin.B.insertar(1, p1);
      else
        Bin.B.insertar(0, p1);
  }

  return Bin;
}

Binario ORExclusivo(const Binario& B1, const Binario& B2) noexcept
{
  Binario Bin("");
  typename Lista<unsigned>::posicion p1 = Bin.B.fin();
  typename Lista<unsigned>::posicion p2 = B2.B.anterior(B2.B.fin());
  typename Lista<unsigned>::posicion p3 = B1.B.anterior(B1.B.fin());

  while(p2 != B2.B.primera() && p3 != B1.B.primera())
  {
    if(B1.B.elemento(p3) == B2.B.elemento(p2))
      Bin.B.insertar(0, p1);
    else
      Bin.B.insertar(1, p1);

    p2 = B2.B.anterior(p2);
    p3 = B1.B.anterior(p3);

    if(p2 == B2.B.primera() || p3 == B1.B.primera())
      if(B2.B.elemento(p2) == B1.B.elemento(p3))
      {
        Bin.B.insertar(0, p1);
        if(p2 != B2.B.primera())
          p2 = B2.B.anterior(p2);
        else if(p3 != B1.B.primera())
          p3 = B1.B.anterior(p3);
      }
      else
      {
        Bin.B.insertar(1, p1);
        if(p2 != B2.B.primera())
          p2 = B2.B.anterior(p2);
        else if(p3 != B1.B.primera())
          p3 = B1.B.anterior(p3);
      }
  }

  while(p2 != B2.B.primera())
  {
    if(B2.B.elemento(p2))
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p2 = B2.B.anterior(p2);

    if(p2 == B2.B.primera())
      if(B2.B.elemento(p2) == 1)
        Bin.B.insertar(1, p1);
      else
        Bin.B.insertar(0, p1);
  }


  while(p3 != B1.B.primera())
  {
    if(B1.B.elemento(p3) == 1)
      Bin.B.insertar(1, p1);
    else
      Bin.B.insertar(0, p1);

    p3 = B1.B.anterior(p3);

    if(p3 == B1.B.primera())
      if(B1.B.elemento(p3) == 1)
        Bin.B.insertar(1, p1);
      else
        Bin.B.insertar(0, p1);
  }

  return Bin;
}

void Izquierda(Binario& B, const unsigned n) noexcept
{
  typename Lista<unsigned>::posicion p1 = B.B.primera();
  typename Lista<unsigned>::posicion p2 = B.B.siguiente(p1);

  for(unsigned i = 0; i < n; ++i)
  {
    while(p2 != B.B.fin())
    {
      B.B.elemento(p1) = B.B.elemento(p2);
      p1 = p2;
      p2 = B.B.siguiente(p2);
    }

    p1 = B.B.primera();
    p2 = B.B.siguiente(p1);
  }

  p1 = B.B.anterior(B.B.fin());

  for(unsigned i = 0; i < n && p1 != B.B.primera(); ++i)
  {
    B.B.elemento(p1) = 0;
    p1 = B.B.anterior(p1);
  }
}

void Derecha(Binario& B, const unsigned n) noexcept
{
  typename Lista<unsigned>::posicion p1 = B.B.anterior(B.B.fin());
  typename Lista<unsigned>::posicion p2 = B.B.anterior(p1);

  for(unsigned i = 0; i < n; ++i)
  {
    while(p2 != B.B.primera())
    {
      B.B.elemento(p1) = B.B.elemento(p2);
      p1 = p2;
      p2 = B.B.anterior(p2);
    }

    p1 = B.B.anterior(B.B.fin());
    p2 = B.B.anterior(p1);
  }

  p1 = B.B.primera();

  for(unsigned i = 0; i < n && p1 != B.B.fin(); ++i)
  {
    B.B.elemento(p1) = 0;
    p1 = B.B.siguiente(p1);
  }
}

void Binario::printBinary() noexcept
{
  typename Lista<unsigned>::posicion p = B.primera();

  for(p; p != B.fin(); p = B.siguiente(p))
    cout << B.elemento(p);

  cout << endl;
}

int main()
{
  Binario b("10111111111");
  Binario b2("00000001111");

  b.printBinary();
  b2.printBinary();

  Binario Bin(AND(b, b2));

  Bin.printBinary();


  return 0;
}
