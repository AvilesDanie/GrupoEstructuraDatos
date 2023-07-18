#pragma once
#include "Empleado.h"
class NodoEmpleado
{
private:
	Empleado dato;
	NodoEmpleado* siguiente;
	NodoEmpleado* anterior;
public:
	NodoEmpleado(Empleado);
	~NodoEmpleado();
	void setDato(Empleado);
	Empleado getDato();
	void setSiguiente(NodoEmpleado*);
	NodoEmpleado* getSiguiente();
	void setAnterior(NodoEmpleado*);
	NodoEmpleado* getAnterior();
};

