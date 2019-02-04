#include <iostream>
#include "ListaDoble.h"

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
  extremo derecho, es decir la suma de su posicion inicial más su anchura.

  Cada unidad de tamaño ocupada por un mueble equivale a 1 posicion ocupada de
  la longitud de la cocina.

  Para la implementación utilizaré el tad Lista en su representación dinamica
  doblemente enlazada, con todas sus operaciones.

  Operaciones:

  Cocina(entero)
  Postcondicion: crea una cocina vacía del tamaño introducido como parametro.
  En caso de que el tamaño sea 0 o negativo, el la cocina se creará con tamaño 1
  por defecto.

  booleano Cabe(mueble)
  Precondicion: posicion dentro de la longitud de la cocina.
  Postcondicion: devuelve verdadero si detecta que el mueble introducido como
  parametro cabe en la posicion deseada, o falso en caso contrario.

  procedimiento Aniadir(Mueble, entero)
  Precondicion: espacio suficiente para aniadir el mueble
  Postcondicion: aniade el mueble en la posición especificada.

  Mueble Observador(entero)
  Precondicion: posicion dentro de la longitud de la cocina, y mueble existente
  en dicha posicion.
  Postcondicion: devuelve el mueble situado en esa posicion o nada en caso de
  que no exista.

  procedimiento Eliminar(entero)
  Precondicion: posicion dentro de los limites de la cocina, y mueble en dicha
  posicion.
  Postcondicion: elimina el mueble situado en la posicion seleccionada en el
  parametro de entrada, o no hace nada si no existe.

  procedimiento Mover(entero)
  Precondicion: posicion dentro de los limites de la cocina, y mueble en dicha
  posicion.
  Postcondicion: mueve el mueble de la posicion pasada como parametro hasta
  pegarlo al mueble anterior si es que existe, en cuyo caso se pegaría al
  extremo de la cocina.

  ~Cocina()
  Postcondicion: elimina la cocina con todos sus muebles.
*/

class Mueble
{
  public:
    Mueble(int t = 1, int pos = 0): tam_{t}, pos_{pos}
    {
      if(tam_ < 1) tam_ = 1;
      if(pos_ < 0) pos_ = 0;
    }
    int tam() const {return tam_;}
    int pos() const {return pos_;}
    int pos() {return pos_;}
  private:
    int tam_, pos_;
};

class Cocina
{
  public:
    explicit Cocina(int anchura = 1);
    bool Cabe(Mueble& m) const;
    Mueble Observador(int pos) const;
    void Eliminar(int pos);
    void Aniadir(Mueble& m);
    void Mover(int pos);
    ~Cocina();
  private:
    int anchura, libre;
    Lista<Mueble> l;
};

Cocina::Cocina(int anchura): anchura{anchura}, libre{anchura},
l{Lista<Mueble>()}
{
  if (anchura < 1)
  { anchura = 1; libre = 1;}
}

bool Cocina::Cabe(Mueble& m) const
{
  bool cabe;
  if(libre - m.tam() < 0)
    cabe = false;
  else
    cabe = true;
  return cabe;
}

Mueble Cocina::Observador(int pos) const
{
  Lista<Mueble>::posicion p = l.primera();
  for(int i = 0; i < pos; ++i)
    p = l.siguiente(p);

  return l.elemento(p);
}

void Cocina::Eliminar(int pos)
{
  Lista<Mueble>::posicion p = l.primera();
  for(int i = 0; i < pos; ++i)
    p = l.siguiente(p);

  libre += l.elemento(p).tam();
  l.eliminar(p);
}

void Cocina::Aniadir(Mueble& m)
{
  if(Cabe(m))
  {
    Lista<Mueble>::posicion p = l.fin();
    l.insertar(m,p);
    libre -= m.tam();
  }
  else
    cout << "No se puede colocar el mueble" << endl;
}

Cocina::~Cocina()
{
  anchura = 0;
  libre = 0;
  l.~Lista();
}

void Cocina::Mover(int pos)
{
  Lista<Mueble>::posicion p = l.primera();
  while(p != l.fin() && l.elemento(p).pos() != pos)
    p = l.siguiente(p);

  Lista<Mueble>::posicion p2 = l.primera();
  while(p2 != l.fin() && l.elemento(p2).pos() != pos-1)
    p2 = l.siguiente(p);

  l.insertar(l.elemento(p), l.siguiente(p2));
  l.eliminar(p);
}

int main()
{
  Cocina c{10};
  Mueble m1{2,1}, m2{3,3}, m3{6,2}, m4{1,2};

  c.Aniadir(m1);
  c.Aniadir(m2);
  c.Aniadir(m3);
  c.Aniadir(m4);

  c.Mover(3);
  c.Observador(1);
  c.Eliminar(2);

  return 0;
}
