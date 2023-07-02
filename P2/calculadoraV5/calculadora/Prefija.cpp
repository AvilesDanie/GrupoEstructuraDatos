#include "Prefija.h"
#include "PilaChar.h"
#include <iostream>

using namespace std;



vector<string> Prefija::separarCadenas(const string& cadena, char separador) {
	vector<string> subcadenas;
	string subcadena;
	PilaChar pila;

	for (size_t i = 0; i < cadena.length(); i++) {
		char caracter = cadena[i];

		if (caracter == '(') {
			pila.push(caracter);
		}
		else if (caracter == ')') {
			if (!pila.getPilaVacia()) {
				pila.pop();
			}
			else {
				// Error: Paréntesis de cierre sin correspondiente paréntesis de apertura
			}
		}

		if (pila.getPilaVacia() && caracter == separador) {
			subcadenas.push_back(subcadena);
			subcadena.clear();
		}
		else {
			subcadena += caracter;
		}
	}

	subcadenas.push_back(subcadena);

	return subcadenas;
}


vector<string> Prefija::obtenerContenidoEntreParentesis(const string& cadena) {
	std::vector<std::string> contenido;
	PilaChar pila;
	std::string subcadena;

	for (size_t i = 0; i < cadena.length(); i++) {
		if (cadena[i] == '(') {
			pila.push('(');
			if (pila.contar() + 1 > 1) {
				subcadena += cadena[i];
			}
		}
		else if (cadena[i] == ')') {
			if (!pila.getPilaVacia()) {
				pila.pop();
				if (pila.getPilaVacia()) {
					contenido.push_back(subcadena);
					subcadena.clear();
				}
				else {
					subcadena += cadena[i];
				}
			}
			else {
				// Error: Paréntesis de cierre sin correspondiente paréntesis de apertura
			}
		}
		else {
			if (!pila.getPilaVacia()) {
				subcadena += cadena[i];
			}
		}
	}
	return contenido;
}


string Prefija::inAPre(string infija)
{
	string prefija = "";
	//vector<string> ExprecionesParentesis = obtenerContenidoEntreParentesis(infija);
	std::reverse(infija.begin(), infija.end());
	bool parentesis = false;
	int contParentesis = 0;

	for (size_t i = 0; i < infija.length(); i++) {
		char e = infija[i];
		string d;
		d = e;
		if ((d == "+" || d == "-") && !parentesis) {
			pila.push(d);
			prefija = d + prefija;
		}
		else if (d == ")") {
			if (parentesis == true) {
				contParentesis += 1;
			}
			parentesis = true;
		}
		else if (d == "(") {
			if (contParentesis == 0) {
				parentesis = false;
			}
			else {
				contParentesis -= 1;
			}
		}
	}

	std::reverse(infija.begin(), infija.end());

	vector<string> subcadenas = separarCadenas(infija, '+');

	vector<string> resultados;
	for (string subcadena : subcadenas) {
		vector<string> subcadenas2 = separarCadenas(subcadena, '-');
		resultados.insert(resultados.end(), subcadenas2.begin(), subcadenas2.end());
	}

	contParentesis = 0;
	for (string resultado : resultados) {
		if (resultado.length() == 1) {
			pila.push(resultado);
			prefija = resultado + prefija;

		}
		/*else if ((resultado[0] == '0' || resultado[0] == '1' || resultado[0] == '2' || resultado[0] == '3' || resultado[0] == '4' || resultado[0] == '5' || resultado[0] == '6' || resultado[0] == '7' || resultado[0] == '8' || resultado[0] == '9') && (resultado[1] == '0' || resultado[1] == '1' || resultado[1] == '2' || resultado[1] == '3' || resultado[1] == '4' || resultado[1] == '5' || resultado[1] == '6' || resultado[1] == '7' || resultado[1] == '8' || resultado[1] == '9')) {
			string numero, charNumero;
			char n = 'a';
			for (size_t i = 0; (resultado[i] == '0' || resultado[i] == '1' || resultado[i] == '2' || resultado[i] == '3' || resultado[i] == '4' || resultado[i] == '5' || resultado[i] == '6' || resultado[i] == '7' || resultado[i] == '8' || resultado[i] == '9') && i < resultado.length(); i++) {
				n = resultado[i];
				charNumero = n;
				numero = numero + charNumero;
			}

			pila.push(numero);

		}*/
		else {
			std::reverse(resultado.begin(), resultado.end());

			parentesis = false;

			for (size_t i = 0; i < resultado.length(); i++) {
				char e = resultado[i];
				string d;
				d = e;

				if ((d == "/" || d == "*") && !parentesis) {
					pila.push(d);
					prefija = d + prefija;
				}
				else if (d == ")") {
					if (parentesis == true) {
						contParentesis += 1;
					}
					parentesis = true;
				}
				else if (d == "(") {
					if (contParentesis == 0) {
						parentesis = false;
					}
					else {
						contParentesis -= 1;
					}
				}
			}
			std::reverse(resultado.begin(), resultado.end());


			vector<string> subcadenasMulDiv = separarCadenas(resultado, '*');

			vector<string> resultadosMulDiv;
			for (string subcadenaMulDiv : subcadenasMulDiv) {
				vector<string> subcadenasMulDiv2 = separarCadenas(subcadenaMulDiv, '/');
				resultadosMulDiv.insert(resultadosMulDiv.end(), subcadenasMulDiv2.begin(), subcadenasMulDiv2.end());
			}
			contParentesis = 0;
			for (string resultadoMulDiv : resultadosMulDiv) {
				if (resultadoMulDiv.length() == 1) {
					pila.push(resultadoMulDiv);
					prefija = resultadoMulDiv + prefija;

				}
				else {
					std::reverse(resultadoMulDiv.begin(), resultadoMulDiv.end());

					parentesis = false;

					for (size_t i = 0; i < resultadoMulDiv.length(); i++) {
						char e = resultadoMulDiv[i];
						string d;
						d = e;

						if ((d == "^") && !parentesis) {
							pila.push(d);
							prefija = d + prefija;
						}
						else if (d == ")") {
							if (parentesis == true) {
								contParentesis += 1;
							}
							parentesis = true;
						}
						else if (d == "(") {
							if (contParentesis == 0) {
								parentesis = false;
							}
							else {
								contParentesis -= 1;
							}
						}
					}


					std::reverse(resultadoMulDiv.begin(), resultadoMulDiv.end());


					vector<string> subcadenasPot = separarCadenas(resultadoMulDiv, '^');
					contParentesis = 0;

					for (string resultadoPot : subcadenasPot) {
						if (resultadoPot.length() == 1) {
							pila.push(resultadoPot);
							prefija = resultadoPot + prefija;

						}
						else if (resultadoPot[0] == 's' || resultadoPot[0] == 'c' || resultadoPot[0] == 't') {
							string raiz;
							char e = 'a';
							string d;
							int iteraciones = 0;
							for (int i = 0; e != '('; i++) {
								e = resultadoPot[i];
								d = e;
								raiz = raiz + d;
								iteraciones = i;
							}
							raiz.pop_back();
							if (raiz == "sqrt") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}
								}

								dentroRaiz.pop_back();

								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}

							else if (raiz == "cbrt") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}

								}
								dentroRaiz.pop_back();

								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}
							else if (raiz == "sen") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}

								}


								dentroRaiz.pop_back();



								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}
							else if (raiz == "cbrt") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}

								}


								dentroRaiz.pop_back();



								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}
							else if (raiz == "cos") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}

								}


								dentroRaiz.pop_back();



								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}
							else if (raiz == "tg") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}

								}


								dentroRaiz.pop_back();



								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}
							else if (raiz == "ctg") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}

								}


								dentroRaiz.pop_back();



								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}
							else if (raiz == "sec") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}

								}


								dentroRaiz.pop_back();


								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}
							else if (raiz == "csc") {
								pila.push(raiz);
								std::reverse(raiz.begin(), raiz.end());
								prefija = raiz + prefija;
								string dentroRaiz;
								int cont = 1;
								iteraciones += 1;
								for (iteraciones; e != ')' || cont != 0; iteraciones++) {

									e = resultadoPot[iteraciones];
									string d;
									d = e;
									dentroRaiz = dentroRaiz + d;
									if (d == "(") {
										cont += 1;
									}
									else if (d == ")") {
										cont -= 1;
									}

								}


								dentroRaiz.pop_back();

								string resultadoRaiz = inAPre(dentroRaiz);
								std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());
								
								prefija = resultadoRaiz + prefija;

							}

						}
						else if (resultadoPot[0] == '(') {
							char e = '0';
							string d;
							string dentroParentesis;
							int cont = 1;

							for (int i = 1; e != ')' || cont != 0; i++) {

								e = resultadoPot[i];
								string d;
								d = e;
								dentroParentesis = dentroParentesis + d;
								if (d == "(") {
									cont += 1;
								}
								else if (d == ")") {
									cont -= 1;
								}

							}

							dentroParentesis.pop_back();
							string resultadoParentesis = inAPre(dentroParentesis);
							std::reverse(resultadoParentesis.begin(), resultadoParentesis.end());

							
							prefija = resultadoParentesis + prefija;
						}
					}
				}
			}
		}
	}
	reverse(prefija.begin(), prefija.end());
	return prefija;
}

Pila Prefija::getPila(){
	return pila;
}

void Prefija::calcularPila() {
	int iteraciones = 0;
	do {
		Pila aux;
		Operaciones operaciones;
		iteraciones = pila.contar();
		for (int i = 0; i <= iteraciones; i++) {
			aux.push(pila.getPrimero()->getValor());
			pila.pop();
		}
		for (int i = 0; i <= iteraciones; i += 3) {
			string e1, e2, e3;
			if (aux.getPrimero() != NULL) {
				e1 = aux.getPrimero()->getValor();
				aux.pop();
			}
			if (aux.getPrimero() != NULL) {
				e2 = aux.getPrimero()->getValor();
				aux.pop();
			}
			if (aux.getPrimero() != NULL) {
				e3 = aux.getPrimero()->getValor();
				aux.pop();
			}
			cout << e1 << e2 << e3 << endl;
			if (!(contieneSoloNumeros(e1)) && contieneSoloNumeros(e2) && contieneSoloNumeros(e3)) {
				if (e1 == "+")
				{
					pila.push(to_string(operaciones.suma(stof(e2), stof(e3))));
				}
				if (e1 == "-")
				{
					pila.push(to_string(operaciones.resta(stof(e2), stof(e3))));
				}
				if (e1 == "*")
				{
					pila.push(to_string(operaciones.multiplicacion(stof(e2), stof(e3))));
				}
				if (e1 == "/")
				{
					pila.push(to_string(operaciones.division(stof(e2), stof(e3))));
				}
				if (e1 == "^")
				{
					pila.push(to_string(operaciones.potencia(stof(e2), stoi(e3))));
				}
			}
			else if (!(contieneSoloNumeros(e1)) && contieneSoloNumeros(e2)) {
				if (e1 == "sqrt") {
					pila.push(to_string(operaciones.raizCuadrada(stof(e2))));
					aux.push(e3);
					i--;
				}
				else if (e1 == "cbrt"){
					pila.push(to_string(operaciones.raizCubica(stof(e2))));
					aux.push(e3);
					i--;
				}
				else if (e1 == "sen"){
					pila.push(to_string(operaciones.seno(stof(e2))));
					aux.push(e3);
					i--;
				}
				else if (e1 == "cos"){
					pila.push(to_string(operaciones.coseno(stof(e2))));
					aux.push(e3);
					i--;
				}
				else if (e1 == "tg"){
					pila.push(to_string(operaciones.tangente(stof(e2))));
					aux.push(e3);
					i--;
				}
				else if (e1 == "ctg"){
					pila.push(to_string(operaciones.cotangente(stof(e2))));
					aux.push(e3);
					i--;
				}
				else if (e1 == "sec"){
					pila.push(to_string(operaciones.secante(stof(e2))));
					aux.push(e3);
					i--;
				}
				else if (e1 == "csc"){
					pila.push(to_string(operaciones.cosecante(stof(e2))));
					aux.push(e3);
					i--;
				}
				else {
					aux.push(e3);
					aux.push(e2);
					pila.push(e1);
					i -= 2;
				}
			}
			else {
				aux.push(e3);
				aux.push(e2);
				pila.push(e1);
				i -= 2;
			}
		}
		while (pila.getPrimero()->getValor() == "") {
			pila.pop();
		}
	}while(iteraciones != 0);
}

bool Prefija::contieneSoloNumeros(string str) {
	if(str=="")
		return false;
	for (char c : str) {
		if (!(c>=48&&c<=57||c==46)) {
			return false;
		}
	}
	return true;
}