#include "Fraccion.h"
#include "Proceso.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion(float num, float den){
    this->denominador = den;
    this->numerador = num;
}

float Fraccion::getNumerador(void){
    return numerador;
}

void Fraccion::setNumerador(float newNumerador){
    numerador = newNumerador;
}

float Fraccion::getDenominador(void){
    return denominador;
}

void Fraccion::setDenominador(float newDenominador){
    denominador = newDenominador;
}

Fraccion::~Fraccion(){
    
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

Fraccion Fraccion::calculo(Fraccion obj1, Fraccion obj2) {
    int nuevo_numerador = obj1.getNumerador() * obj2.getDenominador() + obj1.getDenominador() * obj2.getNumerador();
    int nuevo_denominador = obj1.getDenominador() * obj2.getDenominador();
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

float Fraccion::calculo(float obj1, float obj2) {
    return obj1/obj2;
}