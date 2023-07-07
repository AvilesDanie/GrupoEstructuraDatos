#include <iostream>
#include "Pila.h"
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

class Postfija
{
	typedef Postfija Post;

private:
	int posi;
	Pila pila;
	string* opera = new string[posi];
public:
	string inAPost(string);
	Pila getPila();
	void calcularPila();
	bool contieneSoloNumeros(string str);

	vector<string> separarCadenas(const std::string&, char);
	vector<string> obtenerContenidoEntreParentesis(const std::string&);

}; typedef Postfija Post;
