/***********************************************************************
 * Module:  Operaciones.cpp
 * Author:  Aviles, Reyes
 * Modified: Domingo, 14 de mayo de 2023 12:31:19
 * Purpose: Implementation of the class Operaciones.cpp
 ***********************************************************************/
#include "Operaciones.h"
#include "Fraccion.h"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::Operaciones()
// Purpose:    Implementation of Operaciones::Operaciones()
// Return:     
////////////////////////////////////////////////////////////////////////

Operaciones::Operaciones(){}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::~Operaciones()
// Purpose:    Implementation of Operaciones::~Operaciones()
// Return:     
////////////////////////////////////////////////////////////////////////

Operaciones::~Operaciones(){
  
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::calculo(Fraccion<float> obj1, Fraccion<float> obj2)
// Purpose:    Implementation of Operaciones::calculo()
// Parameters:
// - obj1
// - obj2
// Return:     Fraccion<float>
////////////////////////////////////////////////////////////////////////

Fraccion<float> Operaciones::calculo(Fraccion<float> obj1, Fraccion<float> obj2) {
    float nuevo_numerador = obj1.getNumerador() * obj2.getDenominador() + obj1.getDenominador() * obj2.getNumerador();
    float nuevo_denominador = obj1.getDenominador() * obj2.getDenominador();
    return Fraccion<float>(nuevo_numerador, nuevo_denominador);
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::calculo(float obj1, float obj2)
// Purpose:    Implementation of Operaciones::calculo()
// Parameters:
// - obj1
// - obj2
// Return:     float
////////////////////////////////////////////////////////////////////////

float Operaciones::calculo(float obj1, float obj2) {
    return obj1 / obj2;
}