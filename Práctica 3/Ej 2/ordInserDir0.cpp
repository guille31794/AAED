#include <iostream>
#include <algorithm>

using namespace std;

void ordInser(int *v, int n)
{
  int i, j, aux;

  for (i = 1; i < n; ++i)
  {
    aux = v[i];
    j = i - 1;

    while ((v[j] > aux) && j >= 0 )
    {
      v[j+1] = v[j];
      j--;
    }

    v[j+1] = aux;
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

  ordInser(v, n);

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
