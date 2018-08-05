#include <iostream>
#include <ctime>
#include <cstdlib>
#include "listaDoble.hpp"

using namespace std;

template <typename T> Lista<T> concatenate(const Lista<Lista<T>>& LInic)
{
  Lista<T> LConcat;

  typename Lista<Lista<T>>::posicion pLL = LInic.primera();
  typename Lista<T>::posicion pLT = LInic.elemento(pLL).primera();
  typename Lista<T>::posicion pLC = LConcat.primera();

  while(pLL != LInic.fin())
  {
    while(pLT != LInic.elemento(pLL).fin())
    {
      LConcat.insertar(LInic.elemento(pLL).elemento(pLT), pLC);
      pLC = LConcat.siguiente(pLC);
      pLT = LInic.elemento(pLL).siguiente(pLT);
    }

    pLL = LInic.siguiente(pLL);
    if(pLL != LInic.fin())
      pLT = LInic.elemento(pLL).primera();
  }


  return LConcat;
}

void insertElement(Lista<unsigned>& L)
{
  for (int c = 0; c < 5; ++c)
  {
    Lista<unsigned>::posicion p = L.primera();
    L.insertar((rand()%10 + 1), p);
    p = L.siguiente(p);
  }
}

void printList(const Lista<unsigned>& L)
{
  Lista<unsigned>::posicion p = L.primera();

  while(p != L.fin())
  {
    cout << L.elemento(p) << ' ';
    p = L.siguiente(p);
  }

  cout << endl;
}

void insertList(Lista<Lista<unsigned>>& L)
{
  Lista<Lista<unsigned>>::posicion pLL = L.primera();
  Lista<unsigned> Lista;

  for(int i = 0; i < 5; ++i)
  {
    L.insertar( Lista, pLL);
    insertElement(L.elemento(pLL));
    printList(L.elemento(pLL));
    pLL = L.siguiente(pLL);
  }
}

int main()
{
  srand(time(NULL));
  Lista<Lista<unsigned>> LL;

  insertList(LL);

  Lista<unsigned> LC(concatenate(LL));

  printList(LC);

  return 0;
}
