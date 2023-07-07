#include "Operaciones.h"
#include <iostream>
using namespace std;

double Operaciones::suma(double a, double b){
	return a + b;
}
double Operaciones::resta(double a, double b) {
	return a - b;
}
double Operaciones::multiplicacion(double a, double b){
	return a * b;
}
double Operaciones::division(double a, double b) {
	if(b!=0)
		return a / b;
	else
		return std::numeric_limits<double>::infinity();
}
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
		cout << numerador << endl;
		cout << denominador << endl;
		a = potencia(a, numerador);
		cout << a << endl;
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
double Operaciones::cosecante(double angulo) {
	double seno1 = seno(angulo);

	if (seno1 != 0.0) {
		return 1.0 / seno1;
	}
	else {
		return std::numeric_limits<double>::infinity();
	}
}
double Operaciones::secante(double angulo) {
	double coseno1 = coseno(angulo);

	if (coseno1 != 0.0) {
		return 1.0 / coseno1;
	}
	else {
		return std::numeric_limits<double>::infinity();
	}
}
double Operaciones::cotangente(double angulo) {
	double tangente1 = tangente(angulo);

	if (tangente1 != 0.0) {
		return 1.0 / tangente1;
	}
	else {
		return std::numeric_limits<double>::infinity();
	}
}
int Operaciones::factorial(int n) {
	double factorial = 1.0;

	for (int i = 2; i <= n; i++) {
		factorial *= i;
	}

	return factorial;
}

int Operaciones::calcularMCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return calcularMCD(b, a % b);
	}
}