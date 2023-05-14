#include "Fraccion.h"
#include "Proceso.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion(float num, float den) {
    this->denominador = den;
    this->numerador = num;
}

float Fraccion::getNumerador(void) {
    return numerador;
}

void Fraccion::setNumerador(float newNumerador) {
    numerador = newNumerador;
}

float Fraccion::getDenominador(void) {
    return denominador;
}

void Fraccion::setDenominador(float newDenominador) {
    denominador = newDenominador;
}

Fraccion::~Fraccion() {
   
}

void Fraccion::simplificar() {
    int mcd = calcular_mcd(numerador, denominador);
    numerador /= mcd;
    denominador /= mcd;
}

void Fraccion::imprimir() {
    cout << numerador << "/" << denominador << endl;
}

int Fraccion::calcular_mcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return calcular_mcd(b, a % b);
    }
}