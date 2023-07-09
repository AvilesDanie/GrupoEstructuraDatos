/***********************************************************************
* Module:  PilaChar.cpp
* Authors:  Aviles, Reyes
* Modified: miércoles, 5 de julio de 2023
* Purpose: Declaration of the class PilaChar
***********************************************************************/
#include "PilaChar.h"
#pragma once

/**
* Costructor
**/
PilaChar::PilaChar()
{
	this->primero = NULL;
	this->actual = NULL;
}

/**
* Comprueba se la pila esta vacia
*
* @return booleano
**/
bool PilaChar::getPilaVacia()
{
	return (this->primero == NULL);
}

/**
* Cambia el atributo primero
*
* @param NodoChar* first. Valor a cambiar
**/
void PilaChar::setPrimero(NodoChar* first)
{
	primero = first;
}

/**
* Cambia el atributo actual
*
* @param NodoChar* now. Valor a cambiar
**/
void PilaChar::setActual(NodoChar* now)
{
	actual = now;
}

/**
* Devuelve el atributo primero
*
* @return NodoChar* primero. El atributo primero
**/
NodoChar* PilaChar::getPrimero()
{
	return primero;
}

/**
* Devuelve el atributo actual
*
* @return NodoChar* actual. El atributo actual
**/
NodoChar* PilaChar::getActual()
{
	return actual;
}

/**
* Inserta un elemento a la pila
*
* @param char valor. Valor que se quiere insertar en la pila
**/
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
	}

}

/**
* Quita un elemento de la pila
**/
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

/**
* Impirme el elemento de la lista
**/
void PilaChar::mostrar()
{
	NodoChar* aux = this->primero;
	while (aux != NULL)
	{
		cout << "Pos " << aux->getIndex() << ": " << aux->getValor() << endl;
		aux = aux->getSiguiente();
	}
}

/**
* Busca un elemento de que se encuentre en la pila
*
* @param char n. Elemento a buscar
**/
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

/**
* Cuenta los elementos de la pila
*
* @return El numero de elementos que hay en la pila
**/
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
