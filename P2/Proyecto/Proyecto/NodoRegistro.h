/***********************************************************************
 * Module:  NodoDoble.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class NodoDoble
 ***********************************************************************/
#pragma once
#include "Registro.h"
class NodoRegistro
{
private:
	Registro dato;
	NodoRegistro* siguiente;
	NodoRegistro* anterior;
public:
	NodoRegistro(Registro);
	~NodoRegistro();
	void setDato(Registro);
	Registro getDato();
	void setSiguiente(NodoRegistro*);
	NodoRegistro* getSiguiente();
	void setAnterior(NodoRegistro*);
	NodoRegistro* getAnterior();
};