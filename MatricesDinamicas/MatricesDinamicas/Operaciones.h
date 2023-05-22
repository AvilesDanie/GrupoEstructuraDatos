#pragma once
#include "Matriz.h"
template <typename T>
class Operaciones {
public:
	Operaciones();
	Operaciones(Matriz<T>);
	void encerar();
	T** generar();
	void imprimir();
	Matriz<T> getMatriz();
	void multiplicacion(Matriz<T>,Matriz<T>,Matriz<T>,int);
private:
	Matriz<T> _matriz;
};