//
//  suma.cpp
//  Suma desde fichero
//
//  Created by Guillermo Girón García on 29/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "suma.hpp"

void genFich(fstream &F)
{
    unsigned aleat, i, tamMax, j;

    j = 0;

    F.open("suma.txt", ios::out | ios::trunc);

    if(F.good())
    {
        do
        {
            cout << "\rIntroduzca el tamaño máximo del numero: ";

            tamMax = 0;

            while (tamMax > 20 || tamMax < 10)
            {
                cin >> tamMax;
            }

            cout << endl;

            for(i = 0; i < tamMax; ++i)
            {
                aleat = rand() % 10;
                F << aleat << flush;
            }

            F << '\n';

            ++j;
        }
        while (j < 2);
    }

    cout << endl;

    F.close();

}

void imprPila(Pila<int> const &P)
{
    Pila<int> impr;

    impr.operator = (P);

    while (!impr.vacia())
    {
        cout << impr.tope();
        impr.pop();
    }

    cout << endl;

    impr.~Pila();
}

void fileToP(Pila <int> &P1, Pila <int> &P2, fstream &F)
{
    F.open("suma.txt", ios::in);
    
    if(F.good())
        F >> P1 >> P2;
    
    F.close();
}

void PtoFile(Pila <int> &P, fstream &F)
{
    F.open("suma.txt", ios::app);
    
    if(F.good())
        F << P;
    
    F.close();
}

void sumAc(Pila <int> &N1, Pila<int> &N2, Pila<int> &RES)
{
    int ac;
    
    ac = 0;
    
    while (!N1.vacia() && !N2.vacia())
    {
        if(N1.tope() + N2.tope() + ac > 9)
        {
            RES.push((N1.tope() + N2.tope() + ac) % 10);
            N1.pop();
            N2.pop();
            ac = 1;
        }
        else
        {
            RES.push(N1.tope() + N2.tope() + ac);
            N1.pop();
            N2.pop();
            ac = 0;
        }
    }
    
    if (N1.vacia())
    {
        while (!N2.vacia())
        {
            if (N2.tope() + ac > 9)
            {
                RES.push((N2.tope() + ac) % 10);
                N2.pop();
                ac = 1;
            }
            else
            {
                RES.push(N2.tope() + ac);
                N2.pop();
                ac = 0;
            }
        }
    }
    else
    {
        while (!N1.vacia())
        {
            if (N1.tope() + ac > 9)
            {
                RES.push((N1.tope() + ac) % 10);
                N1.pop();
                ac = 1;
            }
            else
            {
                RES.push(N1.tope() + ac);
                N1.pop();
                ac = 0;
            }
        }
    }
    
}

fstream &operator >> (fstream &fe, Pila <int> &P)
{
    char cifra;

    while (fe.get(cifra) && cifra != '\n')   //Lee caracteres hasta fin de linea
    {
        P.push(cifra -= '0');   //Convierte un digito en su valor numerico
    }

    return fe;
}

fstream &operator << (fstream &fs, Pila<int> P)
{
    while (!P.vacia())
    {
        fs << P.tope();
        P.pop();
    }

    fs << endl;

    return fs;
}
