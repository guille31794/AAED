#include <iostream>
#include <cstdlib>

using namespace std;

double aleatorioInt(int a, int b)
{
double numeroAleatorio;

numeroAleatorio = a + rand() %  (b - a + 1);

return numeroAleatorio;
}

int main(int argc, char const *argv[])
{
  int a, b, i = 0;

  cout << "Introduzca su intervalo" << endl;
  cin >> a  >> b;

  while(i < 10)
  {
  cout << aleatorioInt(a, b)  << endl;
  i++;
  }
  return 0;
}
