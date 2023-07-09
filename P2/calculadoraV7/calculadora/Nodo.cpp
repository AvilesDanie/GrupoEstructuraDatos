/***********************************************************************
 * Module:  Nodo.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 4 de julio de 2023
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/
#include"Nodo.h"

 /**
 * Constructor
 *
 * @param string _valor. Valor almacenado en el nodo
 * @param Nodo* _siguiente. Puntero que apunta al siguiente nodo
 **/
Nodo::Nodo(string _valor, Nodo* _siguiente)
{
	this->valor = _valor;
	this->siguiente = _siguiente;
	this->index = 0;
}

/**
 * Devuelve el atributo valor
 *
 * @return string valor. El atributo valor.
 **/
string Nodo::getValor() {
	return valor;
}

/**
 * Cambia el valor del atributo valor
 *
 * @param string newValor. Dato al que se quiere cambiar.
 **/
void Nodo::setValor(string newValor)
{
	valor = newValor;
}

/**
 * Devuelve el atributo siguiente
 *
 * @return Nodo* siguiente. El atributo siguiente.
 **/
Nodo* Nodo::getSiguiente(void)
{
	return siguiente;
}

/**
 * Cambia el valor del atributo siguiente
 *
 * @param Nodo newSiguiente. Dato al que se quiere cambiar.
 **/
void Nodo::setSiguiente(Nodo* newSiguiente)
{
	siguiente = newSiguiente;
}

/**
 * Devuelve el atributo index
 *
 * @return int index. El atributo index.
 **/
int Nodo::getIndex()
{
	return index;
}

/**
 * Devuelve el atributo index
 *
 * @return int index. El atributo index.
 **/
void Nodo::setIndex(int i)
{
	index = i;
}

/**
 * Destructor
 **/
Nodo::~Nodo() {
	
}