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

int ListaCircularDoble::getPosicion(int indice) {
	NodoDoble* aux = cabeza;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}

void ListaCircularDoble::setPosicion(int min,int dato,int max) {
	NodoDoble* aux = cabeza;
	int diferencia = 1 - min;
	for (int i = 2; i <= dato+diferencia; i++) {
		aux = aux->getSiguiente();
	}
	aux->setDato(dato);
}

int ListaCircularDoble::calcularValorMaximo(int tamanio) {
	int maximo = getPosicion(1);
	for (int i = 1; i < tamanio; i++) {
		if (getPosicion(i+1) > maximo) {
			maximo = getPosicion(i+1);
		}
	}
	return maximo;
}

int ListaCircularDoble::calcularValorMinimo(int tamanio) {
	int minimo = getPosicion(1);
	for (int i = 1; i < tamanio; i++) {
		if (getPosicion(i + 1) < minimo) {
			minimo = getPosicion(i + 1);
		}
	}
	return minimo;
}


ListaCircularDoble ListaCircularDoble::distribucion() {
	int max = calcularValorMaximo(dimencion());
	int min = calcularValorMinimo(dimencion());
	int nulo = min - 1;
	ListaCircularDoble lista;
	NodoDoble* aux = cabeza;
	std::cout << min << "------" << max << std::endl;
	for (int i = min; i <= max; i++) {
		lista.insertar(nulo);
		lista.mostrar();
	}
	std::cout << lista.dimencion() << std::endl;

	for (int i = 1; i <= dimencion(); i++) {
		std::cout <<i<< "=====" << lista.dimencion() << std::endl;
		std::cout << aux->getDato() << std::endl;

		lista.setPosicion(min, aux->getDato(),max);
		aux = aux->getSiguiente();
	}

	int rep = lista.dimencion();
	for (int i = 0; i < rep; i++) {
		lista.eliminar(nulo);
	}

	return lista;
}