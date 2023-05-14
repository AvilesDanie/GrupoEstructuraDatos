#pragma once
#include "Proceso.h"
/***********************************************************************
 * Module:  Fraccion.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 10 de mayo de 2023 8:20:15
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(FRACCION_H)
#define FRACCION_H

class Fraccion{
protected:
private:
    float numerador;
    float denominador;

public:
    float getNumerador(void);
    void setNumerador(float newNumerador);
    float getDenominador(void);
    void setDenominador(float newDenominador);
    Fraccion(float num, float den);
    ~Fraccion();

    void simplificar();
    void imprimir();
private:
    int calcular_mcd(int a, int b);
};

#endif

