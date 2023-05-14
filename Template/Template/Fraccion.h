#pragma once
/***********************************************************************
 * Module:  Fraccion.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 10 de mayo de 2023 8:20:15
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(FRACCION_H)
#define FRACCION_H

template <typename T>
class Fraccion{
protected:
private:
    T numerador;
    T denominador;

public:
    T getNumerador(void);
    void setNumerador(T newNumerador);
    T getDenominador(void);
    void setDenominador(T newDenominador);
    Fraccion(T num, T den);
    ~Fraccion();

    void simplificar();
    void imprimir();
private:
    T calcular_mcd(T a, T b);
};

#endif

