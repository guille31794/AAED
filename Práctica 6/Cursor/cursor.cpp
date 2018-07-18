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

void imprPila(Pila<char> const &P)
{
    Pila<char> impr{};
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
    
    //cout << endl;
    
    impr.~Pila();
}

void ClearScreen()
{
    cout << string( 100, '\n' );
}

void helpMenu()
{
    ClearScreen();
    
    cout << "Menu ayuda: \n" << "1.- mover cursor: flechas derecha/izquierda.\n"
    << "2.- Modo escritura: W.\n" << "3.- Modo lectura: ESC.\n" << "4.- Salir programa: CTRL + C\n"
    << "5.- Salir ayuda: Cualquier caracter.\n" << endl;
    
    fflush(stdin);
    getchar();
}

void readMode(Pila<char> &P1, Pila<char> &P2)
{
    ClearScreen();
    
    cout << "Modo lectura:" << endl;
    
    imprPila(P1);
    cout << '|';
    imprPila(P2);
    cout << endl;
    
    cout << "Pulse h para obtener ayuda." << endl;
    
    cout << "Opcion: " << endl;
    
}

void writeMode(Pila<char> &P1, Pila<char> &P2)
{
    
}

void bucle(Pila<char> &P1, Pila<char> &P2)
{
    char c = '\0';
    
    do
    {
        switch (c)
        {
            case 'q': cout << "Adios :)" << endl;
                    break;
            case 'Q': cout << "Adios :)" << endl;
                    break;
            case 'h': helpMenu();
                    break;
            case 'H': helpMenu();
                    break;
            case 'w': writeMode(P1, P2);
                    break;
            case 'W': writeMode(P1, P2);
                    break;
            case 37: P2.push(P1.tope());
                    P1.pop();
                    break;
            default: readMode(P1, P2);
                    //break;
        }
        
        c = kbhit();
    }
    while(c != 'Q' && c != 'q');
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
        } else
        {
            // ESC key pression
            
            key_code = -100;
        }
        
        tcsetattr(STDIN_FILENO, TCSANOW, &original_ts);
    }
    
    system ("/bin/stty cooked");
    return (char)key_code;
}
