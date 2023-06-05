#pragma once
#include <iostream>
class Fecha{
private:
	int dia;
	int mes;
	int a;
public:
	Fecha(int, int, int);
	Fecha();
	int getDia();
	int getMes();
	int getA();
	void setDia(int);
	void setMes(int);
	void setA(int);
	void imprimir();
};

