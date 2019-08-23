#include <iostream>
#include <vector>

using namespace std;

/*
  Una cocina hace referencia a la longitud de la pared de una habitación
  cualquiera, la cual será utilizada para cocinar alimentos y será necesario
  amueblar para poder lograr tal fin. La cocina tiene un tamaño libre que es
  posible amueblar, aunque este pueda ser discontinuo.

  En la cocina los muebles podrán ir separados o pegados y colocados a lo largo
  de toda la longitud de la cocina hasta agotar la misma y no quedar más espacio
  libre.

  Cada mueble consta de un tamaño y una posición. Se considera el inicio de un mueble 
  tal como sería su vista de frente, cuya posicion será su extremo izquierdo y la distancia 
  que lo separa de la pared y la posicion más el extremo derecho, serán el espacio que ocupa.

  La posición conceptual de un mueble en la cocina no tiene nada que ver con su posición ordinal
  dentro de la estructura de datos empleada.

  Para la implementación utilizaré una estructura vectorial, que me permitira el acceso a las 
  posiciones i-esimas en orden constante.

  Operaciones:

  Cocina(double)
  Postcondicion: crea una cocina vacía del tamaño introducido como parametro.
  En caso de que el tamaño sea 0 o negativo, el la cocina se creará con tamaño 1
  por defecto.

  booleano Cabe(mueble)
  Precondicion: posicion dentro de la longitud de la cocina.
  Postcondicion: devuelve verdadero si detecta que el mueble introducido como
  parametro cabe en la posicion deseada, o falso en caso contrario.

  procedimiento Aniadir(Mueble)
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
    Mueble(double wide, double rp): wide_{wide}, pos_{rp} {}
    int wide() const {return wide_;}
    double pos() {return pos_;}
  private:
    double wide_, pos_;
};

class Cocina
{
  public:
    Cocina(double);
    bool Cabe(Mueble&) const;
    void Aniadir(Mueble&);
    Mueble Observador(int) const;
    void Eliminar(int);
    void Mover(int);
    ~Cocina();
  private:
    double free_;
    vector<Mueble> v;
};

Cocina::Cocina(double t): free_{t}, v{vector<Mueble>{}}
{
  if(free_ < 0.0)
    free_ = 0.0;
}

bool Cocina::Cabe(Mueble& m) const
{
  bool cabe = true;

  if((m.pos()+m.wide()) < free_)
  {
    for(auto muebles : v)
      if(muebles.pos() <= m.pos() && 
      muebles.pos()+muebles.wide() >= m.pos())
        cabe = false;
      else if(m.pos()+m.wide() >= muebles.pos() &&
      m.pos()+m.wide() <= muebles.pos()+muebles.wide())
        cabe = false;
  }
  else
    cabe = false;

  return cabe;
}

void Cocina::Aniadir(Mueble& m)
{
  if(Cabe(m))
    v.push_back(m);
}

Mueble Cocina::Observador(int nMueble) const
{
  if(v.size() >= nMueble)
    return v.at(nMueble);
  else
    return Mueble{0.0, 0.0};
}

void Cocina::Eliminar(int nMueble)
{
  if(v.size() > nMueble)
    v.erase(v.begin()+nMueble-1);
}

//No recuerdo el enunciado y no puedo acabarla
void Cocina::Mover(int i)
{
  Mueble muebleAMover{Observador(i)};
  if(!muebleAMover.pos() && !muebleAMover.wide())
  {
    Mueble muebleDeReferencia{Observador(i-1)};

    if (!muebleDeReferencia.pos() && !muebleDeReferencia.wide())
    {
      
    }
    
  }
  }

Cocina::~Cocina()
{
  v.clear();
  free_ = 0;
}

int main(int argc, char const *argv[]) {

  return 0;
}
