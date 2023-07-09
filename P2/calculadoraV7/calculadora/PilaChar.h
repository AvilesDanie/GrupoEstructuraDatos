/***********************************************************************
 * Module:  PilaChar.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 3 de julio de 2023
 * Purpose: Declaration of the class PilaChar
 ***********************************************************************/
#pragma once
#include "NodoChar.h"
#include <iostream>
#include <string>
using namespace std;
class PilaChar {
private:
	NodoChar* primero;
	NodoChar* actual;
public:
	//métodos de los atributos
	PilaChar();
	void setPrimero(NodoChar*);
	void setActual(NodoChar*);
	NodoChar* getPrimero();
	NodoChar* getActual();
	bool getPilaVacia();
	//métodos de orden de la lista
	void push(char);
	void pop();
	void mostrar();
	void buscar(char);
	int contar();
	//void buscar(int);
};