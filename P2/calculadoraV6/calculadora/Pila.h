#pragma once
#include "Nodo.h"
#include <iostream>
#include <string>
using namespace std;
class Pila {
private:
	Nodo* primero;
	Nodo* actual;
public:
	//métodos de los atributos
	Pila();
	void setPrimero(Nodo*);
	void setActual(Nodo*);
	Nodo* getPrimero();
	Nodo* getActual();
	bool getPilaVacia();
	//métodos de orden de la lista
	void push(string);
	void pop();
	void mostrar();
	void buscar(string);
	int contar();
	//void buscar(int);
};
