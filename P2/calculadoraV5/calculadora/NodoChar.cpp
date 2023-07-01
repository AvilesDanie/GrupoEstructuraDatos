#include "NodoChar.h"
NodoChar::NodoChar(char _valor, NodoChar* _siguiente)
{
	this->valor = _valor;
	this->siguiente = _siguiente;
	this->index = 0;
}

char NodoChar::getValor() {
	return valor;
}
void NodoChar::setValor(char newValor)
{
	valor = newValor;
}
NodoChar* NodoChar::getSiguiente(void)
{
	return siguiente;
}
void NodoChar::setSiguiente(NodoChar* newSiguiente)
{
	siguiente = newSiguiente;
}

int NodoChar::getIndex()
{
	return index;
}

void NodoChar::setIndex(int i)
{
	index = i;
}

NodoChar::~NodoChar() {

}
