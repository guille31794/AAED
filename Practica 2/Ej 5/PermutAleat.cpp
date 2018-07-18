#include <iostream>
#include <algorithm>

using namespace std;

int comparaVectores(int n, int v1[], int v2[])
{
  int b = 1;
  for (int i = 0; i < n; ++i )
  {
    if(v1[i] != v2[i])
      b = 0;
  }
  return b;
}

int main(int argc, char const *argv[])
{
  int i, c, f;
  int v1[] = {2, 3, 1, 4, 5, 6};
  int v2[] = {1, 2, 3, 4, 5, 6};

  i = 0;
  c = 0;

  int n = 6;
  while (i < 10000000)
  {
    if (comparaVectores(n, v1, v2))
    {
      ++c;
    }
    random_shuffle(v1, v1+n);
    ++i;
  }

  cout << c << '\n' <<"El numero de permutaciones ordenadas es: "
  << 10000000/c << endl;

  return 0;
}
