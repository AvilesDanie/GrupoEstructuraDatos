#include "Fraccion.h"
#include <iostream>

using namespace std;

int main() {
	Fraccion f1(1, 2);
	Fraccion f2(3, 4);

	float aux = f1.calculo(f1.getNumerador(), f1.getDenominador());
	float aux1 = f2.calculo(f2.getNumerador(), f2.getDenominador());

	cout << aux << endl;
	cout << aux1 << endl;
	/*
	
	Fraccion f3 = f1.suma(f2);
	Fraccion f4 = f1.resta(f2);
	Fraccion f5 = f1.multiplicacion(f2);
	Fraccion f6 = f1.division(f2);

	f3.simplificar();
	f4.simplificar();
	f5.simplificar();
	f6.simplificar();

	f3.imprimir();
	f4.imprimir();
	f5.imprimir();
	f6.imprimir();

	*/

	return 0;
}

