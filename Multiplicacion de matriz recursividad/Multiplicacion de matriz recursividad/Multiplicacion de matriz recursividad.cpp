#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.h"
#include "Operaciones.h"
#define MAX 3

using namespace std;

int main(int argc, char** argv) {
	Operaciones operaciones;
	Matriz mat1(MAX);
	Matriz mat2(MAX);
	Matriz mat3(MAX);

	mat1.generar(33);
	mat2.generar(3);
	mat1.imprimir();
	mat2.imprimir();

	cout << "\nSuma de Matrices es: ";
	operaciones.sumaRecursivaMatrices(mat1,mat2,mat3,0,0);
	mat3.imprimir();

	Matriz mat4(MAX);
	cout << "\Multiplicacion de Matrices es: ";
	operaciones.multiplicarRecursivaMatrices(mat1,mat2, mat4,2,2);
	mat4.imprimir();

	
	return 0;
}
