/***********************************************************************
 * Module:  NodoChar.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 4 de julio de 2023
 * Purpose: Declaration of the class NodoChar
 ***********************************************************************/
#include "NodoChar.h"

 /**
  * Constructor
  *
  * @param char _valor. Valor almacenado en el nodo
  * @param NodoChar* _siguiente. Puntero que apunta al siguiente nodo
  **/
NodoChar::NodoChar(char _valor, NodoChar* _siguiente)
{
	this->valor = _valor;
	this->siguiente = _siguiente;
	this->index = 0;
}

/**
 * Devuelve el atributo valor
 *
 * @return char valor. El atributo valor.
 **/
char NodoChar::getValor() {
	return valor;
}

/**
 * Cambia el valor del atributo valor
 *
 * @param char newValor. Dato al que se quiere cambiar.
 **/
void NodoChar::setValor(char newValor)
{
	valor = newValor;
}

/**
 * Devuelve el atributo siguiente
 *
 * @return NodoChar* siguiente. El atributo siguiente.
 **/
NodoChar* NodoChar::getSiguiente(void)
{
	return siguiente;
}

/**
 * Cambia el valor del atributo siguiente
 *
 * @param NodoChar newSiguiente. Dato al que se quiere cambiar.
 **/
void NodoChar::setSiguiente(NodoChar* newSiguiente)
{
	siguiente = newSiguiente;
}

/**
 * Devuelve el atributo index
 *
 * @return int index. El atributo index.
 **/
int NodoChar::getIndex()
{
	return index;
}

/**
 * Devuelve el atributo index
 *
 * @return int index. El atributo index.
 **/
void NodoChar::setIndex(int i)
{
	index = i;
}

/**
 * Destructor
 **/
NodoChar::~NodoChar() {

}