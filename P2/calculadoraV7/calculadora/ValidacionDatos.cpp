/***********************************************************************
* Module:  ValidacionDatos.cpp
* Authors:  Aviles, Reyes
* Modified: miércoles, 6 de julio de 2023
* Purpose: Declaration of the class ValidacionDatos
***********************************************************************/
#include"ValidacionDatos.h"
#define LONGITUD 10
#pragma once

/**
 * Lee una cadena de números del teclado y la devuelve
 *
 * @param msj El mensaje que se mostrará al usuario.
 *
 * @return Un puntero a una matriz de caracteres.
 */
char* ValidacionDatos::lecturaEnteros(char const* msj) {
	char* dato = new char[10];
	char c;
	int i = 0;
	printf("%s\n", msj);
	while ((c = _getch()) != 13)//ingreso de datos sin ecco(NO SE PUEDE VER)
	{
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato[i++] = c;
		}
		else if (c == 8) { //backspace
			if (i > 0) {
				i--;
				printf("\b \b");
			}
		}
	}
	dato[i] = '\0';
	return dato;
}
//CASTEO

/**
 *
 * @param dato la variable que almacenará el valor
 * @param msj El mensaje que se mostrará al usuario.
 */
int ValidacionDatos::casteoEnteros(char* dato, char const* msj) {
	int valor;
	//"\nIngresar el valor a convertir a entero : "
	strcpy_s(dato,100 , lecturaEnteros(msj));
	return valor = atoi(dato);
}

/**
 * Lee una cadena de caracteres del teclado y devuelve un puntero a la cadena
 *
 * @param msj El mensaje que se mostrará al usuario.
 *
 * @return Un puntero a una matriz de caracteres.
 */
char* ValidacionDatos::lecturaReales(char const* msj) {
	char* dato = new char[LONGITUD + 1];
	char c;
	printf("%s", msj);
	int i = 0;
	int punto = 0;
	while (c = _getch()) {
		if (c == 13) {
			dato[i] = '\0';
			break;
		}
		else if (c == 8) { //backspace
			if (i > 0) {
				i--;
				printf("\b \b");
				if (dato[i] == 46) {
					punto = 0;
				}

			}
		}
		else if (c == 46) {

			if (punto < 1) {
				printf("%c", c);
				dato[i] = c;
				i++;
			}
			punto++;
		}
		else {
			if (i < LONGITUD && c >= '0' && c <= '9') //limite de longitud
			{
				printf("%c", c);
				dato[i] = c;
				i++;
			}

		}

	}
	return dato;
}
//CASTEO
/**
 * Toma una cadena, la convierte en un doble y devuelve el doble
 *
 * @param dato es la variable que almacenará los datos introducidos por el usuario.
 * @param msj El mensaje que se mostrará al usuario.
 */
double ValidacionDatos::casteoReales(char* dato, char const* msj) {
	double valor;
	strcpy_s(dato, 100, lecturaReales(msj));
	return valor = atof(dato);
}

/**
 * Lee una cadena de caracteres especificos .
 *
 * @param msj El mensaje que se mostrará al usuario.
 *
 * @return Un puntero a una matriz de caracteres.
 */
char* ValidacionDatos::lecturaTexto(char const* msj) {
	////
	char* dato = new char[10];
	char c;
	int i = 0;
	printf("%s\n", msj);
	while ((c = _getch()) != 13)//ingreso de datos sin ecco(NO SE PUEDE VER)
	{
		if ((c >= 65 && c <= 90 || c >= 97 && c <= 122 || c == 32)) {
			printf("%c", c);
			dato[i++] = c;
		}
		else if (c == 8) { //backspace
			if (i > 0) {
				i--;
				printf("\b \b");
			}
		}
	}
	dato[i] = '\0';
	return dato;
}

/**
 * Lee una cadena de caracteres especificos numericos.
 *
 * @param msj El mensaje que se mostrará al usuario.
 *
 * @return Un puntero a una matriz de caracteres.
 */
char* ValidacionDatos::lecturaTextoNumerico(char const* msj) {
	////
	char* dato = new char[10];
	char c;
	int i = 0;
	printf("%s\n", msj);
	while ((c = _getch()) != 13)//ingreso de datos sin ecco(NO SE PUEDE VER)
	{
		if ((c >= 48 && c <= 57)) {
			printf("%c", c);
			dato[i++] = c;
		}
		else if (c == 8) { //backspace
			if (i > 0) {
				i--;
				printf("\b \b");
			}
		}
	}
	dato[i] = '\0';
	return dato;
}



/**
 * Valida la cantidad de parentesis abiertos y cerrados sen iguales.
 *
 * @param string infija. Notacion infija de las operaciones numericas.
 *
 * @return Boleano que muestra la  validadcion.
 */

bool ValidacionDatos::parentesis(std::string infija) {
	char c = 'a';
	int contA = 0, contC = 0;
	for (size_t i = 0; i < infija.length(); i++) {
		c = infija[i];
		if (c == '(') {
			contA += 1;
		}
		else if (c == ')') {
			contC += 1;
		}
	}

	if (contA == contC) {
		return false;
	}
	else {
		return true;
	}
}

/**
 * Valida la posicion y la cantidad de signos matematicos utilizados.
 *
 * @param string infija. Notacion infija de las operaciones numericas.
 *
 * @return Boleano que muestra la  validadcion.
 */
bool ValidacionDatos::signos(std::string infija) {
	char primer = infija[0], ultimo = infija[infija.length()-1],c='0',d='1';

	if ((primer >= 33 && primer <= 39) || (primer >= 41 && primer <= 47) || (primer >= 58 && primer <= 93) || (primer >= 95 && primer <= 98) || (primer >= 100 && primer <= 114) || (primer >= 117 && primer <= 255)) {
			return true;
	}
	if ((ultimo >= 33 && ultimo <= 40) || (ultimo >= 42 && ultimo <= 47) || (ultimo >= 58 && ultimo <= 98) || (ultimo >= 100 && ultimo <= 114) || (ultimo >= 117 && ultimo <= 255)) {
		return true;
	}
	for (size_t i = 0; i < infija.length()-1; i++) {
		c = infija[i];
		d = infija[i + 1];
		if ((c == 42 || c == 43 || c == 45 || c == 47 || c == 94) && (d == 42 || d == 43 || d == 45 || d == 47 || d == 94 || d == 41)) {
			return true;
		}
		if ((c == 40) && (d == 42 || d == 43 || d == 47 || d == 94 || d == 41)) {
			return true;
		}
		if (c == 40 && d == 41) {
			return true;
		}
		if (c == 41 && d == 40) {
			return true;
		}
		if ((c >= 48 && c <= 57) && d == 40) {
			return true;
		}
		if (c==41 && (d >= 48 && d <= 57)) {
			return true;
		}
	}



	return false;
}

/**
 * Valida que los puntos decimales estan bien utilizados.
 *
 * @param string infija. Notacion infija de las operaciones numericas.
 *
 * @return Boleano que muestra la  validadcion.
 */
bool ValidacionDatos::decimales(std::string infija) {
	char c = '0', c2 = '3';
	int cont = 0;
	std::string numero;
	for (size_t i = 0; i < infija.length(); i++) {
		c = infija[i];
		cont = 0;
		numero = numero + c;
		if (!((c >= 48 && c <= 57)||c=='.')) {
			numero.pop_back();
			for (size_t j = 0; j < numero.length(); j++) {
				c2 = numero[j];
				if (c2 == '.') {
					cont++;
				}
				if (cont == 2) {
					return true;
				}
			}
			numero = "";
		}

	}
	return false;
}

/**
 * Valida que los numeros negativos esten bien colocados.
 *
 * @param string infija. Notacion infija de las operaciones numericas.
 *
 * @return Boleano que muestra la  validadcion.
 */
bool ValidacionDatos::negativos(std::string infija) {
	char c = '0', c2 = '0';
	int cont = 0;
	std::string numero;
	bool negativo = false , numeroCompleto=false;
	for (size_t i = 0; i < infija.length(); i++) {
		c = infija[i];
		cont = 0;

		if (negativo) {
			numero = numero + c;
		}

		if (c == '-' && infija[i-1] == '(') {
			negativo = true;
		}
		else if (c == ')' && negativo) {
			numeroCompleto = true;
			negativo = false;
			numero.pop_back();
		}

		

		if (numeroCompleto) {
			for (size_t j = 0; j < numero.length(); j++) {
				c2 = numero[j];
				if (!((c >= 48 && c <= 57) || c == '.')) {
					cont++;
				}
				if (cont == 2) {
					return true;
				}

			}
			numero = "";
			numeroCompleto = false;
		}

	}
	return false;
}

/**
 * Valida cadenas de caracteres especificas que representa diversas operaciones matematicas.
 *
 * @param string infija. Notacion infija de las operaciones numericas.
 *
 * @return Boleano que muestra la  validadcion.
 */
bool ValidacionDatos::letras(std::string infija) {
	char c = '0';


	for (size_t i = 0; i < infija.length(); i++) {
		c = infija[i];
		if (infija[i] >= 97 && infija[i] <= 122) {
			std::string raiz;
			char e = '0';
			std::string d;
			for (int j = i; e != '('; i++) {
				e = infija[i];
				d = e;
				raiz = raiz + d;
			}
			raiz.pop_back();
			if (raiz != "sqrt" && raiz != "cbrt" && raiz != "sen" && raiz != "cos" && raiz != "tg" && raiz != "ctg" && raiz != "sec" && raiz != "csc") {
				return true;
			}


		}
	}

	return false;

}

/**
 * Validad la presencia solamente de caracteres especificaos dentro de la notacion infija.
 *
 * @param string infija. Notacion infija de las operaciones numericas.
 *
 * @return Boleano que muestra la  validadcion.
 */
bool ValidacionDatos::general(std::string infija) {
	char c = '0';


	for (size_t i = 0; i < infija.length(); i++) {
		c = infija[i];
		if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != '.' && c != '(' && c != ')' && c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != 's' && c != 'q' && c != 'r' && c != 't' && c != 'c' && c != 'b' && c != 's' && c != 'e' && c != 'n' && c != 'c' && c != 'o' && c != 'g') {
			return true;
		}

		
	}

	return false;
}
