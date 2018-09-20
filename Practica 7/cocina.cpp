#include <iostream>
#include "listaEnla.hpp"

using namespace std;

/*
  Una cocina hace referencia a la longitud de la pared de una habitación
  cualquiera, la cual será utilizada para cocinar alimentos y será necesario
  amueblar para poder lograr tal fin.

  En la cocina los muebles podrán ir separados o pegados y colocados a lo largo
  de toda la longitud de la cocina hasta agotar la misma y no quedar más espacio
  libre.

  Cada mueble consta de un tamaño el cual dictará cuantas posiciones ocupa en la
  cocina. Se considera el inicio de un mueble tal como sería su vista de frente,
  cuya primera posicion será su extremo izquierdo y cuya última posición será su
  extremo derecho.

  Cada unidad de tamaño ocupada por un mueble equivale a 1 posicion ocupada de
  la longitud de la cocina.

  Para la implementación utilizaré el tad Lista en su representación
  mediante celdas enlazadas, con todas sus operaciones.

  Operaciones:

  Cocina(entero)
  Postcondicion: crea una cocina vacía del tamaño introducido como parametro.
  En caso de que el tamaño sea 0 o negativo, el la cocina se creará con tamaño 1
  por defecto.

  booleano Cabe(mueble, posicion)
  Precondicion: posicion dentro de la longitud de la cocina.
  Postcondicion: devuelve verdadero si detecta que el mueble introducido como
  parametro cabe en la posicion deseada, o falso en caso contrario.

  Mueble Observador(posicion)
  Precondicion: posicion dentro de la longitud de la cocina, y mueble existente
  en dicha posicion.
  Postcondicion: devuelve el mueble situado en esa posicion o nada en caso de
  que no exista.

  procedimiento Eliminar(posicion)
  Precondicion: posicion dentro de los limites de la cocina, y mueble en dicha
  posicion.
  Postcondicion: elimina el mueble situado en la posicion seleccionada en el
  parametro de entrada, o no hace nada si no existe.

  procedimiento Mover(posicion)
  Precondicion: posicion dentro de los limites de la cocina, y mueble en dicha
  posicion.
  Postcondicion: mueve el mueble de la posicion pasada como parametro hasta
  pegarlo al mueble anterior si es que existe, en cuyo caso se pegaría al
  extremo de la cocina.

  ~Cocina()
  Postcondicion: elimina la cocina con todos sus muebles.
*/

class Mueble()
{
  public:
    Mueble(int t = 1): tam_{t} {}
    int tam() const {return tam_;}
    int pos() {return pos_;}
  private:
    int tam_;
    int pos_;
};

class Cocina
{
  public:
    Cocina(int);
    bool Cabe(Mueble&) const;
    Mueble Observador(int) const;
    void Eliminar(int);
    void Mover(int);
    ~Cocina();
  private:
    int tam_, libre;
    int v[tam_];
    Lista<Mueble> L;
};

Cocina Cocina::Cocina(int t): tam_{t}, libre{t}
{
  for(int i=0; i < tam_;++i)
  {
    v[i] = 0;
  }
}

bool Cocina::Cabe(Mueble& m) const
{
  bool cabe = false;

  if(libre < m.tam())
    cabe = true;

  return cabe;
}

Mueble Cocina::Cocina(int p) const
{
  int tamAcum = 0;
  Lista<Mueble>::posicion pos = L.primera();

  if(p < tam_ && p >= 0)
  {
    while (tamAcum < p)
    {
      tamAcum += L.elemento(p).tam();
      p = L.siguiente(p);
    }

    return L.elemento(p);
  }
}

void Eliminar(int p)
{
  int tamAcum = 0;
  Lista<Mueble>::posicion pos = L.primera();

  if(p < tam_ && p >= 0)
  {
    while (tamAcum < p)
    {
      tamAcum += L.elemento(p).tam();
      p = L.siguiente(p);
    }

    L.eliminar(p);
  }
}

void Mover(int i)
{
  int tamAcum = 0;
  Lista<Mueble>::posicion pos = L.primera();

  if(p < tam_ && p >= 0)
  {
    while (tamAcum < p)
    {
      tamAcum += L.elemento(p).tam();
      p = L.siguiente(p);
    }

    L.;
  }
}
