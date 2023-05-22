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
	Matriz<int> matriz1(dim);
	Operaciones<int> operaciones1(matriz1);
	operaciones1.encerar();
	operaciones1.generar();
	operaciones1.imprimir();

	Matriz<int> matriz2(dim);
	Operaciones<int> operaciones2(matriz2);
	operaciones2.encerar();
	operaciones2.generar();
	operaciones2.imprimir();

	Matriz<int> matrizR(dim);
	Operaciones<int> operaciones3(matrizR);
	operaciones3.encerar();
	operaciones3.multiplicacion(matriz1, matriz2, matrizR, dim);
	operaciones3.imprimir();

}

int main(int argc, char** argv) {
	int dim;
	dim = ingresar("Ingrese la dimension de la matriz: ");
	iniciar(dim);

	return 0;
}