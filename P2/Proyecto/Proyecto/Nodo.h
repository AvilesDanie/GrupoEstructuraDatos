#pragma once
#include <iostream>
#include <stdio.h>
#include "Persona.h"
using namespace std;
class Nodo
{
public:
	Persona getValor();
	Nodo*& getDerecha();
	Nodo*& getIzquierda();
	Nodo*& getNivel();
	void setValor(Persona);
	void setDerecha(Nodo*);
	void setIzquierda(Nodo*);

private:
	Persona valor;
	Nodo* derecha;
	Nodo* izquierda;
	Nodo* nivel;
};

