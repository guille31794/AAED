#include <iostream>
#include <cstdlib>

double aleatorioFloat(double a, double b)
{
  return (a + (((rand() * (b - a)) / RAND_MAX) ));
}

int main(int argc, char const *argv[])
{
  double a, b;
  int i;

  std::cout << "Introduzca dos numeros: " << std::endl;
  std::cin >> a >> b;

  i = 1;
  while(i <= 10)
  {
    std::cout << aleatorioFloat(a,b) << std::endl;
    ++i;
  }

  return 0;
}
