#include <iostream>
#include <algorithm>

using namespace std;

void ordenacion(int *v, int n)
{
  int i, j;

  for(i = 1; i <= (n - 1); ++i)
  {
    for (j = 0; j < (n -1); ++j)
    {
      if(v[j] > v[j + 1])
      {
        swap(v[j], v[j+1]);
      }
    }
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

  ordenacion(v, n);
  return(memcmp(v, s, sizeof s) == 0);
}

int main(int argc, char const *argv[])
{
  int n = 9;
  int i;
  int v[n];
  int  w[n];

  for(i = 1; i <= 9; ++i)
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
