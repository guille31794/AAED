#include <iostream>

using namespace std;

int posicion(int *v, int *n, int p)
{
  int i, min;

  for(i = 0; i < *n; ++i)
  {
    if(v[i] == p)
    {
      min = i;
    }
  }
  return min;
}

void ordSeleccion(int *v, int *n)
{
  int p, posMin, i, aux;

  for (i = 0; i < *n - 1; ++i)
  {
    p = *min_element(v + i, v + *n);
    posMin = posicion(v, n, p);

    aux = v[i];
    v[i] = p;
    v[posMin] = aux;

  }

}

int main(int argc, char const *argv[])
{
  int i, n = 5;
  int v[] = {3, 6, 5, 1, 4};

  ordSeleccion(v, &n);

  for(i = 0; i < n; ++i)
  {
    cout << v[i] << endl;
  }

  return 0;
}
