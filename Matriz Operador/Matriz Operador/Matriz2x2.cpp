#include "Matriz2x2.h"
#include <iostream>

template<typename T>
Matriz2x2<T>::Matriz2x2(int e1, int e2, int e3, int e4) {
    elementos[0][0]=e1;
    elementos[0][1]=e2;
    elementos[1][0]=e3;
    elementos[1][1]=e4;

}

template<typename T>
T Matriz2x2<T>::getElemento(int fila, int columna) const {
    return elementos[fila][columna];
}

template<typename T>
void Matriz2x2<T>::setElemento(int fila, int columna, T valor) {
    elementos[fila][columna] = valor;
}

template<typename T>
void Matriz2x2<T>::imprimir() const {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << elementos[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
Matriz2x2<T> Matriz2x2<T>::operator+(const Matriz2x2<T>& other) const {
    Matriz2x2<T> resultado(0,0,0,0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {

            resultado.setElemento(i, j, getElemento(i, j) + other.getElemento(i, j));
        }
    }
    return resultado;
}

template<typename T>
Matriz2x2<T> Matriz2x2<T>::operator-(const Matriz2x2<T>& other) const {
    Matriz2x2<T> resultado(0, 0, 0, 0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            resultado.setElemento(i, j, getElemento(i, j) - other.getElemento(i, j));
        }
    }
    return resultado;
}