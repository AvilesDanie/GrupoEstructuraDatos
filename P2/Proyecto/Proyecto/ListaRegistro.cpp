/***********************************************************************
 * Module:  ListaCircularDoble.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/
#include "ListaRegistro.h"
#include <iostream>
using namespace std;

/**
 * Constructor
 **/
ListaRegistro::ListaRegistro()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}

/**
 * Destructor
 **/
ListaRegistro::~ListaRegistro()
{
}

/**
* Inserta un elemento a la insertar
*
* @param int valor. Valor que se quiere insertar en la lista
**/
void ListaRegistro::insertar(Registro dato)
{
	NodoRegistro* nuevo = new NodoRegistro(dato);
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
void ListaRegistro::eliminar(string dato)
{
	if (this->cabeza != nullptr)
	{
		if (this->cabeza->getDato().getEmpleado().getCedula() == dato)
		{
			NodoRegistro* aux = this->cabeza;
			this->cabeza = this->cabeza->getSiguiente();
			this->cabeza->setAnterior(this->cola);
			this->cola->setSiguiente(this->cabeza);
			delete aux;
		}
		else
		{
			NodoRegistro* aux = this->cabeza;
			while (aux->getSiguiente() != this->cabeza)
			{
				if (aux->getSiguiente()->getDato().getEmpleado().getCedula() == dato)
				{
					NodoRegistro* aux2 = aux->getSiguiente();
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
void ListaRegistro::mostrar()
{
	if (this->cabeza != nullptr)
	{
		NodoRegistro* aux = this->cabeza;
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
bool ListaRegistro::buscar(string dato)
{
	if (this->cabeza != nullptr)
	{
		NodoRegistro* aux = this->cabeza;
		do
		{
			if (aux->getDato().getEmpleado().getCedula() == dato)
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
NodoRegistro* ListaRegistro::getCabeza() {
	return cabeza;
}

/**
* Devuelve el atributo cola
*
* @return NodoDouble* cola
**/
NodoRegistro* ListaRegistro::getCola() {
	return cola;
}

/**
* Cuenta la cantidad de elementos que existe dentro de la lista.
*
* @return Un entero con el numero de elementos incluyendo el 0
**/
int ListaRegistro::dimencion() {
	NodoRegistro* aux = cabeza;
	int dim = 0;
	aux = aux->getSiguiente();
	dim += 1;
	while (aux != cabeza) {
		aux = aux->getSiguiente();
		dim += 1;
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
Registro ListaRegistro::getPosicion(int indice) {
	NodoRegistro* aux = cabeza;
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
void ListaRegistro::setPosicion(Registro dato, int indice) {
	NodoRegistro* aux = cabeza;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	aux->setDato(dato);
}




void ListaRegistro::Modificar(Registro dato)
{
	if (this->cabeza != nullptr)
	{
		NodoRegistro* aux = this->cabeza;
		do
		{
			if (aux->getDato().getEmpleado().getCedula() == dato.getEmpleado().getCedula() &&
				aux->getDato().getEntrada().getAnio() == dato.getEntrada().getAnio() &&
				aux->getDato().getEntrada().getMes() == dato.getEntrada().getMes() &&
				aux->getDato().getEntrada().getDia() == dato.getEntrada().getDia())
			{

				aux->setDato(dato);
				return;
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}
}


Registro ListaRegistro::Recuperar(string dato)
{

	if (this->cabeza != nullptr)
	{
		NodoRegistro* aux = this->cabeza;
		do
		{
			if (aux->getDato().getEmpleado().getCedula() == dato)
			{
				return aux->getDato();
			}
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
	}


	Fecha fecha(0,0,0,0,0,0);
	Persona persona;

	Empleado empleado;

	Registro registro(empleado, fecha,fecha,fecha,fecha);

	return registro;


}
