//Prohibido Modificar este Código 
#pragma once
#include "NodoDoble.h"
//#include "Persona.cpp"
class ListaCircularDoble
{
private:
	NodoDoble* cabeza;
	NodoDoble* cola;
public:
	ListaCircularDoble();
	~ListaCircularDoble();
	void insertar(Persona);
	void eliminarCedula(string);
	void mostrar();
	void buscarCedula(string cedula);
	int dimencion();
	Persona getPosicion(int indice);
};


