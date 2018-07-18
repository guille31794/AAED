#include <iostream>
#include "e_s_polinom.h"
#include "polinom.h"
#include "salida_polinom.h"

int main(int argc, char const *argv[])
{
    int operacion;
    
    polinomio polinomio1(gradoMax);
    polinomio polinomio2(gradoMax);
    
    do
    {
        
        cout << "Menu: \n" << "1.- Suma\n" << "2.- Diferencia \n" << "3.- Producto" << "\n"
        << "4.- Derivada\n" << "5.- Introducir polinomio\n" << "0.- Salir\n" << "Opcion: ";
        
        cin >> operacion;
        cout << endl;
        
        switch (operacion)
        {
            case 1: suma(polinomio1, polinomio2);
                    break;
            case 3: producto(polinomio1, polinomio2);
                    break;
            case 2: resta(polinomio1, polinomio2);
                    break;
            case 4: derivada(polinomio1, polinomio2);
                    break;
            case 5: introducirPolinomio(polinomio1, polinomio2);
                    break;
            default: break;
        }
    }
    while(operacion != 0);
    
    return 0;
}
