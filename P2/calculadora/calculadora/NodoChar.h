#pragma once

#include <string>
#include <iostream>
using namespace std;

class NodoChar {
private:
	char valor;
	NodoChar* siguiente;
	int index;
public:
	NodoChar(char _valor, NodoChar*);
	char getValor(void);
	void setValor(char newValor);
	int getIndex();
	void setIndex(int);
	NodoChar* getSiguiente(void);
	void setSiguiente(NodoChar* newSiguiente);
	~NodoChar();
};
