#include <iostream>
using namespace std;

void muestra_temperatura(int temperatura) {
  cout << "Temperatura: " << temperatura << " grados";
  if (20 < temperatura && temperatura < 30)
    cout << " (normal)";
  else
    cout << " (anormal)";
  cout << endl;
}

int main(int argc, char const *argv[]) {

  int t;
  cout << "Indique la temperatura a medir: ";
  cin >> t;
  muestra_temperatura(t);
}
