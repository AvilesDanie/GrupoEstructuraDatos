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
	//m�todos de los atributos
	PilaChar();
	void setPrimero(NodoChar*);
	void setActual(NodoChar*);
	NodoChar* getPrimero();
	NodoChar* getActual();
	bool getPilaVacia();
	//m�todos de orden de la lista
	void push(char);
	void pop();
	void mostrar();
	void buscar(char);
	int contar();
	//void buscar(int);
};