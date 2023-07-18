#pragma once
#include "NodoEmpleado.h"
#include "Empleado.h"
#include <iostream>
#include <string>
class ListaEmpleados
{
private:
	NodoEmpleado* cabeza;
	NodoEmpleado* cola;
public:
	ListaEmpleados();
	~ListaEmpleados();
	void insertar(Empleado);
	void eliminar(std::string);
	void mostrar();
	bool buscar(std::string);

	NodoEmpleado* getCabeza();
	NodoEmpleado* getCola();

	int dimencion();
	Empleado getPosicion(int);
	void setPosicion(Empleado, int);
};

