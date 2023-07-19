/***********************************************************************
 * Module:  ListaCircularDoble.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/
#include "ListaEmpleados.h"
#include <iostream>
using namespace std;

/**
 * Constructor
 **/
ListaEmpleados::ListaEmpleados()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}

/**
 * Destructor
 **/
ListaEmpleados::~ListaEmpleados()
{
}

/**
* Inserta un elemento a la insertar
*
* @param int valor. Valor que se quiere insertar en la lista
**/
void ListaEmpleados::insertar(Empleado dato)
{
	NodoEmpleado* nuevo = new NodoEmpleado(dato);
	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevo;
		this->cola = nuevo;
		this->cabeza->setSiguiente(this->cola);
		this->cabeza->setAnterior(this->cola);
		this->cola->setSiguiente(this->cabeza);
		this->cola->setAnterior(this->cabeza);
	}
	else
	{
		this->cola->setSiguiente(nuevo);
		nuevo->setAnterior(this->cola);
		nuevo->setSiguiente(this->cabeza);
		this->cabeza->setAnterior(nuevo);
		this->cola = nuevo;
	}
}

/**
* Elimina un elemento de la lista dependiendo del valor seleccionado
*
* @param int valor. Valor que se quiere insertar en la pila
**/
void ListaEmpleados::eliminar(string dato)
{
	if (this->cabeza != nullptr)
	{
		if (this->cabeza->getDato().getCedula() == dato)
		{
			NodoEmpleado* aux = this->cabeza;
			this->cabeza = this->cabeza->getSiguiente();
			this->cabeza->setAnterior(this->cola);
			this->cola->setSiguiente(this->cabeza);
			delete aux;
		}
		else
		{
			NodoEmpleado* aux = this->cabeza;
			while (aux->getSiguiente() != this->cabeza)
			{
				if (aux->getSiguiente()->getDato().getCedula() == dato)
				{
					NodoEmpleado* aux2 = aux->getSiguiente();
					aux->setSiguiente(aux2->getSiguiente());
					aux2->getSiguiente()->setAnterior(aux);
					delete aux2;
					break;
				}
				aux = aux->getSiguiente();
			}
		}
	}
}

/**
* Impirme los elementos de la lista
**/
void ListaEmpleados::mostrar()
{
	if (this->cabeza != nullptr)
	{
		NodoEmpleado* aux = this->cabeza;
		do
		{
			aux->getDato().imprimir();
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		cout << endl;
	}
}

/**
* Busca un elemento de que se encuentre en la lista
*
* @param string n. Elemento a buscar
*
* @retur Devuelve un booleano dependiendo de si se encuenta o no el elemento en la lista
**/
bool ListaEmpleados::buscar(string dato)
{
	if (this->cabeza != nullptr)
	{
		NodoEmpleado* aux = this->cabeza;
		do
		{
			if (aux->getDato().getCedula() == dato)
			{
				return true;
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}
	return false;
}

/**
* Devuelve el atributo cabeza
*
* @return NodoDouble* cabeza
**/
NodoEmpleado* ListaEmpleados::getCabeza() {
	return cabeza;
}

/**
* Devuelve el atributo cola
*
* @return NodoDouble* cola
**/
NodoEmpleado* ListaEmpleados::getCola() {
	return cola;
}

/**
* Cuenta la cantidad de elementos que existe dentro de la lista.
*
* @return Un entero con el numero de elementos incluyendo el 0
**/
int ListaEmpleados::dimencion() {
	NodoEmpleado* aux = cabeza;
	int dim = 0;

	if (aux != nullptr) {

		aux = aux->getSiguiente();
		dim += 1;
		while (aux != cabeza) {
			aux = aux->getSiguiente();
			dim += 1;
		}
		return dim;
	}

	return dim;

	
}

/**
* Devuelve el valor del elemento de una lista dependiendo de en que posicion se encuentre.
*
* @param int Indice posicion en la que se quiere buscar
*
* @return El valor de  elemento en la posicion propuesta
**/
Empleado ListaEmpleados::getPosicion(int indice) {
	NodoEmpleado* aux = cabeza;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}

/**
* Cambia el valor de un elemento dependiendo de la posicion de la que se encuentre
*
* @param int dato Dato por el cual  se quiere sustituir al valor del elemento seleccionado
* @param int Indice posicion en la que se quiere buscar
**/
void ListaEmpleados::setPosicion(Empleado dato, int indice) {
	NodoEmpleado* aux = cabeza;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	aux->setDato(dato);
}


Empleado ListaEmpleados::Recuperar(string dato)
{
	if (this->cabeza != nullptr)
	{
		NodoEmpleado* aux = this->cabeza;
		do
		{
			if (aux->getDato().getCedula() == dato)
			{
				return aux->getDato();
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}
}