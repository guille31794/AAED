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

int main(int argc, char const *argv[])
{
  int v[] = {3,5,1,8,9,7,4};
  int n = 7;
  int i;

  ordenacion(v, n);

  for (i = 0; i < n; i++)
  {
    cout << v[i] << '\n';
  }

  return 0;
}
