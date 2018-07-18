//
//  cursor.cpp
//  Cursor
//
//  Created by Guillermo Girón García on 11/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#include "cursor.hpp"

void stringAPila(string &c, Pila<char> &P)
{
    unsigned i;
    unsigned long l;

    l = c.length();

    for(i = 0; i < l; ++i)
    {
        P.push(c[i]);
    }
}

void pilaAString(string &c, Pila<char> &P)
{
  while (!P.vacia())
  {
    c += P.tope();
    P.pop();
  }
}

void imprString(string s)
{
  unsigned long l;

  l = s.length();

  while(l > 0)
  {
    cout << s[l];
  }
}

void imprPila(Pila<char> const &P)
{
    Pila<char> impr;
    string c;
    int i = 0;

    impr.operator = (P);

    while (!impr.vacia())
    {
        c[i] = impr.tope();
        impr.pop();
        ++i;
    }

    while (i >= 0)
    {
        cout << c[i];
        --i;
    }

    impr.~Pila();
}

void imprPilaInv(Pila<char> const &P)
{
    Pila<char> impr;

    impr.operator = (P);

    while (!impr.vacia())
    {
        cout << impr.tope();
        impr.pop();
    }

    impr.~Pila();
}

void ClearScreen()
{
    cout << string( 100, '\n' );
}

void helpMenu()
{
    ClearScreen();

    cout << "Menu ayuda: \n" <<
    "1.- mover cursor: <- Izquierda || -> Derecha + intro\n"
    << "2.- Modo escritura: en modo lectura - W.\n" <<
    "3.- Modo lectura: en modo escritura - intro.\n"
    << "4.- Salir programa: en modo lectura o ayuda - ESC\n" <<
    "5.- Salir ayuda: Cualquier caracter + intro.\n" <<
    "6.- Borrar caracter: en modo lectura - Delete\n" <<
    "7.- Suprimir caracter: en modo lectura - *\n" <<
    "8.- Fin de linea: En modo lectura - '.' + intro\n" <<
    "9.- Principio de linea: En modo lectura - ','" << endl;

    fflush(stdin);
    getchar();
}

void readMode(Pila<char> &P1, Pila<char> &P2)
{
    ClearScreen();

    cout << "Modo lectura:" << endl;

    imprPila(P1);
    cout << ANSI_COLOR_RED << '|' << ANSI_COLOR_RESET;
    imprPilaInv(P2);
    cout << endl;

    cout << "Pulse h para obtener ayuda." << endl;
}

void writeMode(Pila<char> &P1, Pila<char> &P2)
{
    string s;
    ClearScreen();

    cout << "Modo lectura:" << endl;

    imprPila(P1);

    getline(cin, s);

    stringAPila(s, P1);

}

void bucle(Pila<char> &P1, Pila<char> &P2)
{
    char c = '\0';

    do
    {
        switch (c)
        {
            case 'h': helpMenu();
                    break;
            case 'H': helpMenu();
                    break;
            case 'w': writeMode(P1, P2);
                    break;
            case 'W': writeMode(P1, P2);
                    break;
            case -2: retroC(P1, P2);
                    break;
            case -1: avanzaC(P1, P2);
                    break;
            case 127: del(P1);
            case '*': supr(P2);
            case '.': finC(P1, P2);
                    break;
            case ',': iniC(P1, P2);
            default: readMode(P1, P2);
        }

        c = kbhit();
    }
    while(c != 'Q' && c != 'q' && c != -100);
}

void avanzaC(Pila<char> &P1, Pila<char> &P2)
{
  if(!P2.vacia())
  {
    P1.push(P2.tope());
    P2.pop();
  }
}

void retroC(Pila<char> &P1, Pila<char> &P2)
{
  if(!P1.vacia())
  {
    P2.push(P1.tope());
    P1.pop();
  }
}

void iniC(Pila<char> &P1, Pila<char> &P2)
{
  while(!P1.vacia())
  {
    P2.push(P1.tope());
    P1.pop();
  }
}

void finC(Pila<char> &P1, Pila<char> &P2)
{
  while (!P2.vacia())
  {
    P1.push(P2.tope());
    P2.pop();
  }
}

void del(Pila<char> &P)
{
  if(!P.vacia())
    P.pop();
}

void supr(Pila<char> &P)
{
if(!P.vacia())
  P.pop();
}

char kbhit()
{
    int key_code = 0;
    system ("/bin/stty raw");

    unsigned int character = getchar();
    key_code = character;

    if(character == 27)
    {
        struct termios original_ts, nowait_ts;
        unsigned int SpecialKeyCode;
        unsigned int arrow_code;

        tcgetattr(STDIN_FILENO, &original_ts);
        nowait_ts = original_ts;
        nowait_ts.c_lflag &= ~ISIG;
        nowait_ts.c_cc[VMIN]  = 0;
        nowait_ts.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &nowait_ts);

        usleep(100*1000);

        if((SpecialKeyCode = getchar()) != EOF)
        {
            if(SpecialKeyCode == 91)
            {
                if ((arrow_code = getchar()) != EOF)
                {
                    switch(arrow_code)
                    {
                        case 67: key_code = -1; break; // Derecha
                        case 68: key_code = -2; break; // Izquierda
                        case 70: key_code = -3; break; // Fin texto
                        case 72: key_code = -4; break; // Principio texto
                    }
                }
            }
        }
        else
        {
            // ESC key pression

            key_code = -100;
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &original_ts);
    }

    system ("/bin/stty cooked");
    return (char)key_code;
}
