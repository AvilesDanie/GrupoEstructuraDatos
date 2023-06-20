#include <iostream>
#include "Matriz.h"
template <typename T>
Matriz<T>::Matriz() {
}

template <typename T>
Matriz<T>::Matriz(T** matriz, int dim) {
	this->matriz = matriz;
	this->dim = dim;
}

template <typename T>
Matriz<T>::Matriz(int dim) {
	this->dim = dim;
	matriz = (T**)malloc(dim * sizeof(int*));
	for (int i = 0; i < dim; i++) {
		*(matriz + i) = (T*)malloc(dim * sizeof(int*));
	}
}

template <typename T>
int Matriz<T>::getDim() {
	return dim;
}

template <typename T>
void Matriz<T>::setDim(int dim) {
	this->dim = dim;
}

template <typename T>
T** Matriz<T>::getMatriz() {
	return matriz;
}

template <typename T>
void Matriz<T>::setMatriz(T** matriz1) {
	this->matriz = matriz;
}

template <typename T>
void Matriz<T>::imprimir() {
	printf("La matriz es:\n");
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			std::cout << *(*(matriz + i) + j) << " ";
		}
		printf("\n");
	}
}

template <typename T>
void Matriz<T>::generar(T num) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			*(*(matriz + i) + j) = num;
		}
	}
}