#pragma once
#include "Matriz.h"
template <typename T>
class Operaciones
{
public:
	Operaciones();
	void sumaRecursivaMatrices(Matriz<T>, Matriz<T>, Matriz<T>, int, int);
	void multiplicarRecursivaMatrices(Matriz<T>, Matriz<T>, Matriz<T>, int, int);
};

