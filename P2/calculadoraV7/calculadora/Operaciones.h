/***********************************************************************
 * Module:  Operaciones.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 3 de julio de 2023
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/
#pragma once
class Operaciones
{
public:
	double suma(double, double);
	double resta(double, double);
	double multiplicacion(double, double);
	double division(double, double);
	double potencia(double, double);
	double raizCuadrada(double);
	double raizCubica(double);
	double seno(double);
	double coseno(double);
	double tangente(double);
	double cosecante(double);
	double secante(double);
	double cotangente(double);
	int factorial(int);
	int calcularMCD(int, int);
};

