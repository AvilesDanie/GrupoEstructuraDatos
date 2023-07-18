/***********************************************************************
 * Module:  NodoDoble.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class NodoDoble
 ***********************************************************************/
#include "NodoEmpleado.h"

 /**
 * Constructor
 *
 * @param int dato Data asignado para el atributo dato
 **/
NodoEmpleado::NodoEmpleado(Empleado dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

/**
* Destructor
**/
NodoEmpleado::~NodoEmpleado()
{
}

/**
 * Cambia el valor del atributo dato
 *
 * @param int newValor. Dato al que se quiere cambiar.
 **/
void NodoEmpleado::setDato(Empleado dato)
{
	this->dato = dato;
}

/**
 * Devuelve el atributo dato
 *
 * @return int dato. El atributo dato.
 **/
Empleado NodoEmpleado::getDato()
{
	return this->dato;
}

/**
 * Cambia el valor del atributo siguiente
 *
 * @param NodoNodoDoble* siguiente. Dato al que se quiere cambiar.
 **/
void NodoEmpleado::setSiguiente(NodoEmpleado* siguiente)
{
	this->siguiente = siguiente;
}

/**
 * Devuelve el atributo siguiente
 *
 * @return NodoDoble* siguiente. El atributo siguiente.
 **/
NodoEmpleado* NodoEmpleado::getSiguiente()
{
	return this->siguiente;
}

/**
 * Cambia el valor del atributo anterior
 *
 * @param NodoNodoDoble* anterior. Dato al que se quiere cambiar.
 **/
void NodoEmpleado::setAnterior(NodoEmpleado* anterior)
{
	this->anterior = anterior;
}

/**
 * Devuelve el atributo anterior
 *
 * @return NodoDoble* anterior. El atributo anterior.
 **/
NodoEmpleado* NodoEmpleado::getAnterior()
{
	return this->anterior;
}