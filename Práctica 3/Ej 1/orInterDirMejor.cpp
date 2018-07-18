#include <iostream>
#include <algorithm>

using namespace std;

void ordenacionMejor(int *v, int *n)
{
  int i = 1, j;
  bool f = false;

  while (!f)
  {
    f = true;
    for (j = 0; j < (*n - i); ++j)
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

int main(int argc, char const *argv[])
{
  int v[] = {3,5,1,8,9,7,4};
  int n = 7;
  int i;

  ordenacionMejor(v, &n);

  for (i = 0; i < n; i++)
  {
    cout << v[i] << '\n';
  }

  return 0;
}
