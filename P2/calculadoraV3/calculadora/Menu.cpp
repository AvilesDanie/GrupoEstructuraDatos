#include "Menu.h"

#include "ValidacionDatos.h"
#include "Postfija.h"
#include "Prefija.h"
#define Tecla_Arriba 72
#define Tecla_Abajo 80
#define Enter 13
using namespace std;

void Menu::menuPrincipal() {
	int opcMP = 0, opcMN = 0;
	bool repetir = true, repetir1 = true;
	bool ecValida = false;
	ValidacionDatos objValidar;
	char enteroC[10];
	Postfija objPosFija;
	Prefija  objPreFija;
	string ecuacion;
	const char* ecuacionC[100];
	//,
	int entero;
	const char* titulo = "BIENVENIDO AL APLICATIVO DE NOTACIONES";
	const char* opciones[] = { "Ingresar Ecuacion.","Elegir Notacion.","Cerrar aplicativo." };
	const char* titulo1 = "TIPOS DE NOTACIONES";
	const char* opciones1[] = { "Notacion prefija.","Notacion posfija." };
	//



	do {
		opcMP = menu(titulo, opciones, 3);
		switch (opcMP) {
		case 1: {
			system("cls");
			cout << "Ingrese la ecuacion-> " << endl;
			cin >> ecuacion;
			repetir1 = true;
			system("pause");


			break;
		}

		case 2: {
			if (repetir1) {
				system("cls");
				do {
					opcMN = menu(titulo1, opciones1, 2);
					switch (opcMN) {
					case 1: {
						system("cls");
						Pila pila;
						ecuacion = "1+2/3^4/(5/6/7)*8/9^(1+(2*(3/4))-5)^6/7+8/sqrt(9+(1*2)+3)/4+sqrt(5*6-(7/8/9)/1)";

						cout << "\nInfija: " << ecuacion << endl;
						string ecuacionPreFija = objPreFija.inAPre(ecuacion);




						cout << "\nEcuacion en notacion prefija" << endl;
						cout << ecuacionPreFija << endl;

						/*for (int i = 0; i < objPreFija.getPosi(); i++)
						{
							cout << ecuacionPreFija[i];
						}
						cout << "\nEl resultado es: " << objPreFija.resuelve(ecuacion) << endl;
						repetir1 = false;*/
						system("pause");

						break;
					}
					case 2: {
						system("cls");


						string* ecuacionPosfija = objPosFija.inAPost(ecuacion);
						cout << "\nEcuacion en notacion posfija" << endl;
						for (int i = 0; i < objPosFija.getPosi(); i++)
						{
							cout << ecuacionPosfija[i];
						}
						cout << "\nEl resultado es: " << objPosFija.resuelve(ecuacion) << endl;
						repetir1 = false;
						system("pause");

						break;
					}
					}
				} while (repetir1);



			}
			else {
				system("cls");
				cout << "\nPor favor, ingrese una ecuacion" << endl;
				system("pause");
			}
			break;
			//
		}

		case 3: {
			system("cls");
			cout << "\n\t  HASTA PRONTO";
			repetir = false;
			break;
		}
		}
	} while (repetir);
}

/**
 * Muestra un menú con un título y una lista de opciones, y devuelve el número de la opción
 * seleccionada por el usuario
 *
 * @param titulo El título del menú.
 * @param opciones es una matriz de cadenas que contiene las opciones que se mostrarán en el menú.
 * @param n número de opciones
 *
 * @return La opción seleccionada por el usuario.
 */
int Menu::menu(const char* titulo, const char* opciones[], int n) {
	int opcSeleccionada = 1;
	int tecla;
	bool repetir = true;
	do {
		system("cls");
		gotoxy(5, 3 + opcSeleccionada); cout << "-->";
		gotoxy(15, 2); cout << titulo;
		for (int i = 0; i < n; i++) {
			gotoxy(10, 4 + i); cout << i + 1 << "." << opciones[i];
		}

		do {
			tecla = _getch();
		} while (tecla != Tecla_Arriba && tecla != Tecla_Abajo && tecla != Enter);

		switch (tecla)
		{
		case Tecla_Arriba:
			opcSeleccionada--;
			if (opcSeleccionada < 1) {
				opcSeleccionada = n;
			}
			break;
		case Tecla_Abajo:
			opcSeleccionada++;
			if (opcSeleccionada > n) {
				opcSeleccionada = 1;
			}
			break;
		case Enter:
			repetir = false;
			break;
		}
	} while (repetir);


	return opcSeleccionada;

}

/**
 * Mueve el cursor a la posición especificada
 *
 * @param x La coordenada x del cursor.
 * @param y La coordenada y del cursor.
 */
void Menu::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

/**
 * Valida el número de DNI de una persona.
 *
 * @param cedulaC es una matriz de caracteres que contiene la entrada del usuario.
 *
 * @return el valor de la variable cédula.
 */
 /*int Menu::validarCedula(char *cedulaC){
	 ValidacionDatos objValidaciones;
	 int cedula=0;
	 int cifras=0;
	 string cedulaS;

	 do{
		 try{
		 cedula=objValidaciones.casteoEnteros(cedulaC,"\nIngrese una cedula correcta");
		 cedulaS=cedulaC;
		 cifras=cedulaS.size();
		 if(cifras!=10){
			 throw "Cedula incorrecta, ingrese una cedula de 10 digitos";
		 }
		 if(cifras==10){
			 //cout<<"\nCedula correcta"<<endl;
			 break;
		 }
		 }catch(const char* s){
			 cout<<"\nCatch:"<<s<<endl;
		 }
	 }while(cifras!=10);

	 return cedula;
 }*/

bool Menu::verificarCedula(const string& cedula) {
	int sumaAntigua{};

	for (int i{}; i < 9; i += 2) {
		int valorDetectar = (cedula[i] - '0') * 2;

		if (valorDetectar > 9)
			valorDetectar -= 9;

		sumaAntigua += valorDetectar;
	}

	int sumaNueva{};

	for (int i{ 1 }; i < 8; i += 2) {
		sumaNueva += (cedula[i] - '0');
	}

	int digitoVerificar = ((sumaAntigua + sumaNueva) % 10 != 0) ? 10 - (sumaAntigua + sumaNueva) % 10 : 0;

	return digitoVerificar == (cedula[9] - '0');

}

