#include "Fraccion.h"
#include <iostream>

using namespace std;

template <typename T>
Fraccion<T>::Fraccion(T num, T den) {
    this->denominador = den;
    this->numerador = num;
}

template <typename T>
T Fraccion<T>::getNumerador(void) {
    return numerador;
}

template <typename T>
void Fraccion<T>::setNumerador(T newNumerador) {
    numerador = newNumerador;
}

template <typename T>
T Fraccion<T>::getDenominador(void) {
    return denominador;
}

template <typename T>
void Fraccion<T>::setDenominador(T newDenominador) {
    denominador = newDenominador;
}

template <typename T>
Fraccion<T>::~Fraccion() {
   
}

template <typename T>
void Fraccion<T>::simplificar() {
    int mcd = calcular_mcd(numerador, denominador);
    numerador /= mcd;
    denominador /= mcd;
}

template <typename T>
void Fraccion<T>::imprimir() {
    cout << numerador << "/" << denominador << endl;
}

template <typename T>
T Fraccion<T>::calcular_mcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    else {
        return calcular_mcd(b, a % b);
    }
}

