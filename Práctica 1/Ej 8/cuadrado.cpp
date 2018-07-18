#include <iostream>
#include "cronometro.h"
using namespace std;

inline double cuadrado (double cuadrado) {return cuadrado * cuadrado;}

int main(int argc, char const *argv[]) {
  int contador = 0; cronometro cronometro;
  double numeroAElevar;
  cout << "Introduzca el numero: ";
  cin >> numeroAElevar;
  cronometro.activar();
  while (cronometro.tiempo() < 1) {
    cuadrado(numeroAElevar);
    ++contador;
  }
  cout << "Se repite: " << contador << endl;
}
