#include <iostream>
#include <algorithm>

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

bool prueba_ordena(int e[], int s[], unsigned n)
{
  int v[n], i;

  for(i = 0; i < n; ++i)
  {
    v[i] = e[i];
    cout << v[i] << " ";
  }
  cout << endl;

  ordSeleccion(v, n);
  return(memcmp(v, s, sizeof s) == 0);
}

int main(int argc, char const *argv[])
{
  int n = 9;
  int i;
  int v[n];
  int w[n];

  for(i = 1; i <= n; ++i)
  {
    v[i-1] = i-1;

    memcpy(w, v, sizeof v);

    do
    {
      if(!prueba_ordena(v, w, i))
      {
        cout << "ERROR. \a" << endl;
        return 1;
      }
    }
    while(next_permutation(v, v + i));
  }

  return 0;
}
