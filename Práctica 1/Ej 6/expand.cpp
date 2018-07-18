#include <iostream>
using namespace std;

inline void rotarIzquierda(int& entero1, int& entero2, int& entero3) {
  int variableAuxiliar = entero1;
  entero1 = entero2;
  entero2 = entero3;
  entero3 = variableAuxiliar;
  cout << "La rotacion a la izquierda es: " << entero1 << entero2 << entero3 << endl;
}


int main(int argc, char const *argv[]) {
  cout << "\rIntroduzca 3 enteros a rotar: " ;
  int entero1, entero2, entero3;
  cin >> entero1 >> entero2 >> entero3;
  rotarIzquierda(entero1, entero2, entero3);
}
