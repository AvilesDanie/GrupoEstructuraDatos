#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <conio.h>
#include <cctype>
#include "Validaciones.h"

using namespace std;
/*
@Constructor
*/
Validaciones::Validaciones() {

}

Validaciones::~Validaciones() {

}
/*
@name function: validarEnteros
@return varible type: int
@parameters: void

	-valida la entrada solo de numeros enteros desde teclado.
*/
int Validaciones::validarEnteros() {
	char* dato = new char[10];
	int i = 0;
	int numero;
	char c;
	while ((c = _getch()) != 13) {

		if (c >= '0' && c <= '9') {

			dato[i++] = c;
			printf("%c", c);
			numero = atoi(dato);

		}
		else if (c == 8 && i != 0) {

			dato[i - 1] = 0;
			i--;

			putchar(8);
			putchar(32);
			putchar(8);
		}
	}
	dato[i] = '\0';
	return numero;
}

/*
@name function: validarDoubles
@return varible type: double
@parameters: void

	-valida la entrada solo de numeros enteros y flotantes desde teclado.
*/
double Validaciones::validarDoubles() {
	char* dato = new char[10];
	int i = 0;
	double numero;
	int cont = 0;
	char c;
	while ((c = _getch()) != 13) {

		if (c >= '0' && c <= '9') {

			dato[i++] = c;
			printf("%c", c);
			numero = atof(dato);
		}
		else if (c == '.' && cont < 1) {
			printf("%c", c);
			dato[i++] = c;
			cont++;
			numero = atof(dato);
		}
		else if (c == 8 && i != 0) {

			dato[i - 1] = 0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
		}
	}
	dato[i] = '\0';
	return numero;
}



char* Validaciones::validarStrings() {
	char* dato = new char[0];
	char c;
	int i = 0;

	while ((c = _getch()) != 13) {
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
			dato[i++] = toupper(c);
			printf("%c", c);
		}
		else if (c == 8 && i != 0) {

			*(dato + (i - 1)) = 0;
			i--;

			putchar(8);
			putchar(32);
			putchar(8);
		}
	}
	dato[i] = '\0';
	return dato;
	delete[]dato;
}

/*
@name function: validarEnterosCedula()
@return varible type: char*
@parameters: void

	-valida la entrada solo de numeros enteros de la cedula con un rango de 10 desde teclado.
*/
char* Validaciones::validarEnterosCedula() {
	char* dato = new char[0];
	int i = 0;
	char c;

	while ((c = _getch()) != 13) {

		if (c >= '0' && c <= '9') {

			dato[i++] = c;
			printf("%c", c);

		}
		else if (c == 8 && i != 0) {

			dato[i - 1] = 0;
			i--;

			putchar(8);
			putchar(32);
			putchar(8);
		}
	}
	dato[i] = '\0';
	return dato;
}
/*
@name function: splitNumber
@return varible type: int*
@parameters: char* number

	-valida posicion por posicion la cedula que se ingresa
*/

int* Validaciones::splitNumber(char* number) {

	int* digit = new int[10];
	char dig;

	for (int i = 0; i < 10; i++) {

		dig = *(number + i);
		*(digit + i) = stoi(&dig);
	}


	return digit;

}

/*
@name function: verificacion1
@return varible type: bool
@parameters: char* numCedula

	-se verifican los dos primeros numeros de la cedula
*/
bool Validaciones::verificacion1(char* numCedula) {

	int* cedula;
	int digitos12;
	cedula = splitNumber(numCedula);

	digitos12 = cedula[0] * 10 + cedula[1];
	if (digitos12 < 24 && digitos12>0) {
		return true;
	}

	return false;

}

/*
@name function: verificacion2
@return varible type: bool
@parameters: char* numCedula

	-se verifica el tercer numero de la cedula
*/

bool Validaciones::verificacion2(char* numCedula) {

	int* cedula = splitNumber(numCedula);
	int digito3 = cedula[2];
	if (digito3 < 6 && digito3 >= 0) {
		return true;
	}


	return false;

}

/*
@name function: verificacion3
@return varible type: bool
@parameters: char* numCedula

	-se verifica el ultimo digito de la cedula
*/
bool Validaciones::verificacion3(char* numCedula) {

	int* cedula = splitNumber(numCedula);
	int digValidador;
	int coef;
	int mult;
	int sum = 0;
	int decSuperior;

	for (int i = 0; i < 9; i++) {
		if ((i % 2) == 0) {
			coef = 2;
		}
		else {
			coef = 1;
		}

		mult = *(cedula + i) * coef;

		if (mult > 9) {
			mult -= 9;
		}
		sum += mult;
	}

	decSuperior = ((sum / 10) + 1) * 10;
	digValidador = decSuperior - sum;

	if (digValidador == 10) {
		digValidador = 0;
	}

	if (digValidador == cedula[9]) {
		return true;
	}

	return false;
}
/*
@name function: verificacionCedula
@return varible type: bool
@parameters: char* numCedula

	-se verifica que el numero de cedula cumpla las tres validaciones
*/
bool Validaciones::verificacionCedula(char* numCedula) {
	bool bandera1 = false;
	bool bandera2 = false;
	bool bandera3 = false;

	if (verificarLongitud(numCedula) == true) {
		bandera1 = verificacion1(numCedula);
		bandera2 = verificacion2(numCedula);
		bandera3 = verificacion3(numCedula);
	}

	if (bandera1 && bandera2 && bandera3) {
		return true;
	}

	return false;
}

/*
@name function: LongitudCadena
@return varible type: int
@parameters: char *cedula

	-Saca la longitud de la cedula
*/

int Validaciones::LongitudCadena(char* cedula) {

	char* aux;
	int count = 0;
	aux = cedula;
	while (*aux != '\0') {
		count++;
		aux++;
	}
	return count;
}
/*
@name function: verificarLongitud
@return varible type: bool
@parameters: char *p

	-Verifica si la longitud de la cedula es de 10 para hacerlo valida
*/
bool Validaciones::verificarLongitud(char* p) {

	if (LongitudCadena(p) == 10) {
		return true;
	}
	else {
		return false;
	}
}