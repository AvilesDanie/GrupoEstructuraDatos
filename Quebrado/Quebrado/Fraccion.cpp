#include "Fraccion.h"
#include "Proceso.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion(float num, float den)
{
    // TODO : implement
    this->denominador = den;
    this->numerador = num;
}

float Fraccion::getNumerador(void)
{
    return numerador;
}

void Fraccion::setNumerador(float newNumerador)
{
    numerador = newNumerador;
}

float Fraccion::getDenominador(void)
{
    return denominador;
}

void Fraccion::setDenominador(float newDenominador)
{
    denominador = newDenominador;
}

Fraccion::~Fraccion()
{
    // TODO : implement
}

/*

Fraccion Fraccion::suma(Fraccion sumando) {
    int nuevo_numerador = numerador * sumando.denominador + denominador * sumando.numerador;
    int nuevo_denominador = denominador * sumando.denominador;
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

Fraccion Fraccion::resta(Fraccion sustraendo) {
    int nuevo_numerador = numerador * sustraendo.denominador - denominador * sustraendo.numerador;
    int nuevo_denominador = denominador * sustraendo.denominador;
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

Fraccion Fraccion::multiplicacion(Fraccion multiplicador) {
    int nuevo_numerador = numerador * multiplicador.numerador;
    int nuevo_denominador = denominador * multiplicador.denominador;
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

Fraccion Fraccion::division(Fraccion divisor) {
    int nuevo_numerador = numerador * divisor.denominador;
    int nuevo_denominador = denominador * divisor.numerador;
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

*/

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
    return 0.0;
}

//float Fraccion::calculo(float obj1,float obj2) {
//    return obj1 / obj2;
//}
