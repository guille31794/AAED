#include <iostream>
#include <cstdlib>
#include <ctime>
#include "listaEnla.hpp"

using namespace std;

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

void imprimeInverso(const Lista<unsigned>& L)
{
  /*
    En caso de creerlo necesario, solo sera necesario introducir
    la posicion deseada desde la que partir para realizar la impresion inversa
    o incluso aniadirla como parametro en la funcion
  */
  
  Lista<unsigned>::posicion p = L.anterior(L.fin());

  while(p != L.primera())
  {
    cout << L.elemento(p) << ' ';
    p = L.anterior(p);
  }

  cout << L.elemento(p) << endl;
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  Lista<unsigned> L;

  insertElement(L);
  printList(L);

  imprimeInverso(L);

  return 0;
}
