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
	matriz = (T**)malloc(dim*sizeof(T*));
	for (int i = 0; i < dim;i++) {
		*(matriz + i) = (T*)malloc(dim * sizeof(T*));
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
	this->matriz = matriz1;
}


