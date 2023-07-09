/***********************************************************************
 * Module:  Prefija.h
 * Authors:  Aviles, Reyes
 * Modified: mi�rcoles, 3 de julio de 2023
 * Purpose: Declaration of the class Prefija
 ***********************************************************************/
#pragma once
#include <iostream>
#include "Pila.h"
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "Operaciones.h"

using namespace std;

class Prefija
{
	typedef Prefija Pre;

private:
	int posi;
	Pila pila;
	string* opera = new string[posi];
public:
	string inAPre(string);
	Pila getPila();
	void calcularPila();
	bool contieneSoloNumeros(string str);

	vector<string> separarCadenas(const std::string&, char );
	vector<string> obtenerContenidoEntreParentesis(const std::string&);
}; typedef Prefija Pre;