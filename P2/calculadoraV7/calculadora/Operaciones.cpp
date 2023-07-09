/***********************************************************************
* Module:  Operaciones.cpp
* Authors:  Aviles, Reyes
* Modified: miércoles, 5 de julio de 2023
* Purpose: Declaration of the class Operaciones
***********************************************************************/
#include "Operaciones.h"
#include <iostream>
using namespace std;

/**
* Suma dos numeros
*
* @param double a. Primer sumando
* @param double b. Segundo sumando
* 
* @return Suma a +b
**/
double Operaciones::suma(double a, double b){
	return a + b;
}

/**
* Resta dos numeros
*
* @param double a. Minuendo
* @param double b. Sustraendo
*
* @return resta a-b
**/
double Operaciones::resta(double a, double b) {
	return a - b;
}

/**
* Multiplica dos numeros
*
* @param double a. Primer Factor
* @param double b. Sugundo Factor
*
* @return Multiplicacion  a*b
**/
double Operaciones::multiplicacion(double a, double b){
	return a * b;
}

/**
* Division de dos numeros
*
* @param double a. Dividendo
* @param double b. Divisior
*
* @return Divide a/b
**/
double Operaciones::division(double a, double b) {
	if(b!=0)
		return a / b;
	else
		return std::numeric_limits<double>::infinity();
}

/**
* Resaliza una potencia
*
* @param double a. Base
* @param double b. Exponente
*
* @return Opera a^b
**/
double Operaciones::potencia(double a, double b) {
	if (b - int(b) == 0) {
		double resultado = 1;
		if (b >= 0) {
			for (int i = 0; i < b; i++) {
				resultado *= a;
			}
			return resultado;
		}
		else {
			for (int i = 0; i < b * (-1); i++) {
				resultado *= a;
			}
			return 1 / resultado;
		}
	}
	else {
		double precision = 0.00001;
		int numerador = b * 10000;
		int denominador = 10000;
		int mcd = calcularMCD(numerador, denominador);
		numerador /= mcd;
		denominador /= mcd;
		if (denominador < 0) {
			numerador *= -1;
			denominador *= -1;
		}
		a = potencia(a, numerador);
		double izquierda, derecha;
		if (a < 1.0) {
			izquierda = a;
			derecha = 1.0;
		}
		else {
			izquierda = 1.0;
			derecha = a;
		}

		while (derecha - izquierda > precision) {
			double mitad = (izquierda + derecha) / 2.0;
			double resultado = 1.0;

			for (int i = 0; i < denominador; i++) {
				resultado *= mitad;
			}

			if (resultado > a) {
				derecha = mitad;
			}
			else if (resultado < a) {
				izquierda = mitad;
			}
			else {
				return mitad;
			}
		}
		return (izquierda + derecha) / 2.0;
	}
}

/**
* Calcula la raiz cuadrada de un numero
*
* @param double a. Base
*
* @return sqrt a
**/
double Operaciones::raizCuadrada(double numero) {
	double tolerancia = 0.0001;
	if (numero < 0)
		return std::numeric_limits<double>::infinity();

	double estimacion = numero;
	double diferencia = 1.0;

	while (diferencia > tolerancia) {
		double nuevaEstimacion = 0.5 * (estimacion + numero / estimacion);
		diferencia = std::abs(estimacion - nuevaEstimacion);
		estimacion = nuevaEstimacion;
	}
	return estimacion; 
}

/**
* Calcula la raiz cuabica de un numero
*
* @param double a. Base
*
* @return cbrt a
**/
double Operaciones::raizCubica(double numero) {
	double tolerancia = 0.0001;
	double estimacion = numero;
	double diferencia = 1.0;

	while (diferencia > tolerancia) {
		double nuevaEstimacion = (2 * estimacion + numero / (estimacion * estimacion)) / 3;
		diferencia = std::abs(estimacion - nuevaEstimacion);
		estimacion = nuevaEstimacion;
	}

	return estimacion;
}

/**
* Calcula el seno de un numero
*
* @param double a. Angulo
*
* @return sen a
**/
double Operaciones::seno(double angulo) {
	int iteraciones = 10;
	double radianes = angulo * 3.14159265358979323846 / 180.0;
	double resultado = radianes;

	for (int i = 1; i <= iteraciones; i++) {
		double numerador = potencia(-1, i);
		double denominador = factorial(2 * i + 1);
		double termino = (numerador * potencia(radianes, 2 * i + 1)) / denominador;
		resultado += termino;
	}

	return resultado;
}

/**
* Calcula el coseno de un numero
*
* @param double a. Angulo
*
* @return cos a
**/
double Operaciones::coseno(double angulo) {
	int iteraciones = 10;
	double radianes = angulo * 3.14159265358979323846 / 180.0;
	double resultado = 1.0;  // Primer término de la serie

	for (int i = 1; i <= iteraciones; i++) {
		double numerador = potencia(-1, i);
		double denominador = factorial(2 * i);
		double termino = (numerador * potencia(radianes, 2 * i)) / denominador;
		resultado += termino;
	}

	return resultado;
}

/**
* Calcula la tangente de un numero
*
* @param double a. Angulo
*
* @return tg a
**/
double Operaciones::tangente(double angulo) {
	int iteraciones = 10;
	double radianes = angulo * 3.14159265358979323846 / 180.0;
	double resultado = radianes;  // Primer término de la serie

	for (int i = 1; i <= iteraciones; i++) {
		double numerador = potencia(-1, i) * 2 * potencia(radianes, 2 * i - 1);
		double denominador = factorial(2 * i);
		double termino = numerador / denominador;
		resultado += termino;
	}

	return resultado;
}

/**
* Calcula la cosecante de un numero
*
* @param double a. Numero
*
* @return csc a
**/
double Operaciones::cosecante(double angulo) {
	double seno1 = seno(angulo);

	if (seno1 != 0.0) {
		return 1.0 / seno1;
	}
	else {
		return std::numeric_limits<double>::infinity();
	}
}

/**
* Calcula la secante de un numero
*
* @param double a. Numero
*
* @return sec a
**/
double Operaciones::secante(double angulo) {
	double coseno1 = coseno(angulo);

	if (coseno1 != 0.0) {
		return 1.0 / coseno1;
	}
	else {
		return std::numeric_limits<double>::infinity();
	}
}

/**
* Calcula la cotangente de un numero
*
* @param double a. Numero
*
* @return ctg a
**/
double Operaciones::cotangente(double angulo) {
	double tangente1 = tangente(angulo);

	if (tangente1 != 0.0) {
		return 1.0 / tangente1;
	}
	else {
		return std::numeric_limits<double>::infinity();
	}
}

/**
* Calcula el factorial de un numero
*
* @param int a. Numero
*
* @return  Factorial a!
**/
int Operaciones::factorial(int n) {
	double factorial = 1.0;

	for (int i = 2; i <= n; i++) {
		factorial *= i;
	}

	return factorial;
}

/**
* Calcula el minimo comun division de dos numeros
*
* @param int a. Numero1
* @param int b. Numero2
*
* @return  MCD  de a y b
**/
int Operaciones::calcularMCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return calcularMCD(b, a % b);
	}
}