#include <iostream>

using namespace std;

void ordInser(int *v, int *n)
{
  int i, j, aux;

  for (i = 1; i < *n; ++i)
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

int main(int argc, char const *argv[])
{
  int i, n = 5;
  int v[] = {3, 6, 5, 1, 4};

  ordInser(v, &n);

  for(i = 0; i < n; ++i)
  {
    cout << v[i] << endl;
  }

  return 0;
}
