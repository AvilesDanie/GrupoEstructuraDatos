#include <iostream>
#include "Matriz.h"
Matriz::Matriz() {
}

Matriz::Matriz(int** matriz, int dim) {
	this->matriz = matriz;
	this->dim = dim;
}

Matriz::Matriz(int dim) {
	this->dim = dim;
	matriz = (int**)malloc(dim * sizeof(int*));
	for (int i = 0; i < dim; i++) {
		*(matriz + i) = (int*)malloc(dim * sizeof(int*));
	}
}

int Matriz::getDim() {
	return dim;
}

void Matriz::setDim(int dim) {
	this->dim = dim;
}

int** Matriz::getMatriz() {
	return matriz;
}

void Matriz::setMatriz(int** matriz1) {
	this->matriz = matriz;
}

void Matriz::imprimir() {
	printf("La matriz es:\n");
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			printf("%d", *(*(matriz + i) + j));
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}

void Matriz::generar(int num) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			*(*(matriz + i) + j) = num;
		}
	}
}