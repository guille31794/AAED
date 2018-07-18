#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

double pseudoDouble()
{
  double a, b, numeroAleatorio;

  a = 0;
  b = 1;

  //numeroAleatorio = b / (rand()+b);
  return (a + (((rand() * (b - a)) / RAND_MAX) ));
  //return numeroAleatorio;

}

double raiz(double r)
{
  double y;
  y = 4 * (sqrt((1 - (r * r))));
  return y;
}

int main(int argc, char const *argv[])
{
  double auxiliar, auxiliar2, media;
  int i = 0;

  while (i < 100)
  {
    auxiliar = pseudoDouble();
    auxiliar2 = raiz(auxiliar);
    media += auxiliar2;
    cout << auxiliar << endl;
    ++i;
  }

  media = media / 100;
  cout << "La media es: " << media << endl;

  return 0;
}
