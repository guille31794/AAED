//
//  main.cpp
//  TAD Lista
//
//  Created by Guillermo Girón García on 12/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

/*#include "listaCir.hpp"
#include <iostream>

using namespace std;

int main()
{
    Lista<unsigned> L;
    unsigned i;

    Lista<unsigned>::posicion p;

    p = L.iniPos();

    for (i = 0 ; i < 5; ++i)
    {
        L.insertar(i, p);
        p = L.siguiente(p);
    }

    for (i = 0; i < 20; ++i)
    {
        cout << L.elemento(p) << " ; " ;
        p = L.siguiente(p);
    }

    cout << endl;

    L.~Lista();
}*/

/*#include "listaOrdenada.hpp"
#include <iostream>

using namespace std;

int main()
{
    ListaOrd<unsigned> L;
    unsigned i;

    ListaOrd<unsigned>::posicion p;

    p = L.primera();

    for (i = 0 ; i < 5; ++i)
    {
        L.insertar(i);
    }

    cout << "Primera " << L.elemento(L.primera()) << endl;
    cout << "Fin " << L.elemento(L.fin() -> ant) << endl;

    L.insertar(19);
    L.insertar(11);
    L.insertar(8);
    L.insertar(0);
    L.insertar(6);
    L.insertar(5);
    L.insertar(3);

    p = L.primera();

    for (i = 0; i < 12; ++i)
    {
        cout << L.elemento(p) << " ; " ;
        p = L.siguiente(p);
    }

    cout << endl;


    L.~ListaOrd();
}*/

/*#include "listaDoble.hpp"
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
*/
