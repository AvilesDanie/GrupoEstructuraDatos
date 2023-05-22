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
			printf("%d", *(*(_matriz.getMatriz() + i) + j));
			printf("%*s", j + 5, "");
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
			*(*(matriz+i)+j)=rand()+(T)1.1;
		}
	}
	return matriz;
}
