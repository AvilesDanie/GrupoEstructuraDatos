#include "Operaciones.h"
#include "Fraccion.h"
#include "Proceso.h"
#include <iostream>

using namespace std;

Operaciones::Operaciones(){}

Operaciones::~Operaciones(){
  
}

Fraccion Operaciones::calculo(Fraccion obj1, Fraccion obj2) {
    int nuevo_numerador = obj1.getNumerador() * obj2.getDenominador() + obj1.getDenominador() * obj2.getNumerador();
    int nuevo_denominador = obj1.getDenominador() * obj2.getDenominador();
    return Fraccion(nuevo_numerador, nuevo_denominador);
}

float Operaciones::calculo(float obj1, float obj2) {
    return obj1 / obj2;
}