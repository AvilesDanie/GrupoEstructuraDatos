#include "Pila.h"
#pragma once
Pila::Pila()
{
	this->primero = NULL;
	this->actual = NULL;
}
bool Pila::getPilaVacia()
{
	return (this->primero == NULL);
}

void Pila::setPrimero(Nodo* first)
{
	primero = first;
}
void Pila::setActual(Nodo* now)
{
	actual = now;
}
Nodo* Pila::getPrimero()
{
	return primero;
}
Nodo* Pila::getActual()
{
	return actual;
}

//métodos de orden de la lista
void Pila::push(string valor)
{
	if (getPilaVacia())
	{
		Nodo* nuevo = new Nodo(valor, NULL);
		nuevo->setSiguiente(this->primero);
		setPrimero(nuevo);
	}
	else
	{
		Nodo* nuevo = new Nodo(valor, NULL);
		nuevo->setSiguiente(this->primero);
		nuevo->setIndex(contar() + 1);
		setPrimero(nuevo);



		/*Nodo *aux = primero;
		Nodo *aux2;

		while(aux->getSiguiente()!=NULL)
		{
			aux2 = aux->getSiguiente();
			aux2->setIndex((aux->getIndex())+1);

			aux = aux->getSiguiente();
		}*/
	}

}

void Pila::pop()
{
	if (getPilaVacia())
	{
		cout << "\nNo se puede eliminar elementos de una pila sin objetos." << endl;
	}
	else
	{
		Nodo* nodoAuxiliar = primero->getSiguiente();
		delete primero;
		setPrimero(nodoAuxiliar);
	}
}

void Pila::mostrar()
{
	Nodo* aux = this->primero;
	while (aux != NULL)
	{
		cout << "Pos " << aux->getIndex() << ": " << aux->getValor() << endl;
		aux = aux->getSiguiente();
	}
}

void Pila::buscar(string n)
{
	Nodo* nodoAuxiliar = primero;
	bool encontrado = false;
	for (int x = 0; x <= contar(); x++)
	{
		if (nodoAuxiliar->getValor() == n)
		{
			encontrado = true;
			break;
		}
		nodoAuxiliar = nodoAuxiliar->getSiguiente();
	}
	if (encontrado)
	{
		cout << "\nEl valor es: " << nodoAuxiliar->getValor() << endl;
		printf("\nEl indice del valor encontrado es: %d\n", nodoAuxiliar->getIndex());
	}
	else
	{
		cout << "\nNo se ha encontrado el valor ingresado." << endl;
	}
}

int Pila::contar()
{
	int i = 0;
	Nodo* nodoAuxiliar = primero;
	while (nodoAuxiliar->getSiguiente() != NULL)
	{
		nodoAuxiliar = nodoAuxiliar->getSiguiente();
		i++;
	}
	return i;
}
