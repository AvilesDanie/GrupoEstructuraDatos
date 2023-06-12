/***************************************************
Universidad de las Fuerzas Armadas ESPE
Autores: Daniel Aviles, Ariel Reyes
Fechas de Creacion: 21/05/2023
Fecha de modificacion: 21/05/2023
****************************************************/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.cpp"
#include "Operaciones.cpp"
#define MAX 3

using namespace std;

int main(int argc, char** argv) {
	Operaciones<float> operaciones;
	Matriz<float> mat1(MAX);
	Matriz<float> mat2(MAX);
	Matriz<float> mat3(MAX);

	mat1.generar(33.3);
	mat2.generar(3.3);
	mat1.imprimir();
	mat2.imprimir();

	cout << "\nSuma de Matrices es: ";
	operaciones.sumaRecursivaMatrices(mat1,mat2,mat3,0,0);
	mat3.imprimir();

	Matriz<float> mat4(MAX);
	cout << "\Multiplicacion de Matrices es: ";
	operaciones.multiplicarRecursivaMatrices(mat1,mat2, mat4,2,2);
	mat4.imprimir();

	
	return 0;
}
