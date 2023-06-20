//Prohibido Modificar este Código 
#pragma once
#include "Persona.h"
class NodoDoble
{
private:
	Persona persona;
	NodoDoble* siguiente;
	NodoDoble* anterior;
public:
	NodoDoble(Persona);
	~NodoDoble();
	void setDato(Persona);
	Persona getDato();
	void setSiguiente(NodoDoble*);
	NodoDoble* getSiguiente();
	void setAnterior(NodoDoble*);
	NodoDoble* getAnterior();
};


