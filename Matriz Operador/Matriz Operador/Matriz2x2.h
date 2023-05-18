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

    void imprimir() const;

    Matriz2x2<T> operator+(const Matriz2x2& other) const;

    Matriz2x2<T> operator-(const Matriz2x2& other) const;

};

#endif