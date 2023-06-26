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
	vector<string> contenido;
	PilaChar pila2;

	for (size_t i = 0; i < cadena.length(); i++) {
		if (cadena[i] == '(') {
			pila2.push('(');
		}
		else if (cadena[i] == ')') {
			if (!pila2.getPilaVacia()) {
				pila2.pop();
			}
			else {
				// Error: Paréntesis de cierre sin correspondiente paréntesis de apertura
			}
		}

		if (!pila2.getPilaVacia()) {
			std::string subcadena;
			while (!pila2.getPilaVacia() && i < cadena.length() - 1 && cadena[i + 1] != ')' && cadena[i + 1] != '(') {
				subcadena += cadena[i + 1];
				i++;
			}
			contenido.push_back(subcadena);
		}
	}

	return contenido;
}


string Prefija::inAPre(string infija)
{
	string prefija = "";
	reverse(infija.begin(), infija.end());
	string elem = "";
	posi = 0;
	reverse(infija.begin(), infija.end());

	vector<string> ExprecionesParentesis = obtenerContenidoEntreParentesis(infija);

	reverse(infija.begin(), infija.end());
	bool parentesis = false;

	for (size_t i = 0; i < infija.length(); i++) {
		char e = infija[i];
		string d;
		d = e;
		if ((d == "+" || d == "-") && !parentesis) {
			prefija = d+prefija;
		}
		else if (d == ")") {
			parentesis = true;
		}
		else if (d == "(") {
			parentesis = false;
		}
	}

	reverse(infija.begin(), infija.end());

	vector<string> subcadenas = separarCadenas(infija, '+');

	vector<string> resultados;
	for (string subcadena : subcadenas) {
		vector<string> subcadenas2 = separarCadenas(subcadena, '-');
		resultados.insert(resultados.end(), subcadenas2.begin(), subcadenas2.end());
	}

	for (string resultado : resultados) {
		reverse(resultado.begin(), resultado.end());
		if (resultado.length() == 1) {
			prefija = resultado + prefija;

		}
		else {
			parentesis = false;

			for (size_t i = 0; i < resultado.length(); i++) {
				char e = resultado[i];
				string d;
				d = e;

				if ((d == "/" || d == "*")&& !parentesis) {
					prefija = d + prefija;
				}

				else if (d == ")") {
					parentesis = true;
				}
				else if (d == "(") {
					parentesis = false;
				}
			}
			/*vector<string> subcadenasMultDiv = separarCadenas(infija, '*');

			vector<string> resultadosMultDiv;
			for (string subcadena : subcadenasMultDiv) {
				vector<string> subcadenas2 = separarCadenas(subcadena, '/');
				resultadosMultDiv.insert(resultados.end(), subcadenas2.begin(), subcadenas2.end());
			}
			
			for (string resultado : resultados) {
				reverse(resultado.begin(), resultado.end());
				if (resultado.length() == 1) {
					prefija = resultado + prefija;

				}
				else {

				}
			}*/
			parentesis = false;
			bool potDespuesParentesis = false;

			string p;
			reverse(resultado.begin(), resultado.end());

			for (size_t i = 0; i < resultado.length(); i++) {

				char e2 = resultado[i];
				string d2;
				d2 = e2;
				if ((d2 == "0" || d2 == "1" || d2 == "2" || d2 == "3" || d2 == "4" || d2 == "5" || d2 == "6" || d2 == "7" || d2 == "8" || d2 == "9")&&!parentesis ) {
					prefija = d2 + prefija;
					potDespuesParentesis = false;


				}
				else if (d2 == "^" && !potDespuesParentesis) {
					string primerCaracter = prefija.substr(0, 1);
					prefija.erase(0, 1);
					prefija = d2 + prefija;
					prefija = primerCaracter + prefija;
				}
				else if (d2 == "(") {

					parentesis = true;
				}
				else if (d2 == ")") {

					parentesis = false;
					for (string par : ExprecionesParentesis) {
						if (p == par) {
							
							string preParentesis = inAPre(par);

							reverse(preParentesis.begin(), preParentesis.end());

							char po = resultado[i + 1];
							string pot;
							pot = po;
							if ( pot == "^") {
								prefija = pot + prefija;
								potDespuesParentesis = true;
							}

							prefija = preParentesis + prefija;

						}
					}
				}
				else if ( parentesis) {

					p = p+d2;

				}
				
				else {

				}
			}
		}
		
	}
	
	reverse(prefija.begin(), prefija.end());
	Pila aux;
	for (size_t i = 0; i < prefija.length(); i++) {
		char e = prefija[i];
		string d;
		d = e;
		aux.push(d);
	}
	pila = aux;
	pila.mostrar();
	
	return prefija;






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
}

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



