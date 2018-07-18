#include <iostream>
#include <algorithm>

using namespace std;

void ordenacionMejor(int *v, int n)
{
  int i = 1, j;
  bool f = false;

  while (!f)
  {
    f = true;
    for (j = 0; j < (n - i); ++j)
    {
      if(v[j] > v[j + 1])
      {
        swap(v[j], v[j+1]);
        f = false;
      }
    }
    ++i;
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

  ordenacionMejor(v, n);
  
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
