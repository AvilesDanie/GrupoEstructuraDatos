#pragma once
/***********************************************************************
 * Module:  Fraccion.h
 * Authors:  Aviles, Reyes
 * Modified: Domingo, 14 de mayo de 2023 16:25:15
 * Purpose: Declaracion de la clase Fraccion.h
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
    int calcular_mcd(T a, T b);
};

#endif

