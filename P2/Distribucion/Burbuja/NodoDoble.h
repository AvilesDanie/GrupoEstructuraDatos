/***********************************************************************
 * Module:  NodoDoble.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class NodoDoble
 ***********************************************************************/
#pragma once
class NodoDoble
{
private:
	int dato;
	NodoDoble* siguiente;
	NodoDoble* anterior;
public:
	NodoDoble(int);
	~NodoDoble();
	void setDato(int);
	int getDato();
	void setSiguiente(NodoDoble*);
	NodoDoble* getSiguiente();
	void setAnterior(NodoDoble*);
	NodoDoble* getAnterior();
};