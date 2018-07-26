#include "listaEnla.hpp"
#include <iostream>

using namespace std;

Lista<int> EliminaCaracter(Lista<int>& L, int x)
{
  Lista<int> L1 = L;
  Lista<int>::posicion p = L1.buscar(x);

  while(p != L1.fin())
  {
    L1.eliminar(p);
    p = L1.buscar(x);
  }

  return L1;
}

int main()
{
  Lista<int> L;
  int x;

  for (int c = 0; c < 5; ++c)
  {
    Lista<int>::posicion p = L.primera();
    L.insertar(5, p);
    p = L.siguiente(p);
  }

  cout << "Introduzca entero a elminar: ";
  cin >> x;
  cout << endl;

  Lista<int> L1(EliminaCaracter(L, x));
  Lista<int>::posicion p1 = L1.primera();

  while (p1 != L1.fin())
  {
    cout << L1.elemento(p1) << " ";
    p1 = L1.siguiente(p1);
  }

  cout << endl;

  return 0;
}
