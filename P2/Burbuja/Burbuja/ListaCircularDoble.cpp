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


void ListaCircularDoble::ordenarBurbuja()
{
	if (this->cabeza == nullptr)
		return;

	bool intercambio = false;
	do
	{
		intercambio = false;
		NodoDoble* actual = this->cabeza;
		NodoDoble* siguiente = actual->getSiguiente();

		while (siguiente != this->cabeza)
		{
			if (actual->getDato() > siguiente->getDato())
			{
				// Intercambiar los datos de los nodos
				int temp = actual->getDato();
				actual->setDato(siguiente->getDato());
				siguiente->setDato(temp);
				intercambio = true;
			}

			actual = siguiente;
			siguiente = siguiente->getSiguiente();
		}
	} while (intercambio);
}

void ListaCircularDoble::ordenarBurbuja(NodoDoble* actual, NodoDoble* siguiente)
{
	if (siguiente == this->cabeza)
	{
		if (actual->getSiguiente() != this->cabeza)
		{
			ordenarBurbuja(this->cabeza, this->cabeza->getSiguiente());
		}
		return;
	}

	if (actual->getDato() > siguiente->getDato())
	{
		// Intercambiar los datos de los nodos
		int temp = actual->getDato();
		actual->setDato(siguiente->getDato());
		siguiente->setDato(temp);
	}

	ordenarBurbuja(siguiente, siguiente->getSiguiente());
}

/*void ListaCircularDoble::ordenarBurbuja()
{
	if (this->cabeza == nullptr)
		return;

	NodoDoble* actual = this->cabeza;
	NodoDoble* siguiente = actual->getSiguiente();
	ordenarBurbuja(actual, siguiente);
}*/

NodoDoble* ListaCircularDoble::getCabeza() {
	return cabeza;
}
