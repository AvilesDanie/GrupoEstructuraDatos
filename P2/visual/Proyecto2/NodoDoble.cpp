//Prohibido Modificar este Código 
#include "NodoDoble.h"
NodoDoble::NodoDoble(Persona persona)
{
	this->persona = persona;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}
NodoDoble::~NodoDoble()
{
}

void NodoDoble::setDato(Persona persona)
{
	this->persona = persona;
}

Persona NodoDoble::getDato()
{
	return this->persona;
}

void NodoDoble::setSiguiente(NodoDoble* siguiente)
{
	this->siguiente = siguiente;
}

NodoDoble* NodoDoble::getSiguiente()
{
	return this->siguiente;
}

void NodoDoble::setAnterior(NodoDoble* anterior)
{
	this->anterior = anterior;
}

NodoDoble* NodoDoble::getAnterior()
{
	return this->anterior;
}


