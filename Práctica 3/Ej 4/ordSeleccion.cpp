#include <iostream>
#include <algorithm>
#include "cronometro.h"

using namespace std;

int posicion(int *v, int n, int p)
{
  int i, min;

  for(i = 0; i < n; ++i)
  {
    if(v[i] == p)
    {
      min = i;
    }
  }
  return min;
}

void ordSeleccion(int *v, int n)
{
  int p, posMin, i, aux;

  for (i = 0; i < n - 1; ++i)
  {
    p = *min_element(v + i, v + n);
    posMin = posicion(v, n, p);

    aux = v[i];
    v[i] = p;
    v[posMin] = aux;

  }

}

int main(int argc, char const *argv[])
{
  int n = 20000;
  int i, j, aux;
  int v[n];
  int  w[n];
  double tiempo;
  const int r = 10;
  cronometro crono;

  //Inicializo el vector con n primeros numeros naturales

  i = 1;

  while(i <= n)
  {
    v[i-1] = i-1;
    i++;
  }

i = 1000;

  do
  {
    memcpy(w, v, sizeof v);

    for(j = 0; j < r; ++j)
    {
      for(aux = 0; aux < 50; ++aux)
      {
        // Realizo 50 permutaciones aleatorias
        random_shuffle(w, w+i);
      }

      //Cronometro el tiempo que tardo en ordenar las permutaciones

      crono.activar();
      ordSeleccion(w, i);
      crono.parar();
    }

    tiempo = crono.tiempo() / r;

    cout << "El tiempo es: " << tiempo << endl;
    i += 1000;
  }
  while (i < n);

  return 0;

}
