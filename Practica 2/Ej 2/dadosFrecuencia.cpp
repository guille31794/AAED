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
  int a = 1, b = 6, i = 0, auxiliar;

  //Contadores para las frecuencias relativas
  float f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;

  while(i < 10000000)
  {
    auxiliar = aleatorioInt(a, b);
    //cout << auxiliar << endl;
    i++;

    switch (auxiliar)
    {
      case 1: ++f1;
              break;
      case 2: ++f2;
              break;
      case 3: ++f3;
              break;
      case 4: ++f4;
              break;
      case 5: ++f5;
              break;
      case 6: ++f6;
              break;
    }
  }

  cout << "\nLas frecuencias relativas son: \n"
  << f1 / 10000000 << '\n' << f2 / 10000000 << '\n'<< f3 / 10000000
  << '\n' << f4 / 10000000 << '\n' << f5 / 10000000 <<
  '\n'<< f6 / 10000000 << '\n'<< endl;

  return 0;
}
