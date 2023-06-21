#include "ListaCircularDoble.h"
#include <iostream>
using namespace std;
ListaCircularDoble::ListaCircularDoble()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}

ListaCircularDoble::~ListaCircularDoble()
{
}

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



NodoDoble* ListaCircularDoble::getCabeza() {
	return cabeza;
}

NodoDoble* ListaCircularDoble::getCola() {
	return cola;
}





void ListaCircularDoble::intercambiarRecursivo(NodoDoble* actual, NodoDoble* siguiente, bool intercambio)
{


	//do
	//{
		intercambio = false;
		siguiente = actual->getSiguiente();

		while (siguiente != this->cabeza)
		{
			if (actual->getDato() > siguiente->getDato())
			{
				int temp = actual->getDato();
				actual->setDato(siguiente->getDato());
				siguiente->setDato(temp);
				intercambio = true;

			}
			siguiente = siguiente->getSiguiente();
		}

		actual = actual->getSiguiente();
	////} while (intercambio);


	if (intercambio) {
		intercambiarRecursivo(actual, siguiente, intercambio);
	}
	else {
		return;
	}

}