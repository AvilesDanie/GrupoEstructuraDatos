/***********************************************************************
 * Module:  ListaCircularDoble.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/
#include "ListaCircularDoble.h"
#include <iostream>
using namespace std;

/**
 * Constructor
 **/
ListaCircularDoble::ListaCircularDoble()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}

/**
 * Destructor
 **/
ListaCircularDoble::~ListaCircularDoble()
{
}

/**
* Inserta un elemento a la insertar
*
* @param int valor. Valor que se quiere insertar en la lista
**/
void ListaCircularDoble::insertar(int dato)
{
	NodoDoble* nuevo = new NodoDoble(dato);
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
void ListaCircularDoble::eliminar(int dato)
{
	if (this->cabeza != nullptr)
	{
		if (this->cabeza->getDato() == dato)
		{
			NodoDoble* aux = this->cabeza;
			this->cabeza = this->cabeza->getSiguiente();
			this->cabeza->setAnterior(this->cola);
			this->cola->setSiguiente(this->cabeza);
			delete aux;
		}
		else
		{
			NodoDoble* aux = this->cabeza;
			while (aux->getSiguiente() != this->cabeza)
			{
				if (aux->getSiguiente()->getDato() == dato)
				{
					NodoDoble* aux2 = aux->getSiguiente();
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
void ListaCircularDoble::mostrar()
{
	if (this->cabeza != nullptr)
	{
		NodoDoble* aux = this->cabeza;
		do
		{
			cout << aux->getDato() << " ";
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
bool ListaCircularDoble::buscar(int dato)
{
	if (this->cabeza != nullptr)
	{
		NodoDoble* aux = this->cabeza;
		do
		{
			if (aux->getDato() == dato)
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
NodoDoble* ListaCircularDoble::getCabeza() {
	return cabeza;
}

/**
* Devuelve el atributo cola
*
* @return NodoDouble* cola
**/
NodoDoble* ListaCircularDoble::getCola() {
	return cola;
}

/**
* Funcion de ordemaniento burbuja de forma recursiva
*
* @param NodoDoble* actual Posicion en la lista en la que se enncuentra
* @param NodoDoble* siguiente Posicion siguiente a la del parametro actual
* @param bool intercambio Boolenao que comprueva si el ordenamiento esta completo o no
* @param int temp Dato temporal para el intercambio de los valores entre los elementos de la lista
**/
void ListaCircularDoble::intercambiarRecursivo(NodoDoble* actual, NodoDoble* siguiente, bool intercambio, int temp)
{
	intercambio = false;
	siguiente = actual->getSiguiente();

	if (siguiente != this->cabeza)
	{
		if (actual->getDato() > siguiente->getDato())
		{
			temp = actual->getDato();
			actual->setDato(siguiente->getDato());
			siguiente->setDato(temp);
			intercambio = true;

		}
		actual = siguiente;
		siguiente = siguiente->getSiguiente();
		intercambiarRecursivo(actual, siguiente, intercambio,0);
	}

	if (intercambio) {
		intercambiarRecursivo(cabeza, cabeza->getSiguiente(), intercambio,0);
	}
	else {
		return;
	}
}

/**
* Cuenta la cantidad de elementos que existe dentro de la lista.
*
* @return Un entero con el numero de elementos incluyendo el 0
**/
int ListaCircularDoble::dimencion() {
	NodoDoble* aux = cabeza;
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
int ListaCircularDoble::getPosicion(int indice) {
	NodoDoble* aux = cabeza;
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
void ListaCircularDoble::setPosicion(int dato,int indice) {
	NodoDoble* aux = cabeza;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	aux->setDato(dato);
}

/**
* Calcula el valor maximo presente en los elementos de la lista
*
* @return Entero con el valor maximo de la lista
**/
int ListaCircularDoble::calcularValorMaximo() {
	int maximo = getPosicion(1);
	for (int i = 1; i < dimencion(); i++) {
		if (getPosicion(i+1) > maximo) {
			maximo = getPosicion(i+1);
		}
	}
	return maximo;
}

/**
* Calcula el valor minimo presente en los elementos de la lista
*
* @return Entero con el valor minimo de la lista
**/
int ListaCircularDoble::calcularValorMinimo() {
	int minimo = getPosicion(1);
	for (int i = 1; i < dimencion(); i++) {
		if (getPosicion(i + 1) < minimo) {
			minimo = getPosicion(i + 1);
		}
	}
	return minimo;
}

/**
* Funcion de ordemaniento por distribucion.
* Utilizando listas.
**/
void ListaCircularDoble::distribucion() {
	if (cabeza != nullptr) {
		int maximo = calcularValorMaximo();
		int minimo = calcularValorMinimo();
		ListaCircularDoble conteo;
		ListaCircularDoble lista;

		for (int i = 0; i < dimencion(); i++) {
			lista.insertar(0);
		}

		for (int i = 0; i < maximo-minimo + 1; i++) {
			conteo.insertar(0);
		}

		for (int i = 0; i < dimencion(); i++) {
			int dato = conteo.getPosicion(getPosicion(i)-minimo);
			dato++;
			conteo.setPosicion(dato, getPosicion(i)-minimo);
		}
		
		for (int i = 1; i <= maximo-minimo; i++) {
			conteo.setPosicion(conteo.getPosicion(i) + conteo.getPosicion(i - 1), i);
		}
		
		for (int i = 0; i < dimencion(); i++) {
			lista.setPosicion(getPosicion(i), conteo.getPosicion(getPosicion(i)-minimo) - 1);
			conteo.setPosicion(conteo.getPosicion(getPosicion(i) - minimo) - 1, getPosicion(i)-minimo);
		}

		for (int i = 0; i < dimencion(); i++) {
			setPosicion(lista.getPosicion(i), i);
		}
	}
	else
		std::cout << "La lista esta vacia" << std::endl;
}