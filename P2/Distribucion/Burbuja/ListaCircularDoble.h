#pragma once
#include "NodoDoble.h"
class ListaCircularDoble
{
private:
	NodoDoble* cabeza;
	NodoDoble* cola;
public:
	ListaCircularDoble();
	~ListaCircularDoble();
	void insertar(int);
	void eliminar(int);
	void mostrar();
	bool buscar(int);

	NodoDoble* getCabeza();
	NodoDoble* getCola();


	void intercambiarRecursivo(NodoDoble*, NodoDoble*, bool, int);




	int dimencion();
	int getPosicion(int);
	void setPosicion(int,int);
	int calcularValorMaximo();
	int calcularValorMinimo();
	void distribucion();
};


