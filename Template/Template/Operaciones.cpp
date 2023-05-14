#include "Operaciones.h"
#include "Fraccion.h"
#include <iostream>

using namespace std;

Operaciones::Operaciones(){}

Operaciones::~Operaciones(){
  
}

Fraccion<float> Operaciones::calculo(Fraccion<float> obj1, Fraccion<float> obj2) {
    float nuevo_numerador = obj1.getNumerador() * obj2.getDenominador() + obj1.getDenominador() * obj2.getNumerador();
    float nuevo_denominador = obj1.getDenominador() * obj2.getDenominador();
    return Fraccion<float>(nuevo_numerador, nuevo_denominador);
}

float Operaciones::calculo(float obj1, float obj2) {
    return obj1 / obj2;
}