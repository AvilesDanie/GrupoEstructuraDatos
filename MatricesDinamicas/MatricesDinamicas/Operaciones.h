#pragma once
#include "Matriz.h"
class Operaciones {
public:
	Operaciones();
	Operaciones(Matriz);
	void encerar();
	int** generar();
	void imprimir();
	Matriz getMatriz();

private:
	Matriz _matriz;
};