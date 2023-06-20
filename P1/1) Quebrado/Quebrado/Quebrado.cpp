/***************************************************
Universidad de las Fuerzas Armadas ESPE
Autores: Daniel Aviles, Ariel Reyes
Fechas de Creacion: 11/05/2023
Fecha de modificacion: 11/05/2023
Tipos de datos Abstractos e interface en Quebrados
****************************************************/
#include "Fraccion.h"
#include <iostream>

using namespace std;

int main() {

	Fraccion f1(1, 2);
	Fraccion f2(3, 4);
	Fraccion f3 = f1.calculo(f1, f2);
	f3.simplificar();
	f3.imprimir();

	return 0;
}
