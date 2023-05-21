#pragma once
#include "Matriz.h"
class Operaciones {
public:
	Operaciones();
	Operaciones(Matriz);
	void segmentar();
	void encerar();
	int** generar();
	void procesarPot(int,int**);
	void procesarMulti();
	void imprimir();
	Matriz getMatriz();

private:
	Matriz _matriz;
};