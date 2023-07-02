#include "Postfija.h"
#include "PilaChar.h"

using namespace std;


vector<string> Postfija::separarCadenas(const string& cadena, char separador) {
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


vector<string> Postfija::obtenerContenidoEntreParentesis(const string& cadena) {
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


string Postfija::inAPost(string infija)
{
	string posfija = "";
	Pila sumaResta;

	vector<string> ExprecionesParentesis = obtenerContenidoEntreParentesis(infija);


	bool parentesis = false;
	int contParentesis = 0;
	for (size_t i = 0; i < infija.length(); i++) {
		char e = infija[i];
		string d;
		d = e;
		if ((d == "+" || d == "-") && !parentesis) {
			sumaResta.push(d);
		}
		else if (d == "(") {
			if (parentesis == true) {
				contParentesis += 1;
			}
			parentesis = true;
		}
		else if (d == ")") {
			if (contParentesis == 0) {
				parentesis = false;
			}
			else {
				contParentesis -= 1;
			}
		}
	}

	vector<string> subcadenas = separarCadenas(infija, '+');

	vector<string> resultados;
	for (string subcadena : subcadenas) {
		vector<string> subcadenas2 = separarCadenas(subcadena, '-');
		resultados.insert(resultados.end(), subcadenas2.begin(), subcadenas2.end());
	}

	vector<string> resultadosInveso;
	for (int i = resultados.size() - 1; i >= 0; --i) {
		resultadosInveso.push_back(resultados[i]);
	}

	for (string resultado : resultadosInveso) {
		if (!sumaResta.getPilaVacia()) {
			posfija = sumaResta.getPrimero()->getValor() + posfija;
			sumaResta.pop();
		}


		if (resultado.length() == 1) {
			posfija = resultado + posfija;

		}

		else {

			Pila mulDiv;

			parentesis = false;

			for (size_t i = 0; i < resultado.length(); i++) {
				char e = resultado[i];
				string d;
				d = e;

				if ((d == "/" || d == "*") && !parentesis) {
					mulDiv.push(d);
				}
				else if (d == "(") {
					if (parentesis == true) {
						contParentesis += 1;
					}
					parentesis = true;
				}
				else if (d == ")") {
					if (contParentesis == 0) {
						parentesis = false;
					}
					else {
						contParentesis -= 1;
					}
				}
			}


			vector<string> subcadenasMulDiv = separarCadenas(resultado, '*');

			vector<string> resultadosMulDiv;
			for (string subcadenaMulDiv : subcadenasMulDiv) {
				vector<string> subcadenasMulDiv2 = separarCadenas(subcadenaMulDiv, '/');
				resultadosMulDiv.insert(resultadosMulDiv.end(), subcadenasMulDiv2.begin(), subcadenasMulDiv2.end());
			}

			vector<string> resultadosMulDivInveso;
			for (int i = resultadosMulDiv.size() - 1; i >= 0; --i) {
				resultadosMulDivInveso.push_back(resultadosMulDiv[i]);
			}

			contParentesis = 0;
			for (string resultadoMulDiv : resultadosMulDivInveso) {

				if (!mulDiv.getPilaVacia()) {

					posfija = mulDiv.getPrimero()->getValor() + posfija;
					mulDiv.pop();
				}
				//std::cout << posfija << std::endl;

				if (resultadoMulDiv.length() == 1) {
					posfija = resultadoMulDiv + posfija;

				}
				else {

					Pila PilaPot;

					parentesis = false;

					for (size_t i = 0; i < resultadoMulDiv.length(); i++) {
						char e = resultadoMulDiv[i];
						string d;
						d = e;

						if ((d == "^") && !parentesis) {
							PilaPot.push(d);
						}
						else if (d == "(") {
							if (parentesis == true) {
								contParentesis += 1;
							}
							parentesis = true;
						}
						else if (d == ")") {
							if (contParentesis == 0) {
								parentesis = false;
							}
							else {
								contParentesis -= 1;
							}
						}
					}


					vector<string> subcadenasPot = separarCadenas(resultadoMulDiv, '^');

					vector<string> subcadenasPotInveso;
					for (int i = subcadenasPot.size() - 1; i >= 0; --i) {
						subcadenasPotInveso.push_back(subcadenasPot[i]);
					}

					contParentesis = 0;
					for (string resultadoPot : subcadenasPotInveso) {
						
						if (!PilaPot.getPilaVacia()) {

							posfija = PilaPot.getPrimero()->getValor() + posfija;
							PilaPot.pop();
						}
						if (resultadoPot.length() == 1) {
							posfija = resultadoPot + posfija;

						}

						else if(resultadoPot[0] == 's' || resultadoPot[0] == 'c' || resultadoPot[0] == 't'){
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

								posfija = raiz + posfija;
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



								string resultadoRaiz = inAPost(dentroRaiz);

								posfija = resultadoRaiz + posfija;

							}

							else if (raiz == "cbrt") {

								posfija = raiz + posfija;
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



								string resultadoRaiz = inAPost(dentroRaiz);

								posfija = resultadoRaiz + posfija;

							}
							else if (raiz == "sin") {

								posfija = raiz + posfija;
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



								string resultadoRaiz = inAPost(dentroRaiz);

								posfija = resultadoRaiz + posfija;

							}
							else if (raiz == "cbrt") {

								posfija = raiz + posfija;
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



								string resultadoRaiz = inAPost(dentroRaiz);

								posfija = resultadoRaiz + posfija;

							}
							else if (raiz == "cos") {

								posfija = raiz + posfija;
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



								string resultadoRaiz = inAPost(dentroRaiz);

								posfija = resultadoRaiz + posfija;

							}
							else if (raiz == "tg") {

								posfija = raiz + posfija;
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



								string resultadoRaiz = inAPost(dentroRaiz);

								posfija = resultadoRaiz + posfija;

							}
							else if (raiz == "ctg") {

								posfija = raiz + posfija;
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



								string resultadoRaiz = inAPost(dentroRaiz);

								posfija = resultadoRaiz + posfija;

							}
							else if (raiz == "sec") {

								posfija = raiz + posfija;
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
								string resultadoRaiz = inAPost(dentroRaiz);
								posfija = resultadoRaiz + posfija;
							}
							else if (raiz == "csc") {
								posfija = raiz + posfija;
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
								string resultadoRaiz = inAPost(dentroRaiz);
								posfija = resultadoRaiz + posfija;

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
							string resultadoParentesis = inAPost(dentroParentesis);


							posfija = resultadoParentesis + posfija;
						}
					}
				}
			}
		}
	}
	return posfija;	
}
