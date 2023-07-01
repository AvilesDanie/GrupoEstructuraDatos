#pragma once
#include <iostream>
#include "Pila.h"
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

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
	int getPosi();
	float resuelve(string);
	float suma(float, float);
	float resta(float, float);
	float multi(float, float);
	float divi(float, float);
	float pot(float, float);
	float sen(float);
	float cose(float);
	float tange(float);
	float arccose(float);
	float arcsen(float);
	float arctange(float);
	float senh(float);
	float coseh(float);
	float tangeh(float);
	int priorizar(string);

	float raiz(float);
	vector<string> separarCadenas(const std::string&, char );
	vector<string> obtenerContenidoEntreParentesis(const std::string&);
}; typedef Prefija Pre;