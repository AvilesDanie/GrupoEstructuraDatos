#include "Postfija.h"
#include "PilaChar.h"
#include "Operaciones.h"

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

	if (infija[0] == '-') {
		std::string numero;
		pila.push("-");
		std::string cero = "0";
		std::reverse(infija.begin(), infija.end());
		infija.pop_back();
		std::reverse(infija.begin(), infija.end());

		numero = infija;
		pila.push(numero);
		pila.push(cero);
		posfija = "0" + numero + "-";



		return posfija;

	}

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
			pila.push(sumaResta.getPrimero()->getValor());
			sumaResta.pop();
		}


		if (resultado.length() == 1) {
			pila.push(resultado);
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
					pila.push(mulDiv.getPrimero()->getValor());
					posfija = mulDiv.getPrimero()->getValor() + posfija;
					mulDiv.pop();
				}

				if (resultadoMulDiv.length() == 1) {
					pila.push(resultadoMulDiv);
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
							pila.push(PilaPot.getPrimero()->getValor());
							posfija = PilaPot.getPrimero()->getValor() + posfija;
							PilaPot.pop();
						}
						if (resultadoPot.length() == 1) {
							pila.push(resultadoPot);
							posfija = resultadoPot + posfija;

						}
						else if ((resultadoPot[0] == '0' || resultadoPot[0] == '1' || resultadoPot[0] == '2' || resultadoPot[0] == '3' || resultadoPot[0] == '4' || resultadoPot[0] == '5' || resultadoPot[0] == '6' || resultadoPot[0] == '7' || resultadoPot[0] == '8' || resultadoPot[0] == '9') && (resultadoPot[1] == '0' || resultadoPot[1] == '1' || resultadoPot[1] == '2' || resultadoPot[1] == '3' || resultadoPot[1] == '4' || resultadoPot[1] == '5' || resultadoPot[1] == '6' || resultadoPot[1] == '7' || resultadoPot[1] == '8' || resultadoPot[1] == '9' || resultadoPot[1] == '.')) {
							string numero, charNumero;
							char n = 'a';
							for (size_t i = 0; (resultadoPot[i] == '0' || resultadoPot[i] == '1' || resultadoPot[i] == '2' || resultadoPot[i] == '3' || resultadoPot[i] == '4' || resultadoPot[i] == '5' || resultadoPot[i] == '6' || resultadoPot[i] == '7' || resultadoPot[i] == '8' || resultadoPot[i] == '9' || resultadoPot[i] == '.') && i < resultadoPot.length(); i++) {
								n = resultadoPot[i];
								charNumero = n;
								numero = numero + charNumero;
							}

							pila.push(numero);
							posfija = numero + posfija;

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
								pila.push(raiz);
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
								pila.push(raiz);
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
							else if (raiz == "sen") {
								pila.push(raiz);
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
								pila.push(raiz);
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
								pila.push(raiz);
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
								pila.push(raiz);
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
								pila.push(raiz);
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
								pila.push(raiz);
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


Pila Postfija::getPila() {
	return pila;
}

void Postfija::calcularPila() {
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
			if ((e1 == "+" || e1 == "-" || e1 == "*" || e1 == "/" || e1 == "^")
				&& contieneSoloNumeros(e3) && contieneSoloNumeros(e2)) {
				if (e1 == "+"){
					pila.push(to_string(operaciones.suma(stod(e3), stod(e2))));
				}
				else if (e1 == "-"){
					pila.push(to_string(operaciones.resta(stod(e3), stod(e2))));
				}
				else if (e1 == "*"){
					pila.push(to_string(operaciones.multiplicacion(stod(e3), stod(e2))));
				}
				else if (e1 == "/"){
					if (operaciones.division(stod(e3), stod(e2)) == std::numeric_limits<double>::infinity()) {
						cout << "Math ERROR" << endl;
						iteraciones = 0;
					}
					pila.push(to_string(operaciones.division(stod(e3), stod(e2))));
				}
				else if (e1 == "^"){
					pila.push(to_string(operaciones.potencia(stod(e3), stod(e2))));
				}
			}
			else if ((e1 == "sqrt" || e1 == "cbrt" || e1 == "sen" || e1 == "cos" || e1 == "tg" || e1 == "ctg" ||
				e1 == "sec" || e1 == "csc") && contieneSoloNumeros(e2)) {
				if (e1 == "sqrt") {
					if (operaciones.raizCuadrada(stod(e2)) == std::numeric_limits<double>::infinity()) {
						cout << "Math ERROR" << endl;
						iteraciones = 0;
					}
					pila.push(to_string(operaciones.raizCuadrada(stod(e2))));
					aux.push(e3);
					i -= 1;
				}
				else if (e1 == "cbrt") {
					pila.push(to_string(operaciones.raizCubica(stod(e2))));
					aux.push(e3);
					i -= 1;
				}
				else if (e1 == "sen") {
					pila.push(to_string(operaciones.seno(stod(e2))));
					aux.push(e3);
					i -= 1;
				}
				else if (e1 == "cos") {
					pila.push(to_string(operaciones.coseno(stod(e2))));
					aux.push(e3);
					i -= 1;
				}
				else if (e1 == "tg") {
					pila.push(to_string(operaciones.tangente(stod(e2))));
					aux.push(e3);
					i -= 1;
				}
				else if (e1 == "ctg") {
					if (operaciones.cotangente(stod(e2)) == std::numeric_limits<double>::infinity()) {
						cout << "Math ERROR" << endl;
						iteraciones = 0;
					}
					pila.push(to_string(operaciones.cotangente(stod(e2))));
					aux.push(e3);
					i -= 1;
				}
				else if (e1 == "sec") {
					if (operaciones.secante(stod(e2)) == std::numeric_limits<double>::infinity()) {
						cout << "Math ERROR" << endl;
						iteraciones = 0;
					}
					pila.push(to_string(operaciones.secante(stod(e2))));
					aux.push(e3);
					i -= 1;
				}
				else if (e1 == "csc") {
					if (operaciones.cosecante(stod(e2)) == std::numeric_limits<double>::infinity()) {
						cout << "Math ERROR" << endl;
						iteraciones = 0;
					}
					pila.push(to_string(operaciones.cosecante(stod(e2))));
					aux.push(e3);
					i -= 1;
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
	} while (iteraciones != 0);
	cout << "\nResultado: " << pila.getPrimero()->getValor() << endl;
	pila.pop();
}

bool Postfija::contieneSoloNumeros(string str) {
	if (str.empty()) {
		return false;
	}
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+') {
		i = 1;
		if (str.length() == 1) {
			return false;
		}
	}

	bool puntoDecimalEncontrado = false;
	for (; i < str.length(); i++) {
		char c = str[i];
		if (isdigit(c)) {
			continue;
		}
		else if (c == '.') {
			if (puntoDecimalEncontrado) {
				return false;
			}
			puntoDecimalEncontrado = true;
		}
		else {
			return false;
		}
	}

	return true;
}