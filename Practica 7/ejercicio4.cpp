#include <iostream>
#include <ctime>
#include <cstdlib>
#include "listaOrdenada.hpp"

using namespace std;

void insertElement(ListaOrd<unsigned>& L)
{
  for (int c = 0; c < 5; ++c)
  {
    ListaOrd<unsigned>::posicion p = L.primera();
    L.insertar((rand()%10 + 1));
    p = L.siguiente(p);
  }
}

void printList(const ListaOrd<unsigned>& L)
{
  ListaOrd<unsigned>::posicion p = L.primera();

  while(p != L.fin())
  {
    cout << L.elemento(p) << ' ';
    p = L.siguiente(p);
  }

  cout << endl;
}

ListaOrd<unsigned> joinLists(const ListaOrd<unsigned>& L1,
const ListaOrd<unsigned>& L2)
{
  ListaOrd<unsigned> L3;
  ListaOrd<unsigned>::posicion p1 = L1.primera(), p2 = L2.primera();

  while (p1 != L1.fin())
  {
    L3.insertar(L1.elemento(p1));
    p1 = L1.siguiente(p1);
  }

  while (p2 != L2.fin())
  {
    L3.insertar(L2.elemento(p2));
    p2 = L2.siguiente(p2);
  }

  return L3;
}

int main()
{
  srand(time(NULL));
  ListaOrd<unsigned> L1, L2;

  insertElement(L1);
  insertElement(L2);

  printList(L1);
  printList(L2);

  ListaOrd<unsigned> L3(joinLists(L1, L2));

  printList(L3);

  return 0;
}
