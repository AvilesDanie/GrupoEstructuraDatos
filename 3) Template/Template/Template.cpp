/***************************************************
Universidad de las Fuerzas Armadas ESPE
Autores: Daniel Aviles, Ariel Reyes
Fechas de Creacion: 14/05/2023
Fecha de modificacion: 14/05/2023
****************************************************/
#include "Fraccion.cpp"
#include "Operaciones.h"
#include <iostream>

using namespace std;

int main() {

	Fraccion<float> f1(1, 2);
	Fraccion<float> f2(3, 4);
	Operaciones o1;
	cout<<"Suma de fraciones"<< endl;
	Fraccion<float> f3=o1.calculo(f1, f2);
	f3.imprimir();

	cout << "Real de la fraccion f1" << endl;
	float realF1 = o1.calculo(f1.getNumerador(), f1.getDenominador());
	cout << realF1 << endl;
	cout << "Real de la fraccion f2" << endl;
	float realF2 = o1.calculo(f2.getNumerador(), f2.getDenominador());
	cout << realF2 << endl;

	return 0;
}

