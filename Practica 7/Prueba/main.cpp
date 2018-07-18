
#include "listaDoble.hpp"
#include <iostream>

using namespace std;

int main()
{
    Lista<unsigned> L;
    unsigned i;

    Lista<unsigned>::posicion p;

    p = L.primera();

    for (i = 0 ; i < 5; ++i)
    {
        L.insertar(i, p);
        p = L.siguiente(p);
    }

    p = L.primera();

    for (i = 0; i < 5; ++i)
    {
        cout << L.elemento(p) << " ; " ;
        p = L.siguiente(p);
    }

    cout << endl;
    cout << "Primera " << L.elemento(L.primera()) << endl;
    cout << "Fin " << L.elemento(L.fin()-> ant) << endl;

    L.~Lista();
}
