/***********************************************************************
 * Module:  ListaCircularDoble.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/
#pragma once
#include "NodoRegistro.h"
#include "Registro.h"
#include <iostream>
#include <string>
class ListaRegistro
{
private:
	NodoRegistro* cabeza;
	NodoRegistro* cola;
public:
	ListaRegistro();
	~ListaRegistro();
	void insertar(Registro);
	void eliminar(std::string);
	void mostrar();
	bool buscar(std::string);

	NodoRegistro* getCabeza();
	NodoRegistro* getCola();

	int dimencion();
	Registro getPosicion(int);
	void setPosicion(Registro, int);

};

