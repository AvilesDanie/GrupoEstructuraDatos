/***********************************************************************
 * Module:  NodoDoble.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class NodoDoble
 ***********************************************************************/
#include "NodoDoble.h"

/**
* Constructor
* 
* @param int dato Data asignado para el atributo dato
**/
NodoDoble::NodoDoble(int dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

/**
* Destructor
**/
NodoDoble::~NodoDoble()
{
}

/**
 * Cambia el valor del atributo dato
 *
 * @param int newValor. Dato al que se quiere cambiar.
 **/
void NodoDoble::setDato(int dato)
{
	this->dato = dato;
}

/**
 * Devuelve el atributo dato
 *
 * @return int dato. El atributo dato.
 **/
int NodoDoble::getDato()
{
	return this->dato;
}

/**
 * Cambia el valor del atributo siguiente
 *
 * @param NodoNodoDoble* siguiente. Dato al que se quiere cambiar.
 **/
void NodoDoble::setSiguiente(NodoDoble* siguiente)
{
	this->siguiente = siguiente;
}

/**
 * Devuelve el atributo siguiente
 *
 * @return NodoDoble* siguiente. El atributo siguiente.
 **/
NodoDoble* NodoDoble::getSiguiente()
{
	return this->siguiente;
}

/**
 * Cambia el valor del atributo anterior
 *
 * @param NodoNodoDoble* anterior. Dato al que se quiere cambiar.
 **/
void NodoDoble::setAnterior(NodoDoble* anterior)
{
	this->anterior = anterior;
}

/**
 * Devuelve el atributo anterior
 *
 * @return NodoDoble* anterior. El atributo anterior.
 **/
NodoDoble* NodoDoble::getAnterior()
{
	return this->anterior;
}


