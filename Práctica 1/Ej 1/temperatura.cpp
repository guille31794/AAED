#include <iostream>
using namespace std;

void muestra_temperatura(int temperatura)
{
  cout << "temperatura: " << temperatura << " grados";
  if (temperatura > 20)
    if(temperatura < 30)
      cout << " (normal)";
  else
    cout << "(baja)";
  cout << endl;
}

int main(int argc, char const *argv[]) {

  int t;
  cout << "Indique la temperatura a medir: ";
  cin >> t;
  muestra_temperatura(t);
  return 0;
}
