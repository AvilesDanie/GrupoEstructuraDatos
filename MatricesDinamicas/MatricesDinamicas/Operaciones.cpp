#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include "Operaciones.h"
template <typename T>
Matriz<T> Operaciones<T>::getMatriz() {
	return _matriz;
}

template <typename T>
Operaciones<T>::Operaciones() {
}

template <typename T>
Operaciones<T>::Operaciones(Matriz<T> m) {
	this->_matriz = m;
}

template <typename T>
void Operaciones<T>::encerar() {
	T  **matriz;
	matriz = _matriz.getMatriz();
	for (int i = 0; i < _matriz.getDim(); i++) {
		for (int j = 0; j < _matriz.getDim(); j++) {
			*(*(matriz + i) + j) = 0;
		}
	}
}

template <typename T>
void Operaciones<T>::imprimir() {
	printf("La matriz es:\n");
	for (int i = 0; i < _matriz.getDim(); i++) {
		for (int j = 0; j < _matriz.getDim(); j++) {
			std::cout << *(*(_matriz.getMatriz() + i) + j) << " ";
		}
		printf("\n");
	}
}

template <typename T>
T **Operaciones<T>::generar(){
	srand(time(NULL));
	T **matriz = _matriz.getMatriz();
	for(int i=0;i<_matriz.getDim();i++){
		for(int j=0;j<_matriz.getDim();j++)	{
			*(*(matriz+i)+j)=(rand()%3)*1.3;
		}
	}
	return matriz;
}

template <typename T>
void Operaciones<T>::multiplicacion(Matriz<T> matriz1, Matriz<T> matriz2, Matriz<T> matrizR, int dim) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			*(*(matrizR.getMatriz() + i) + j) = 0;
			for (int k = 0; k < dim; k++) {
				*(*(matrizR.getMatriz() + i) + j) += (*(*(matriz1.getMatriz() + i) + k)) * (*(*(matriz2.getMatriz() + k) + j));
			}
		}
	}
}