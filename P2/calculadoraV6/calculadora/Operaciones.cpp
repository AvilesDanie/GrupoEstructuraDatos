#include "Operaciones.h"
#include <iostream>
using namespace std;

float Operaciones::suma(float a, float b){
	return a + b;
}
float Operaciones::resta(float a, float b) {
	return a - b;
}
float Operaciones::multiplicacion(float a, float b){
	return a * b;
}
float Operaciones::division(float a, float b) {
	return a / b;
}
float Operaciones::potencia(float a, int b) {
	float resultado = 1;
	if (b >= 0) {
		for (int i = 0; i < b; i++) {
			resultado *= a;
		}
		return resultado;
	}
	else {
		for (int i = 0; i < b*(-1); i++) {
			resultado *= a;
		}
		return 1/resultado;
	}
}
float Operaciones::raizCuadrada(float numero) {
	float tolerancia = 0.0001;
	if (numero < 0)
		return -1;  // Error: no se puede calcular la raíz cuadrada de un número negativo

	float estimacion = numero;
	float diferencia = 1.0;

	while (diferencia > tolerancia) {
		float nuevaEstimacion = 0.5 * (estimacion + numero / estimacion);
		diferencia = std::abs(estimacion - nuevaEstimacion);
		estimacion = nuevaEstimacion;
	}
	return estimacion; 
}
float Operaciones::raizCubica(float numero) {
	float tolerancia = 0.0001;
	float estimacion = numero;
	float diferencia = 1.0;

	while (diferencia > tolerancia) {
		float nuevaEstimacion = (2 * estimacion + numero / (estimacion * estimacion)) / 3;
		diferencia = std::abs(estimacion - nuevaEstimacion);
		estimacion = nuevaEstimacion;
	}

	return estimacion;
}
float Operaciones::seno(float angulo) {
	int iteraciones = 10;
	float radianes = angulo * 3.14159265358979323846 / 180.0;
	float resultado = radianes;

	for (int i = 1; i <= iteraciones; i++) {
		float numerador = potencia(-1, i);
		float denominador = factorial(2 * i + 1);
		float termino = (numerador * potencia(radianes, 2 * i + 1)) / denominador;
		resultado += termino;
	}

	return resultado;
}
float Operaciones::coseno(float angulo) {
	int iteraciones = 10;
	float radianes = angulo * 3.14159265358979323846 / 180.0;
	float resultado = 1.0;  // Primer término de la serie

	for (int i = 1; i <= iteraciones; i++) {
		float numerador = potencia(-1, i);
		float denominador = factorial(2 * i);
		float termino = (numerador * potencia(radianes, 2 * i)) / denominador;
		resultado += termino;
	}

	return resultado;
}
float Operaciones::tangente(float angulo) {
	int iteraciones = 10;
	float radianes = angulo * 3.14159265358979323846 / 180.0;
	float resultado = radianes;  // Primer término de la serie

	for (int i = 1; i <= iteraciones; i++) {
		float numerador = potencia(-1, i) * 2 * potencia(radianes, 2 * i - 1);
		float denominador = factorial(2 * i);
		float termino = numerador / denominador;
		resultado += termino;
	}

	return resultado;
}
float Operaciones::cosecante(float angulo) {
	float seno1 = seno(angulo);

	if (seno1 != 0.0) {
		return 1.0 / seno1;
	}
	else {
		return std::numeric_limits<float>::infinity();
	}
}
float Operaciones::secante(float angulo) {
	float coseno1 = coseno(angulo);

	if (coseno1 != 0.0) {
		return 1.0 / coseno1;
	}
	else {
		return std::numeric_limits<float>::infinity();
	}
}
float Operaciones::cotangente(float angulo) {
	float tangente1 = tangente(angulo);

	if (tangente1 != 0.0) {
		return 1.0 / tangente1;
	}
	else {
		return std::numeric_limits<float>::infinity();
	}
}
int Operaciones::factorial(int n) {
	double factorial = 1.0;

	for (int i = 2; i <= n; i++) {
		factorial *= i;
	}

	return factorial;
}