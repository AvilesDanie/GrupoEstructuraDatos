#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include "Operaciones.h"
Matriz Operaciones::getMatriz() {
	return _matriz;
}

Operaciones::Operaciones() {
}

Operaciones::Operaciones(Matriz m) {
	this->_matriz = m;
}

void Operaciones::encerar() {
	int  **matriz;
	matriz = _matriz.getMatriz();
	for (int i = 0; i < _matriz.getDim(); i++) {
		for (int j = 0; j < _matriz.getDim(); j++) {
			*(*(matriz + i) + j) = 0;
		}
	}
}

void Operaciones::imprimir() {
	printf("La matriz es:\n");
	for (int i = 0; i < _matriz.getDim(); i++) {
		for (int j = 0; j < _matriz.getDim(); j++) {
			printf("%d", *(*(_matriz.getMatriz() + i) + j));
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}

int **Operaciones::generar(){
	srand(time(NULL));
	int **matriz = _matriz.getMatriz();
	for(int i=0;i<_matriz.getDim();i++){
		for(int j=0;j<_matriz.getDim();j++)	{
			*(*(matriz+i)+j)=rand()%3;
		}
	}
	return matriz;
}
