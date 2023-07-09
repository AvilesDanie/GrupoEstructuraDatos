/***********************************************************************
* Module:  Pila.cpp
* Authors:  Aviles, Reyes
* Modified: miércoles, 5 de julio de 2023
* Purpose: Declaration of the class Pila
***********************************************************************/
#include "Pila.h"
#pragma once

/**
* Costructor
**/
Pila::Pila()
{
	this->primero = NULL;
	this->actual = NULL;
}

/**
* Comprueba se la pila esta vacia
*
* @return booleano
**/
bool Pila::getPilaVacia()
{
	return (this->primero == NULL);
}

/**
* Cambia el atributo primero
*
* @param Nodo* first. Valor a cambiar
**/
void Pila::setPrimero(Nodo* first)
{
	primero = first;
}

/**
* Cambia el atributo actual
*
* @param Nodo* now. Valor a cambiar
**/
void Pila::setActual(Nodo* now)
{
	actual = now;
}

/**
* Devuelve el atributo primero
* 
* @return Nodo* primero. El atributo primero
**/
Nodo* Pila::getPrimero()
{
	return primero;
}

/**
* Devuelve el atributo actual
*
* @return Nodo* actual. El atributo actual
**/
Nodo* Pila::getActual()
{
	return actual;
}

/**
* Inserta un elemento a la pila
*
* @param string valor. Valor que se quiere insertar en la pila
**/
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
	}

}

/**
* Quita un elemento de la pila
**/
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

/**
* Impirme el elemento de la pila
**/
void Pila::mostrar()
{
	Nodo* aux = this->primero;
	while (aux != NULL)
	{
		cout << "Pos " << aux->getIndex() << ": " << aux->getValor() << endl;
		aux = aux->getSiguiente();
	}
}

/**
* Busca un elemento de que se encuentre en la pila
* 
* @param string n. Elemento a buscar
**/
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

/**
* Cuenta los elementos de la pila
*
* @return El numero de elementos que hay en la pila
**/
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
