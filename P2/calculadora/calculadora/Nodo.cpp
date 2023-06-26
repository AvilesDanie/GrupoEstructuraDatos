#include"Nodo.h"

Nodo::Nodo(string _valor, Nodo* _siguiente)
{
	this->valor = _valor;
	this->siguiente = _siguiente;
	this->index = 0;
}

string Nodo::getValor() {
	return valor;
}
void Nodo::setValor(string newValor)
{
	valor = newValor;
}
Nodo* Nodo::getSiguiente(void)
{
	return siguiente;
}
void Nodo::setSiguiente(Nodo* newSiguiente)
{
	siguiente = newSiguiente;
}

int Nodo::getIndex()
{
	return index;
}

void Nodo::setIndex(int i)
{
	index = i;
}

Nodo::~Nodo() {

}
