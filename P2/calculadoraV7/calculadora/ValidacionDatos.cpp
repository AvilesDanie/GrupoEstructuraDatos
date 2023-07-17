/***********************************************************************
* Module:  ValidacionDatos.cpp
* Authors:  Aviles, Reyes
* Modified: miércoles, 6 de julio de 2023
* Purpose: Declaration of the class ValidacionDatos
***********************************************************************/
#include"ValidacionDatos.h"




/**
 * Valida la cantidad de parentesis abiertos y cerrados sen iguales.
 *
 * @param string infija. Notacion infija de las operaciones numericas.
 *
 * @return Boleano que muestra la  validadcion.
 */

bool ValidacionDatos::parentesis(std::string infija) {
	char c = 'a';
	int cont = 0;
	for (size_t i = 0; i < infija.length(); i++) {
		c = infija[i];
		if (c == '(') {
			cont += 1;
		}
		else if (c == ')') {
			cont -= 1;
		}
		if (cont < 0) {
			return true;
		}
	}

	if (cont != 0) {
		return true;
	}
	return false;
	
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
				if (cont == 2 || numero[0]=='.') {
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

				if (!((c2 >= 48 && c <= 57) || c2 == '.')) {
					cont++;
				}
				if (cont == 1) {
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
			for (int j = i; e != '(' && i < infija.length(); i++) {
				e = infija[i];
				d = e;
				raiz = raiz + d;
			}
			i--;
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
