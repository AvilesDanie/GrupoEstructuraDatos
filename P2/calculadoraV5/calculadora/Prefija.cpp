#include "Prefija.h"
#include "PilaChar.h"

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

	vector<string> ExprecionesParentesis = obtenerContenidoEntreParentesis(infija);
	

	std::reverse(infija.begin(), infija.end());
	bool parentesis = false;
	int contParentesis = 0;
	for (size_t i = 0; i < infija.length(); i++) {
		char e = infija[i];
		string d;
		d = e;
		if ((d == "+" || d == "-") && !parentesis) {
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
			prefija = resultado + prefija;

		}
		
		else {
			std::reverse(resultado.begin(), resultado.end());

			parentesis = false;

			for (size_t i = 0; i < resultado.length(); i++) {
				char e = resultado[i];
				string d;
				d = e;

				if ((d == "/" || d == "*") && !parentesis) {
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
							prefija = resultadoPot + prefija;

						}
						else if (resultadoPot[0] == 's' || resultadoPot[0] == 'c' || resultadoPot[0] == 't') {
							string raiz;
							char e = 'a';
							string d;
							int iteraciones = 0;
							for (size_t i = 0; e != '('; i++) {
								e = resultadoPot[i];
								d = e;
								raiz = raiz + d;
								iteraciones = i;
							}
							raiz.pop_back();
							if (raiz == "sqrt") {

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
							else if (raiz == "sin") {

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

							for (int i =1; e != ')' || cont != 0; i++) {

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

	std::reverse(prefija.begin(), prefija.end());
	Pila aux;
	for (size_t i = 0; i < prefija.length(); i++) {
		char e = prefija[i];
		string d;
		d = e;
		aux.push(d);
	}
	pila = aux;


	return prefija;
}





