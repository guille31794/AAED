#include "listaCir.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

/*

  Juego conocido, en el cual hay al menos seis jugadores identificados por su
  nombre. Se situan en circulo, y se les asigna un numero del 1 al 6. Varios
  jugadores pueden tener el mismo numero. Se elige al azar un jugador para
  comenzar y suponiendo i un numero entre 1 y 6, se elimina al jugador situado
  i posiciones a la izquierda si i es impar o i posiciones a la derecha si es
  par. El juego continua utilizando como valor de i el numero del jugador
  eliminado en ultimo lugar, hasta que solamente quede un jugador.

  Se utilizará para la implementación del juego una lista circular de jugadores
  con todas sus operaciones.

  Los jugadores constan de un numero del 1 al 6 asignado aleatoriamente y un
  nombre.

  ganador()
    Precondicion: lista de jugadores inicializada.
    Postcondición: devuelve al último jugador sin eliminar.
*/

class Jugador
{
  public:
    const char* name;
    unsigned number;
    Jugador(const char* na, const unsigned nu): name{na}, number{nu}
    {}
    Jugador(): name{}, number{}
    {}
    Jugador(const Jugador& J): name{J.name}, number{J.number}
    {}
};

Jugador ganador(Lista<Jugador>& L)
{
  typename Lista<Jugador>::posicion p1 = L.iniPos();
  typename Lista<Jugador>::posicion p2 = L.siguiente(p1);
  unsigned totalPlayers = 6;

  /*while(L.elemento(p2).name != L.elemento(p1).name)
  {
    ++totalPlayers;
    p2 = L.siguiente(p2);
    //cout << "Bucle de los nombres" << endl;
  }*/

  unsigned jumpNumber = L.elemento(p1).number;

  while (totalPlayers > 1)
  {
    if(L.elemento(p1).number % 2 == 0)
    {
      while (jumpNumber > 1)
      {
        --jumpNumber;
        p1 = L.siguiente(p1);
      }

      jumpNumber = L.elemento(p1).number;
      cout << "El jugador " << L.elemento(p1).name << " ha sido eliminado" <<
      endl;
      L.eliminar(p1);
    }
    else
    {
      while (jumpNumber > 1)
      {
        --jumpNumber;
        p1 = L.anterior(p1);
      }

      jumpNumber = L.elemento(p1).number;
      cout << "El jugador " << L.elemento(p1).name << " ha sido eliminado" <<
      endl;
      L.eliminar(p1);
    }

    --totalPlayers;
  }

  return L.elemento(L.iniPos());
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  Lista<Jugador> L;
  typename Lista<Jugador>::posicion p = L.iniPos();

  L.insertar(Jugador("Alejandro", rand() % 6 + 1), p);
  L.insertar(Jugador("Juan", rand() % 6 + 1), p);
  L.insertar(Jugador("Guillermo", rand() % 6 + 1), p);
  L.insertar(Jugador("Adrian", rand() % 6 + 1), p);
  L.insertar(Jugador("Alvaro", rand() % 6 + 1), p);
  L.insertar(Jugador("Pablo", rand() % 6 + 1), p);

  Jugador J(ganador(L));

  cout << "El ganador es " << J.name << endl;

  return 0;
}
