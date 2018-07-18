//Cabeceras de es_polinom.cpp

#include "polinom.h"

using namespace std;

//Grado maximo de un polinomio

const unsigned gradoMax = 3;

//Función que inicializa los polinomios

void introducirPolinomio(polinomio &p1, polinomio &p2);

//Funcion que añade los coeficientes a los polinomios

void introducirCoeficientes(polinomio &p, int g);

//Función que permite establecer el grado del polinomio

int introducirGrado();

//Realiza la suma de dos polinomios dados

void suma(polinomio const &p1, polinomio const &p2);

//Realiza la resta de dos polinomios

void resta(polinomio const &p1, polinomio const &p2);

//Realiza el producto de dos polinomios

void producto(polinomio const &p1, polinomio const &p2);

//Realiza la derivada de un polinomio

void derivada(polinomio const &p1, polinomio const &p2);

