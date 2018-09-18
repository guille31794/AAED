#include <iostream>
#include "pilaEnla.hpp"

using namespace std;

/*
  Se considera tren a una secuencia de vagones precedida por una locomotora.
  Durante la cadena de montaje este solo puede desplazarse a izquierda o derecha
  y el robot, solo puede operar en los vagones. El vagón situado frente al robot
  será el considerado como vagón activo sobre el cual se realizarán las
  operaciones.

  Se utilizará para ello dos pilas enlazadas, con todas sus operaciones.

  Operaciomes tren:

  Tren()
  Postcondicion: crea una locomotora, sin vagones asociados.

  DIzquierda()
  Precondición: existe algún vagón detrás del activo o la locomotora.
  Postcondicion: mueve el tren un vagón a la izquierda, y transforma el vagón
  activo en el inmediantamente posterior al que hubiera o a la locomotora.

  DDerecha()
  Precondición: existe un vagón activo.
  Postcondición: mueve el tren un vagón a la derecha, y transforma en activo el
  vagón inmediantamente anterior o la misma locomotora sino hay más vagones.

  Eliminar()
  Precondición: existe vagón activo.
  Postcondicion: elimina el vagón activo y pasa a serlo su inmediantamente
  posterior. En caso de no haber posterior, se convierte en activo el anterior,
  y en caso de que tampoco exista, el tren queda vacío.

  Insertar(Vagon)
  Postcondicion: añade un nuevo vagón activo, sino existe ninguno. Si existiese
  alguno, lo desplazaría a la derecha y después se añadiría el nuevo vagón
  activo.

  Observar()
  Precondición: existe vagón activo.
  Postcondición: devuelve el vagón activo.

  Vacío()
  Postcondición: indica si el tren tiene vagones.
*/

typedef int Vagon;

class Tren
{
  public:
    Tren();
    void DIzquierda();
    void DDerecha();
    void Eliminar();
    void Insertar(Vagon&);
    Vagon Observar() const;
    bool vacio() const;
  private:
    Pila<Vagon> PI, PD;
};

Tren::Tren()  {}

void Tren::DIzquierda()
{
  if(!PD.vacia())
  {
    PI.push(PD.tope());
    PD.pop();
  }
}

void Tren::DDerecha()
{
  if(!PI.vacia())
  {
    PD.push(PI.tope());
    PI.pop();
  }
}

void Tren::Eliminar()
{
  if(!PD.vacia() && !PI.vacia())
  {
    PI.pop();
    PI.push(PD.tope());
    PD.pop();
  }
  else
    if(!PI.vacia())
      PI.pop();
}

void Tren::Insertar(Vagon& V)
{
  if(!PI.vacia())
  {
    PD.push(PI.tope());
    PI.pop();
    PI.push(V);
  }
  else
    PI.push(V);
}

Vagon Tren::Observar() const
{
  if(!PI.vacia())
    return PI.tope();
}

bool Tren::vacio() const
{
  bool vacio = false;

  if(PI.vacia() && PD.vacia())
    vacio = true;

  return vacio;
}

int main(int argc, char const *argv[]) {
  
  return 0;
}
