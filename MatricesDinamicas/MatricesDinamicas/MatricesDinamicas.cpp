#include <iostream>
#include "Matriz.cpp"
#include "Operaciones.cpp"
int ingresar(const char*);
int ingresar(const char* msj) {
	int dim;
	printf("\n%s\n", msj);
	std::cin >> dim;
	return dim;
}

void iniciar(int);
void iniciar(int  dim) {
	Matriz<float> matriz(dim);
	Operaciones<float> operaciones1(matriz);
	operaciones1.encerar();
	operaciones1.imprimir();
	operaciones1.generar();
	operaciones1.imprimir();
}

int main(int argc, char** argv) {
	int dim;
	dim = ingresar("Ingrese la dimension de la matriz: ");
	iniciar(dim);

	return 0;
}