/***********************************************************************
 * Module:  Fraccion.cpp
 * Author:  Aviles, Reyes
 * Modified: Domingo, 14 de mayo de 2023 16:25:15
 * Purpose: Implementation of the class Fraccion
 ***********************************************************************/
#include "Fraccion.h"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::Fraccion(T num, T den)
// Purpose:    Implementation of Fraccion<T>::Fraccion(T num, T den)
// Parameters:
// - num
// - den
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
Fraccion<T>::Fraccion(T num, T den) {
    this->denominador = den;
    this->numerador = num;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::getNumerador()
// Purpose:    Implementation of Fraccion<T>::getNumerador()
// Return:     Template
////////////////////////////////////////////////////////////////////////

template <typename T>
T Fraccion<T>::getNumerador(void) {
    return numerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::setNumerador(T newNumerador)
// Purpose:    Implementation of Fraccion<T>::setNumerador(T newNumerador)
// Parameters:
// - newNumerador
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void Fraccion<T>::setNumerador(T newNumerador) {
    numerador = newNumerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::getDenominador()
// Purpose:    Implementation of Fraccion<T>::getDenominador()
// Return:     Template
////////////////////////////////////////////////////////////////////////

template <typename T>
T Fraccion<T>::getDenominador(void) {
    return denominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::setDenominador(T newDenominador)
// Purpose:    Implementation of Fraccion<T>::setDenominador()
// Parameters:
// - newDenominador
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void Fraccion<T>::setDenominador(T newDenominador) {
    denominador = newDenominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::~Fraccion()
// Purpose:    Implementation of Fraccion<T>::~Fraccion()
// Return:     
////////////////////////////////////////////////////////////////////////

template <typename T>
Fraccion<T>::~Fraccion() {
   
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::simplificar()
// Purpose:    Implementation of Fraccion<T>::simplificar()
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void Fraccion<T>::simplificar() {
    int mcd = calcular_mcd(numerador, denominador);
    numerador /= mcd;
    denominador /= mcd;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::imprimir()
// Purpose:    Implementation of Fraccion<T>::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

template <typename T>
void Fraccion<T>::imprimir() {
    cout << numerador << "/" << denominador << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion<T>::calcular_mcd(T a, T b)
// Purpose:    Implementation of Fraccion<T>::calcular_mcd(T a, T b)
// Parameters:
// - a
// - b
// Return:     int
////////////////////////////////////////////////////////////////////////

template <typename T>
int Fraccion<T>::calcular_mcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    else {
        return calcular_mcd(b, a % b);
    }
}

