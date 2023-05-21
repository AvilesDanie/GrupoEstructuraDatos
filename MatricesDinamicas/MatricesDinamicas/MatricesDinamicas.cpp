#include <iostream>
#include "Matriz.h"
#include "Operaciones.h"
int ingresar(const char*);
int ingresar(const char* msj) {
	int dim;
	printf("\n%s\n", msj);
	std::cin >> dim;
	return dim;
}
void iniciar(int);
void iniciar(int  dim) {
	int pot;
	int** matR = nullptr;
	int** mat1 = (int**)malloc(dim * sizeof(int*));;
	for (int j = 0; j < dim; j++) {
		*(mat1 + j) = (int*)malloc(dim * sizeof(int*));
	}
	int** mat2 = nullptr;
	Matriz matriz1(mat1, dim);
	Operaciones operaciones1(matriz1);
	operaciones1.segmentar();
	operaciones1.encerar();
	operaciones1.imprimir();
	mat1=operaciones1.generar();
	operaciones1.imprimir();
	mat2=operaciones1.generar();
	operaciones1.imprimir();
	operaciones1.imprimir();
}
int main(int argc, char** argv) {
	int dim;
	dim = ingresar("Ingrese la dimension de la matriz: ");
	iniciar(dim);

	return 0;
}