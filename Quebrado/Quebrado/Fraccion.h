#pragma once
/***********************************************************************
 * Module:  Fraccion.h
 * Author:  Fernando
 * Modified: mi�rcoles, 10 de mayo de 2023 8:20:15
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#include "Proceso.h"
#if !defined(__Class_Diagram_1_Fraccion_h)
#define __Class_Diagram_1_Fraccion_h

class Fraccion : public Proceso{
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

    Fraccion();

    /*
    * 
    Fraccion suma(Fraccion resultado);
    Fraccion resta(Fraccion resultado);
    Fraccion multiplicacion(Fraccion resultado);
    Fraccion division(Fraccion resultado);
    
    */
    
    void simplificar();
    void imprimir();
    float calculo(float obj1, float obj2)override;

private:
    int calcular_mcd(int a, int b);
};

#endif

