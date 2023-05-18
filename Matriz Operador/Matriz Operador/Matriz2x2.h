/***********************************************************************
 * Module:  Matriz2x2.h
 * Authors:  Aviles, Reyes
 * Modified: Jueves, 18 de mayo de 2023 08:45:26
 * Purpose: Declaracion de la clase Matriz2x2.h
 ***********************************************************************/
#pragma once
#ifndef MATRIZ2X2_H
#define MATRIZ2X2_H

template<typename T>
class Matriz2x2 {
private:
    T elementos[2][2];

public:
    Matriz2x2(int e1, int e2, int e3, int e4);

    T getElemento(int fila, int columna) const;

    void setElemento(int fila, int columna, T valor);

    void imprimir();

    Matriz2x2<T> operator +(const Matriz2x2& other) const;

    Matriz2x2<T> operator -(const Matriz2x2& other) const;

    Matriz2x2<T> operator *(const Matriz2x2& other) const;

    bool operator ==(const Matriz2x2& other) const;
};

#endif