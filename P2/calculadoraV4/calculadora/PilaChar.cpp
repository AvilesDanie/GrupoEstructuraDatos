#include "PilaChar.h"
#pragma once
PilaChar::PilaChar()
{
	this->primero = NULL;
	this->actual = NULL;
}
bool PilaChar::getPilaVacia()
{
	return (this->primero == NULL);
}

void PilaChar::setPrimero(NodoChar* first)
{
	primero = first;
}
void PilaChar::setActual(NodoChar* now)
{
	actual = now;
}
NodoChar* PilaChar::getPrimero()
{
	return primero;
}
NodoChar* PilaChar::getActual()
{
	return actual;
}

//métodos de orden de la lista
void PilaChar::push(char valor)
{
	if (getPilaVacia())
	{
		NodoChar* nuevo = new NodoChar(valor, NULL);
		nuevo->setSiguiente(this->primero);
		setPrimero(nuevo);
		setActual(nuevo);
	}
	else
	{
		NodoChar* nuevo = new NodoChar(valor, NULL);
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

void PilaChar::pop()
{
	if (getPilaVacia())
	{
		cout << "\nNo se puede eliminar elementos de una pila sin objetos." << endl;
	}
	else
	{
		NodoChar* nodoAuxiliar = primero->getSiguiente();
		delete primero;
		setPrimero(nodoAuxiliar);
	}
}

void PilaChar::mostrar()
{
	NodoChar* aux = this->primero;
	while (aux != NULL)
	{
		cout << "Pos " << aux->getIndex() << ": " << aux->getValor() << endl;
		aux = aux->getSiguiente();
	}
}

void PilaChar::buscar(char n)
{
	NodoChar* nodoAuxiliar = primero;
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

int PilaChar::contar()
{
	int i = 0;
	NodoChar* nodoAuxiliar = primero;
	while (nodoAuxiliar->getSiguiente() != NULL)
	{
		nodoAuxiliar = nodoAuxiliar->getSiguiente();
		i++;
	}
	setActual(nodoAuxiliar);
	return i;
}
