#include "Prefija.h"
#include "PilaChar.h"

using namespace std;

int Prefija::getPosi()
{
	return posi;
}

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
	//std::cout << infija << std::endl;
	string prefija = "";
	string elem = "";
	posi = 0;

	vector<string> ExprecionesParentesis = obtenerContenidoEntreParentesis(infija);
	/*for (string a : ExprecionesParentesis) {
		std::cout << a << std::endl;
	}*/

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
		else if (resultado[0] == 's' || resultado[0] == 'c') {
			string raiz;
			char e = 'a';
			string d;
			int iteraciones = 0;
			for (size_t i = 0; e != '('; i++) {
				e = resultado[i];
				d = e;
				raiz = raiz + d;
				iteraciones = i;
			}
			raiz.pop_back();
			//std::cout << "raiiiiiiiz" << std::endl;
			if (raiz == "sqrt") {
				//std::cout << "raiiiiiiiz" << std::endl;

				std::reverse(raiz.begin(), raiz.end());
				prefija = raiz + prefija;
				string dentroRaiz;
				int cont = 0;
				//std::cout << iteraciones << std::endl;
				iteraciones += 1;
				for (iteraciones; e != ')'||cont==0; iteraciones++) {
					//std::cout << iteraciones << std::endl;

					e = resultado[iteraciones];
					string d;
					d = e;
					dentroRaiz = dentroRaiz + d;
					if (d == "(") {
						cont += 1;
					}
					else if (d == ")") {
						cont -= 1;
					}
					//std::cout << dentroRaiz << std::endl;

				}
				//std::cout << dentroRaiz << std::endl;


				dentroRaiz.pop_back();

				//std::cout << dentroRaiz << std::endl;


				string resultadoRaiz = inAPre(dentroRaiz);
				std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());

				prefija = resultadoRaiz + prefija;

			}
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
				else if (resultadoMulDiv[0] == 's' || resultadoMulDiv[0] == 'c') {
					string raiz;
					char e = 'a';
					string d;
					int iteraciones = 0;
					for (size_t i = 0; e != '('; i++) {
						e = resultadoMulDiv[i];
						d = e;
						raiz = raiz + d;
						iteraciones = i;
					}
					raiz.pop_back();
					//std::cout << "raiiiiiiiz" << std::endl;
					if (raiz == "sqrt") {
						//std::cout << "raiiiiiiiz" << std::endl;

						std::reverse(raiz.begin(), raiz.end());
						prefija = raiz + prefija;
						string dentroRaiz;
						int cont = 0;
						//std::cout << iteraciones << std::endl;
						iteraciones += 1;
						for (iteraciones; e != ')' || cont == 0; iteraciones++) {
							//std::cout << iteraciones << std::endl;

							e = resultadoMulDiv[iteraciones];
							string d;
							d = e;
							dentroRaiz = dentroRaiz + d;
							if (d == "(") {
								cont += 1;
							}
							else if (d == ")") {
								cont -= 1;
							}
							//std::cout << dentroRaiz << std::endl;

						}
						//std::cout << dentroRaiz << std::endl;


						dentroRaiz.pop_back();

						//std::cout << dentroRaiz << std::endl;


						string resultadoRaiz = inAPre(dentroRaiz);
						std::reverse(resultadoRaiz.begin(), resultadoRaiz.end());

						prefija = resultadoRaiz + prefija;

					}
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

					parentesis = false;

					string p;
					std::reverse(resultadoMulDiv.begin(), resultadoMulDiv.end());

					for (size_t i = 0; i < resultadoMulDiv.length(); i++) {
						//std::cout << p << std::endl;
						char e2 = resultadoMulDiv[i];
						string d2;
						d2 = e2;
						if ((d2 == "0" || d2 == "1" || d2 == "2" || d2 == "3" || d2 == "4" || d2 == "5" || d2 == "6" || d2 == "7" || d2 == "8" || d2 == "9") && !parentesis) {
							prefija = d2 + prefija;


						}
						else if (d2 == "(") {
							if (parentesis == true) {
								p = p + d2;
								contParentesis += 1;
							}
							parentesis = true;
						}
						else if (d2 == ")") {
							if (contParentesis == 0) {
								parentesis = false;
								for (string par : ExprecionesParentesis) {
									if (p == par) {

										string preParentesis = inAPre(par);

										std::reverse(preParentesis.begin(), preParentesis.end());


										prefija = preParentesis + prefija;

									}
								}
							}
							else {
								p = p + d2;
								contParentesis -= 1;
							}
						}
						else if (parentesis) {

							p = p + d2;

						}

						else {

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
	//pila.mostrar();


	return prefija;
}





//reverse(infija.begin(), infija.end());
//string elem = ""; string numeri = "";
//posi = 0;


//for (int i = 0; i < infija.size(); i++)
//{
//	char e = infija[i];
//	string d;
//	d.push_back(e);

//	if (d == ")")
//	{
//		pila.push(d);
//	}
//	else if (d == "+" || d == "-" || d == "*" || d == "/" || d == "^")
//	{
//		if (elem != "")
//		{
//			reverse(elem.begin(), elem.end());
//			opera[posi] = elem; posi++;
//			elem = "";
//		}
//		opera[posi] = " "; posi++;
//		while (!pila.getPilaVacia() && pila.getPrimero()->getValor() != ")" && priorizar(d) <= priorizar(pila.getPrimero()->getValor()))
//		{
//			opera[posi] = pila.getPrimero()->getValor(); posi++;
//			opera[posi] = " "; posi++;
//			pila.pop();
//		}
//		pila.push(d);
//	}
//	else if ((d >= "0" && d <= "9") || d == ".")
//	{
//		elem += d;
//	}
//	else if (e >= 97 && e <= 122)
//	{
//		numeri += d;

//		if (numeri == "trqs" || numeri == "nis" || numeri == "soc" || numeri == "nat" || numeri == "niscra" || numeri == "soccra" || numeri == "natcra" || numeri == "hnes" || numeri == "hsc" || numeri == "hgt")
//		{
//			reverse(numeri.begin(), numeri.end());

//			if (elem != "")
//			{
//				reverse(elem.begin(), elem.end());
//				opera[posi] = elem; posi++;
//				elem = "";
//			}
//			//opera[posi] = " "; posi++;
//			while (!pila.getPilaVacia() && pila.getPrimero()->getValor() != ")" && priorizar(numeri) <= priorizar(pila.getPrimero()->getValor()))
//			{
//				opera[posi] = pila.getPrimero()->getValor(); posi++;
//				opera[posi] = " "; posi++;
//				pila.pop();
//			}
//			pila.push(numeri);
//			numeri = "";
//		}

//		if (numeri == "ip" || numeri == "e")
//		{
//			//reverse(numeri.begin(),numeri.end());
//			if (elem != "")
//			{
//				reverse(elem.begin(), elem.end());
//				opera[posi] = elem; posi++;
//				elem = "";
//			}

//			opera[posi] = " "; posi++;
//			elem += numeri;

//			numeri = "";

//		}

//	}
//	else if (d == "(")
//	{
//		bool paren = false;

//		if (elem != "")
//		{
//			reverse(elem.begin(), elem.end());
//			opera[posi] = elem; posi++;
//			elem = "";
//		}

//		Nodo* piloso = pila.getPrimero();
//		string op = piloso->getValor();
//		while (piloso != NULL && paren != true)
//		{
//			opera[posi] = " "; posi++;

//			if (piloso->getValor() != ")")
//			{
//				opera[posi] = piloso->getValor(); posi++;
//				opera[posi] = " ";
//			}
//			else if (piloso->getValor() == ")" && paren == false)
//			{
//				paren = true;
//			}
//			else
//			{
//				paren = false;
//				break;
//			}
//			pila.pop();
//			piloso = pila.getPrimero();

//		}
//	}

//}
//if (elem != "")
//{
//	reverse(elem.begin(), elem.end());
//	opera[posi] = elem; posi++;
//	elem = "";
//}
//opera[posi] = " "; posi++;

//Nodo* piloso2 = pila.getPrimero();
//while (piloso2 != NULL)
//{
//	if (piloso2->getValor() != ")")
//	{
//		opera[posi] = piloso2->getValor(); posi++;
//		opera[posi] = " "; posi;
//	}
//	//piloso2 = piloso2->getSiguiente();
//	pila.pop();
//	piloso2 = pila.getPrimero();
//}

//int aux = posi;

//for (int x = 0; x <= aux; x++, aux--)
//{
//	string temp = opera[x];
//	opera[x] = opera[aux];
//	opera[aux] = temp;
//}


//return opera;


float Prefija::resuelve(string opi)
{
	float resul = 0;
	float a, b;
	for (int i = posi; i >= 0; i--)
	{
		if (opera[i] != " ")
		{
			if (opera[i] == "+")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rs = suma(a, b);
				pila.push(to_string(rs));
			}
			else if (opera[i] == "-")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rr = resta(a, b);
				pila.push(to_string(rr));
			}
			else if (opera[i] == "*")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rm = multi(a, b);
				pila.push(to_string(rm));
			}
			else if (opera[i] == "/")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rd = divi(a, b);
				pila.push(to_string(rd));
			}
			else if (opera[i] == "^")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rp = pot(a, b);
				pila.push(to_string(rp));
			}
			else if (opera[i] == "sqrt")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rra = raiz(a);
				pila.push(to_string(rra));
			}
			else if (opera[i] == "sin")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rsin = sen(a);
				pila.push(to_string(rsin));
			}
			else if (opera[i] == "cos")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rcos = cose(a);
				pila.push(to_string(rcos));
			}
			else if (opera[i] == "tan")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rtan = tange(a);
				pila.push(to_string(rtan));
			}
			else if (opera[i] == "arcsin")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rasin = arcsen(a);
				pila.push(to_string(rasin));
			}
			else if (opera[i] == "arccos")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float racos = arccose(a);
				pila.push(to_string(racos));
			}
			else if (opera[i] == "arctan")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float ratan = arctange(a);
				pila.push(to_string(ratan));
			}
			else if (opera[i] == "senh")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rsinh = senh(a);
				pila.push(to_string(rsinh));
			}
			else if (opera[i] == "csh")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rcosh = coseh(a);
				pila.push(to_string(rcosh));
			}
			else if (opera[i] == "tgh")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rtanh = tangeh(a);
				pila.push(to_string(rtanh));
			}
			else
			{
				/*if (opera[i] == "pi")
				{
					pila.push(to_string(M_PI));
				}
				else if (opera[i] == "e")
				{
					pila.push(to_string(M_E));
				}
				else
				{
					pila.push(opera[i]);
				}*/
			}
		}
	}

	resul = stof(pila.getPrimero()->getValor());

	return resul;
}

//métodos operadores

float Prefija::suma(float a, float b)
{
	return a + b;
}
float Prefija::resta(float a, float b)
{
	return a - b;
}
float Prefija::multi(float a, float b)
{
	return a * b;
}
float Prefija::divi(float a, float b)
{
	return a / b;
}
float Prefija::pot(float a, float b)
{
	return pow(b, a);
}
float Prefija::raiz(float a)
{
	return sqrt((double)a);
}
float Prefija::sen(float a)
{
	return sin((double)a);
}
float Prefija::cose(float a)
{
	return cos((double)a);
}
float Prefija::tange(float a)
{
	return tan((double)a);
}
float Prefija::arcsen(float a)
{
	return asin((double)a);
}
float Prefija::arccose(float a)
{
	return acos((double)a);
}
float Prefija::arctange(float a)
{
	return atan((double)a);
}
float Prefija::senh(float a)
{
	return sinh((double)a);
}
float Prefija::coseh(float a)
{
	return cosh((double)a);
}
float Prefija::tangeh(float a)
{
	return tanh((double)a);
}
//orden de operadores

int Prefija::priorizar(string c)
{
	if (c == "+" || c == "-")
	{
		return 1;
	}
	else if (c == "*" || c == "/")
	{
		return 2;
	}
	else if (c == "^" || c == "sqrt")
	{
		return 3;
	}
	else if (c == "sin" || c == "cos" || c == "tan" || c == "arcsin" || c == "arccos" || c == "arctan" || c == "senh" || c == "csh" || c == "tgh")
	{
		return 4;
	}
	else
	{
		return 0;
	}
}



