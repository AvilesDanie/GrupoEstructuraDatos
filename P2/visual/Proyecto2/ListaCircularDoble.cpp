//Prohibido Modificar este Código 
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

void ListaCircularDoble::insertar(Persona dato)
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

void ListaCircularDoble::eliminarCedula(string cedula)
{
	if (this->cabeza != nullptr)
	{
		Persona p1=this->cabeza->getDato();
		if (p1.getCedula() == cedula && cabeza == cola)
		{
			NodoDoble* aux = this->cabeza;
			this->cabeza = nullptr;
			this->cola = nullptr;
			delete aux;
			cout << "\nSe elimino a la persona " << endl;
			return;

		}
		else if (p1.getCedula() == cedula)
		{
			NodoDoble* aux = this->cabeza;
			this->cabeza = this->cabeza->getSiguiente();
			this->cabeza->setAnterior(this->cola);
			this->cola->setSiguiente(this->cabeza);
			delete aux;
			cout << "\nSe elimino a la persona " << endl;
			return;
		}

		else
		{
			NodoDoble* aux = this->cabeza;
			p1=aux->getDato();
			while (aux->getSiguiente() != this->cabeza)
			{
				if (aux->getSiguiente()->getDato().getCedula() == cedula)
				{
					NodoDoble* aux2 = aux->getSiguiente();
					if (aux2 == cola) {
						cola = aux;
					}
					aux->setSiguiente(aux2->getSiguiente());
					aux2->getSiguiente()->setAnterior(aux);
					delete aux2;
					cout << "\nSe elimino a la persona " << endl;

					return;
				}
				aux = aux->getSiguiente();
			}
		}
		

	}
	cout << "\nNo se encontro a la persona " << endl;
}


void ListaCircularDoble::mostrar()
{
	if (this->cabeza != nullptr)
	{
		NodoDoble* aux = this->cabeza;
		do
		{
			Persona p1 = aux->getDato();
			cout << "Cedula: " << p1.getCedula() << endl;
			cout << "Nombre: " << p1.getNombre() << endl;
			cout << "Apellido: " << p1.getApellido() << endl;
			// Imprimir otros atributos de Persona si los hubiera
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		cout << endl;
	}
}


void ListaCircularDoble::buscarCedula(string cedula)
{
	if (this->cabeza != nullptr)
	{
		NodoDoble* aux = this->cabeza;
		Persona p1 = aux->getDato();
		do
		{
			if (p1.getCedula() == cedula)
			{
				Persona p1 = aux->getDato();
				cout << "Se encontro a la Persona " << endl;
				cout << "Nombre: " << p1.getNombre() << endl;
				cout << "Apellido: " << p1.getApellido() << endl;
				cout << "Cedula: " << p1.getCedula() << endl;
			}
			aux = aux->getSiguiente();
			p1 = aux->getDato();
		} while (aux != this->cabeza);
		//cout<<"No se encontro a la persona"<<endl;
	}
	else {
		cout << "No se encontro a la persona" << endl;
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


Persona ListaCircularDoble::getPosicion(int indice) {
	NodoDoble* aux = cabeza;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}