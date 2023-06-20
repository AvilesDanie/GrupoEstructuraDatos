/***********************************************************************
 * Module:  Matriz2x2.cpp
 * Author:  Aviles, Reyes
 * Modified: Domingo, 14 de mayo de 2023 16:25:15
 * Purpose: Implementation of the class Matriz2x2.cpp
 ***********************************************************************/
#include "Matriz2x2.h"
#include <iostream>

 ////////////////////////////////////////////////////////////////////////
 // Name:       Matriz2x2<T>::Matriz2x2(int e1, int e2, int e3, int e4)
 // Purpose:    Implementation of Matriz2x2<T>::Matriz2x2(int e1, int e2, int e3, int e4)
 // Parameters:
 // - e1
 // - e2
 // - e3
 // - e4
 // Return:     
 ////////////////////////////////////////////////////////////////////////

template<typename T>
Matriz2x2<T>::Matriz2x2(int e1, int e2, int e3, int e4) {
    elementos[0][0]=e1;
    elementos[0][1]=e2;
    elementos[1][0]=e3;
    elementos[1][1]=e4;

}

////////////////////////////////////////////////////////////////////////
// Name:       T Matriz2x2<T>::getElemento(int fila, int columna) const
// Purpose:    Implementation of T Matriz2x2<T>::getElemento(int fila, int columna) const
// Parameters:
// - fila
// - columna
// Return:  Template  
////////////////////////////////////////////////////////////////////////

template<typename T>
T Matriz2x2<T>::getElemento(int fila, int columna) const {
    return elementos[fila][columna];
}

////////////////////////////////////////////////////////////////////////
// Name:       void Matriz2x2<T>::setElemento(int fila, int columna, T valor)
// Purpose:    Implementation of void Matriz2x2<T>::setElemento(int fila, int columna, T valor)
// Parameters:
// - fila
// - columna
// - valor
// Return:  void  
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matriz2x2<T>::setElemento(int fila, int columna, T valor) {
    elementos[fila][columna] = valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       void Matriz2x2<T>::imprimir()
// Purpose:    Implementation of void Matriz2x2<T>::imprimir()
// Return:  void  
////////////////////////////////////////////////////////////////////////

template<typename T>
void Matriz2x2<T>::imprimir(){
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << elementos[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz2x2<T> Matriz2x2<T>::operator +(const Matriz2x2<T>& other) const
// Purpose:    Implementation of Matriz2x2<T> Matriz2x2<T>::operator +(const Matriz2x2<T>& other) const
// Parameters:
// - other
// Return:  Template  
////////////////////////////////////////////////////////////////////////

template<typename T>
Matriz2x2<T> Matriz2x2<T>::operator +(const Matriz2x2<T>& other) const {
    Matriz2x2<T> resultado(0,0,0,0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            resultado.setElemento(i, j, getElemento(i, j) + other.getElemento(i, j));
        }
    }
    return resultado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz2x2<T> Matriz2x2<T>::operator -(const Matriz2x2<T>& other) const
// Purpose:    Implementation of Matriz2x2<T> Matriz2x2<T>::operator -(const Matriz2x2<T>& other) const
// Parameters:
// - other
// Return:  Template 
////////////////////////////////////////////////////////////////////////

template<typename T>
Matriz2x2<T> Matriz2x2<T>::operator -(const Matriz2x2<T>& other) const {
    Matriz2x2<T> resultado(0, 0, 0, 0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            resultado.setElemento(i, j, getElemento(i, j) - other.getElemento(i, j));
        }
    }
    return resultado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz2x2<T> Matriz2x2<T>::operator *(const Matriz2x2<T>& other)const
// Purpose:    Implementation of Matriz2x2<T> Matriz2x2<T>::operator *(const Matriz2x2<T>& other)const
// Parameters:
// - other
// Return:  Template 
////////////////////////////////////////////////////////////////////////

template<typename T>
Matriz2x2<T> Matriz2x2<T>::operator *(const Matriz2x2<T>& other)const {
    Matriz2x2<T> resultado(0, 0, 0, 0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            resultado.setElemento(i, j, getElemento(i, 0) * other.getElemento(0, j)+ getElemento(i, 1) * other.getElemento(1, j));
        }
    }
    return resultado;
}

////////////////////////////////////////////////////////////////////////
// Name:       bool Matriz2x2<T>::operator ==(const Matriz2x2<T>& other)const
// Purpose:    Implementation of bool Matriz2x2<T>::operator ==(const Matriz2x2<T>& other)const
// Parameters:
// - other
// Return:  bool 
////////////////////////////////////////////////////////////////////////

template<typename T>
bool Matriz2x2<T>::operator ==(const Matriz2x2<T>& other)const {
    bool resultado=true;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (getElemento(i, j) != other.getElemento(i, j))
                resultado = false;
        }
    }
    return resultado;
}