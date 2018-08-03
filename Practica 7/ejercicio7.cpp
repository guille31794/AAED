#include <iostream>
#include "listaDoble.hpp"

using namespace std;

template <typename T> Lista<T> concatenate(const Lista<Lista<T>>& LInic)
{
  Lista<T> LConcat;

  typename Lista<Lista<T>>::posicion pLL = LInic.primera();
  typename Lista<T>::posicion pLT = LInic.elemento(pLL).primera();

  for(pLL; pLL != LInic.fin(); pLL = LInic.siguiente(pLL))
    for(pLT; pLT != LInic.elemento(pLL).fin(); pLT = LInic.elemento(pLL).siguiente(pLT))
      LConcat.insertar(LInic.elemento(pLL).elemento(pLT));

  return LConcat;
}

int main(int argc, char const *argv[]) 
{

  return 0;
}
