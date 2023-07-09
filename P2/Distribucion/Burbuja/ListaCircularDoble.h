/***********************************************************************
 * Module:  ListaCircularDoble.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/
#pragma once
#include "NodoDoble.h"
class ListaCircularDoble
{
private:
	NodoDoble* cabeza;
	NodoDoble* cola;
public:
	ListaCircularDoble();
	~ListaCircularDoble();
	void insertar(int);
	void eliminar(int);
	void mostrar();
	bool buscar(int);

	NodoDoble* getCabeza();
	NodoDoble* getCola();

	void intercambiarRecursivo(NodoDoble*, NodoDoble*, bool, int);

	int dimencion();
	int getPosicion(int);
	void setPosicion(int,int);
	int calcularValorMaximo();
	int calcularValorMinimo();
	void distribucion();
};


